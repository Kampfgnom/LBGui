#ifndef LBGUI_EDITTABLEDIALOG_H
#define LBGUI_EDITTABLEDIALOG_H

#include <QDialog>

namespace LBDatabase {
class Table;
class Column;
}

namespace LBGui {

class EditTableDialogPrivate;
class EditTableDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit EditTableDialog(LBDatabase::Table *table, QWidget *parent = 0);
    ~EditTableDialog();

private:
    EditTableDialogPrivate * const d_ptr;
    Q_DECLARE_PRIVATE(EditTableDialog)
};

} // namespace LBGui

#endif // LBGUI_EDITTABLEDIALOG_H
