#include "columneditline.h"

#include <LBDatabase/LBDatabase.h>

#include <QHBoxLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>

namespace LBGui {

class ColumnEditLinePrivate {
    ColumnEditLinePrivate() :
        column(0)
    {}

    friend class ColumnEditLine;
    LBDatabase::Column *column;
    QLineEdit *lineEditName;
    QComboBox *comboBoxType;
    QCheckBox *checkBoxDelete;
};

ColumnEditLine::ColumnEditLine(LBDatabase::Column *column, QWidget *parent) :
    QWidget(parent),
    d_ptr(new ColumnEditLinePrivate)
{
    Q_D(ColumnEditLine);
    d->column = column;

    d->lineEditName = new QLineEdit(column->name(), this);
    d->comboBoxType = new QComboBox(this);
    d->comboBoxType->addItems(LBDatabase::Column::typeNames());
    d->comboBoxType->setCurrentIndex(column->type());
    d->comboBoxType->setEnabled(false);
    d->checkBoxDelete = new QCheckBox(tr("Delete"), this);
    connect(d->checkBoxDelete, SIGNAL(toggled(bool)), this, SLOT(markForDeletion(bool)));

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(d->lineEditName);
    layout->addWidget(d->comboBoxType);
    layout->addWidget(d->checkBoxDelete);
    layout->setSpacing(5);
    layout->setContentsMargins(0,0,0,0);
    setLayout(layout);
}

ColumnEditLine::~ColumnEditLine()
{
    Q_D(ColumnEditLine);
    delete d;
}

QString ColumnEditLine::name() const
{
    Q_D(const ColumnEditLine);
    return d->lineEditName->text();
}

int ColumnEditLine::type() const
{
    Q_D(const ColumnEditLine);
    return d->comboBoxType->currentIndex();
}

void ColumnEditLine::saveChanges()
{
    Q_D(ColumnEditLine);
    if(d->checkBoxDelete->isChecked()) {
        setVisible(false);
        d->column->table()->removeColumn(d->column->name());
        deleteLater();
    }
    else {
        d->column->table()->changeColumnName(d->column->name(), name());
    }
}

void ColumnEditLine::markForDeletion(bool marked)
{
    Q_D(ColumnEditLine);
    d->lineEditName->setEnabled(!marked);
    //d->comboBoxType->setEnabled(!marked);
}

} // namespace LBGui
