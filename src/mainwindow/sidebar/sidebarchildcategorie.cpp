#include "sidebarchildcategorie.h"

namespace LBGui {

SidebarChildCategorie::SidebarChildCategorie() :
    QStandardItem()
{
}

SidebarChildCategorie::SidebarChildCategorie(const QString &title) :
    QStandardItem()
{
#ifdef Q_WS_MAC
    QFont f;
    f.setFamily("Lucida Grande");
    f.setPixelSize(13);
    setFont(f);

    setSizeHint(QSize(0,24));
    setFlags((flags() | Qt::ItemIsSelectable) & ~ Qt::ItemIsEditable);
#endif

    setData(QVariant::fromValue<SidebarChildCategorie*>(this),SelfRole);
    setTitle(title);
}

void SidebarChildCategorie::setTitle(const QString &title)
{
    m_title = title;
    setData(title, TitleRole);
}

QString SidebarChildCategorie::title() const
{
    return m_title;
}

void SidebarChildCategorie::setWidget(QWidget *w)
{
    m_widget = w;
    setData(QVariant::fromValue<QWidget*>(w), WidgetRole);
}

QWidget *SidebarChildCategorie::widget() const
{
    return m_widget;
}

} // namespace LBGui
