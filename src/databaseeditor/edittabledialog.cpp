#include "edittabledialog.h"

#include "columneditline.h"

#include <LBDatabase/LBDatabase.h>

#include <QComboBox>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QFormLayout>

namespace LBGui {

class EditTableDialogPrivate {
    EditTableDialogPrivate() {}

    friend class EditTableDialog;
};

EditTableDialog::EditTableDialog(LBDatabase::Table *table, QWidget *parent) :
    QDialog(parent),
    d_ptr(new EditTableDialogPrivate)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QWidget *columns = new QWidget(this);
    QFormLayout *formLayout = new QFormLayout(columns);
    formLayout->setSpacing(5);
    columns->setLayout(formLayout);
    layout->addWidget(columns);
    QDialogButtonBox *buttonBox = new QDialogButtonBox(this);
    foreach(LBDatabase::Column *column, table->columns()) {
        ColumnEditLine *columnEditLine = new ColumnEditLine(column, this);
        formLayout->addWidget(columnEditLine);
        connect(buttonBox, SIGNAL(accepted()), columnEditLine, SLOT(saveChanges()));
    }
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    buttonBox->setStandardButtons(QDialogButtonBox::Save | QDialogButtonBox::Cancel);
    layout->addWidget(buttonBox);
    setLayout(layout);
    setWindowModality(Qt::WindowModal);
}

EditTableDialog::~EditTableDialog()
{
    Q_D(EditTableDialog);
    delete d;
}

} // namespace LBGui
