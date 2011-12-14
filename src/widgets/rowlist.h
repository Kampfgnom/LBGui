#ifndef ROWLIST_H
#define ROWLIST_H

#include <QTreeView>

class QSortFilterProxyModel;


namespace LBDatabase {
    class Row;
    class AttributeBase;
    class TableModelBase;
}

namespace LBGui {

//! Stellt eine Liste von Elementen (z.B. Spielen) dar.
/*!
  Diese Listen werden von TableModel bereitgstellt (siehe z.B. GamesModel).<br>
  Die Klasse ItemsList verwaltet anschließend das Auswählen und Klicks auf Listenelemente.
  */
class RowList : public QTreeView
{
    Q_OBJECT
    Q_ENUMS(DoubleClickAction)
    Q_PROPERTY(LBDatabase::TableModelBase* model READ model WRITE setModel)
    Q_PROPERTY(int doubleClickActions READ doubleClickActions WRITE setDoubleClickActions)

public:
    enum DoubleClickAction {
        NoAction = 0,
        EmitRowAction = 1L << 1,
        EditAttributeAction = 1L << 2
    };

    /*!
      Erstellt eine ItemsList, die im MainWindow \p parent angezeigt wird. Der Konstruktor initialisiert diese Liste mit einem PlayersModel und gutem Aussehen für Mac OS X.
      */
    explicit RowList(LBDatabase::TableModelBase *model = 0, QWidget *parent = 0);

    /*!
      Speichert die aktuelle Größe der Liste.
      */
    ~RowList();

    /*!
      Setzt das Model der Liste auf \p model.
      */
    void setModel(LBDatabase::TableModelBase *model);

    LBDatabase::TableModelBase *model() const;

    LBDatabase::AttributeBase* attributeAt(const QPoint& point);

    int doubleClickActions() const;

    void setDoubleClickActions(int actions);

signals:
    /*!
      Dieses Signal wird gesendet, wenn ein Element doppelt geklickt wurde.
      */
    void rowDoubleClicked(LBDatabase::Row *row);
    /*!
      Dieses Signal wird gesendet, wenn mehrere Element der Liste angewählt wurden.
      */
    void rowsSelected(QList<LBDatabase::Row*> rows);

    /*!
      Dieses Signal wird gesendet, wenn sich die Auswahl der Liste allgemein geändert hat.
      */
    void selectionChanged();

protected slots:
    /*!
      Dieser Slot wird aktiviert, wenn sich die Auswahl allgemein geändert hat.<br>
      Dann werden die angewählten Elemente aus dem Model ausgelesen und korrekt gecastet (z.B. auf Game) von den jeweiligen Signals gesendet.
      */
    void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

    /*!
      Dieser Slot wird aktiviert, wenn ein Element der Liste doppelt geklickt wird.
      Dann wird das angewählte Element aus dem Model ausgelesen und korrekt gecastet (z.B. auf Game) von den jeweiligen Signals gesendet.
      */
    void on_doubleClicked(QModelIndex);

    /*!
      Dieser Slot wird aktiviert, wenn sich die Liste der sichtbaren Spalten im Model geändert hat.
      */
    void setupVisibleColumns();

    void on_customContextMenuRequested(const QPoint &pos);

    void on_editAttributeActionTriggered();

private:
    QSortFilterProxyModel* m_proxyModel; //!< In diesem Proxymodel wird das eigentlich angezeigte Model gewrappt, und ist somit sortierbar.
    LBDatabase::TableModelBase* m_model; //!< Das Model, das wir eigentlich anzeigen.
    int m_doubleClickActions;

};

} //namespace LBGui

#endif // ROWLIST_H
