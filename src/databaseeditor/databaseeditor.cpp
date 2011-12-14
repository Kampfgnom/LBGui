#include "databaseeditor.h"

#include <widgets/rowlist.h>
#include <widgets/tabwidget.h>
#include <mainwindow/sidebar/sidebar.h>
#include <mainwindow/sidebar/sidebarchildcategorie.h>

#include <LBDatabase/LBDatabase.h>

#include <QVBoxLayout>
#include <QPushButton>
#include <QToolBar>
#include <QStackedWidget>

namespace LBGui {

DatabaseEditor::DatabaseEditor(QWidget *parent) :
    MainWindow(parent)
{
    LBGui::Sidebar* sidebar = new LBGui::Sidebar(this);
    sidebar->setStyle(LBGui::Sidebar::MacOSLionMailStyle);
    sidebar->addParentCategorie("Tables");

    foreach(LBDatabase::TableBase *table, LBDatabase::Database::instance()->tables()) {
        SidebarChildCategorie *categorie = sidebar->addChildCategorie(0, table->name());
        RowList *rowList = new RowList(table->model(), m_centralViewStackedWidget);
        rowList->setDoubleClickActions(RowList::EditAttributeAction);
        categorie->setWidget(rowList);
    }
    sidebar->expandAll();

    connect(sidebar, SIGNAL(categorieChanged(::LBGui::SidebarChildCategorie*)),
            this,    SLOT(showCategorieWidget(::LBGui::SidebarChildCategorie*)));

    sidebar->setSelectedCategorie(0,0);
    setLeftSideBar(sidebar);

    setSaveSettings(true);
    setSettingsName(QLatin1String("DatabaseEditor"));
    restoreSettings();
}

} //namespace Gui
