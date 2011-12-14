#ifndef LBGUI_SIDEBARCHILDCATEGORIE_H
#define LBGUI_SIDEBARCHILDCATEGORIE_H

#include <QStandardItem>

namespace LBGui {

class SidebarChildCategorie : public QStandardItem
{
public:
    enum Role {
        SelfRole = Qt::UserRole + 1,
        TitleRole,
        WidgetRole
    };

    explicit SidebarChildCategorie();
    explicit SidebarChildCategorie(const QString &title);

    void setTitle(const QString &title);
    QString title() const;

    void setWidget(QWidget *w);
    QWidget *widget() const;

protected:
    QString m_title;
    QWidget *m_widget;
};

} // namespace LBGui

Q_DECLARE_METATYPE(LBGui::SidebarChildCategorie*)

#endif // LBGUI_SIDEBARCHILDCATEGORIE_H
