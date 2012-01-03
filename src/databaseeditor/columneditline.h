#ifndef COLUMNEDITLINE_H
#define COLUMNEDITLINE_H

#include <QWidget>

namespace LBDatabase {
class Column;
}

namespace LBGui {

class ColumnEditLinePrivate;
class ColumnEditLine : public QWidget
{
    Q_OBJECT

public:
    explicit ColumnEditLine(LBDatabase::Column *column, QWidget *parent = 0);
    ~ColumnEditLine();

    QString name() const;
    int type() const;

public Q_SLOTS:
    void saveChanges();
    void markForDeletion(bool);

private:
    ColumnEditLinePrivate * const d_ptr;
    Q_DECLARE_PRIVATE(ColumnEditLine)
};

} // namespace LBGui

#endif // COLUMNEDITLINE_H
