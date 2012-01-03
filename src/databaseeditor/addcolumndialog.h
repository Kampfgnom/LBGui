#ifndef LBGUI_ATTRIBUTEEDITDIALOG_H
#define LBGUI_ATTRIBUTEEDITDIALOG_H

#include <QDialog>

#include <LBDatabase/LBDatabase.h>

namespace LBDatabase {
class Column;
}

namespace LBGui {

namespace Ui {
class AddColumnDialog;
}

class AddColumnDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AddColumnDialog(QWidget *parent = 0);
    ~AddColumnDialog();

    QString name() const;
    QVariant defaultValue() const;
    LBDatabase::Column::Type type() const;

private:
    Ui::AddColumnDialog *ui;
};

} // namespace LBGui

#endif // LBGUI_ATTRIBUTEEDITDIALOG_H
