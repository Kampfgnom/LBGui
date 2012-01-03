#include "databaseeditor.h"

#include "databaseeditorcontroller.h"
#include "databaseeditoractions.h"
#include "databaseeditorsidebar.h"
#include "databasewidget.h"
#include "tablewidget.h"

#include <mainwindow/menubar.h>
#include <mainwindow/sidebar/sidebarchildcategorie.h>
#include <mainwindow/toolbar.h>
#include <shared/action.h>
#include <shared/actionsmanager.h>
#include <shared/recentfilesmanager.h>
#include <widgets/backgroundwidget.h>

#include <LBDatabase/LBDatabase.h>

#include <QVBoxLayout>
#include <QPushButton>
#include <QToolBar>
#include <QStackedWidget>
#include <QFile>
#include <QSettings>
#include <QFileInfo>
#include <QCloseEvent>

namespace LBGui {

DatabaseEditor::DatabaseEditor(QWidget *parent) :
    MainWindow(parent)
{
    setSaveSettings(true);
    setSettingsName(QLatin1String("DatabaseEditor"));

    // SideBar
    createSideBar();

    m_controller = new DatabaseEditorController(this);
    m_actions = new DatabaseEditorActions(m_controller);
    m_recentFiles = new RecentFilesManager(this);
    m_toolBar = new ToolBar(this);
    m_databaseWidget = new DatabaseWidget();
    m_tableWidget = new TableWidget();

    BackgroundWidget *w = new BackgroundWidget(m_centralViewStackedWidget);
    w->setStyle(BackgroundWidget::Gray);
    m_centralViewStackedWidget->addWidget(w);
    m_centralViewStackedWidget->addWidget(m_databaseWidget);
    m_centralViewStackedWidget->addWidget(m_tableWidget);
    m_centralViewStackedWidget->setCurrentWidget(w);

    // Recent files
    m_recentFiles->setSettingsName(m_settingsName+QLatin1String("/RecentFiles"));
    m_recentFiles->populateFromSettings();
    connect(m_recentFiles, SIGNAL(fileTriggered(QString)), m_controller, SLOT(openDatabase(QString)));

    // MenuBar
    createMenuBar();

    // ToolBar
    createToolBar();

    setTitle(tr("Database Editor"));
    restoreSettings();
    m_menuBar->addWindow(this);
}

DatabaseEditorSidebar *DatabaseEditor::dbeSidebar() const
{
    return static_cast<DatabaseEditorSidebar*>(m_leftSideBar);
}

RecentFilesManager *DatabaseEditor::recentFilesManager() const
{
    return m_recentFiles;
}

DatabaseEditorController *DatabaseEditor::controller() const
{
    return m_controller;
}

DatabaseEditorActions *DatabaseEditor::actions() const
{
    return m_actions;
}

void DatabaseEditor::showDatabase(LBDatabase::Database *database)
{
    if(!database) {
        m_centralViewStackedWidget->setCurrentIndex(0);
        return;
    }
    m_databaseWidget->setDatabase(database);
    m_centralViewStackedWidget->setCurrentWidget(m_databaseWidget);
}

void DatabaseEditor::showTable(LBDatabase::Table *table)
{
    m_tableWidget->setTable(table);
    m_centralViewStackedWidget->setCurrentWidget(m_tableWidget);
}

void DatabaseEditor::closeEvent(QCloseEvent *event)
{
    if(m_controller->close()) {
        event->accept();
    }
    else {
        event->ignore();
    }
}

void DatabaseEditor::reflectCurrentDatabaseDirtyState()
{
    setWindowModified(m_controller->currentDatabase() != 0 && m_controller->currentDatabase()->isDirty());
}

void DatabaseEditor::createSideBar()
{
    LBGui::DatabaseEditorSidebar* sidebar = new LBGui::DatabaseEditorSidebar(this);
    sidebar->setStyle(LBGui::Sidebar::MacOSLionMailStyle);
    sidebar->setSelectedCategorie(0,0);
    sidebar->expandAll();
    setLeftSideBar(sidebar);
}

void DatabaseEditor::createMenuBar()
{
    m_menuBar->addAction(tr("File"),m_actions->openDatabaseAction());
    m_menuBar->addMenu(tr("File"), m_recentFiles->recentFilesMenu());
    m_menuBar->addSeparator(tr("File"));
    m_menuBar->addAction(tr("File"),m_actions->closeDatabaseAction());
    m_menuBar->addAction(tr("File"),m_actions->saveDatabaseAction());

    m_menuBar->addAction(tr("Table"), m_actions->createTableAction());
    m_menuBar->addAction(tr("Table"), m_actions->editTableAction());
    m_menuBar->addAction(tr("Table"), m_actions->insertRowAction());

    m_menuBar->addMenu(m_menuBar->windowMenu());
    m_menuBar->addMenu(m_menuBar->helpMenu());
}

void DatabaseEditor::createToolBar()
{
    m_toolBar->addAction(m_actions->openDatabaseAction());
    m_toolBar->addAction(m_actions->createTableAction());
    m_toolBar->addAction(m_actions->editTableAction());
    m_toolBar->addAction(m_actions->insertRowAction());
    addToolBar(m_toolBar);
    setUnifiedTitleAndToolBarOnMac(true);
}

} //namespace Gui
