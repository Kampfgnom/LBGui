#ifndef ROWLIST_H
#define ROWLIST_H

#include <QTreeView>

namespace LBGui {

class TreeView : public QTreeView
{
    Q_OBJECT
    Q_ENUMS(DoubleClickAction)
    Q_ENUMS(Style)
    Q_PROPERTY(int doubleClickActions READ doubleClickActions WRITE setDoubleClickActions)

public:
    enum DoubleClickAction {
        NoAction = 0,
        EditAttributeAction = 1L << 1
    };
    enum Style {
        ItunesWhite
    };

    Style style() const;

    void setStyle(Style style);

    explicit TreeView(QWidget *parent = 0);

    int doubleClickActions() const;

    void setDoubleClickActions(int actions);

signals:
    void selectionChanged();

protected slots:
    void on_doubleClicked(QModelIndex);

private:
    int m_doubleClickActions;
    Style m_style;
};

} //namespace LBGui

#endif // ROWLIST_H
