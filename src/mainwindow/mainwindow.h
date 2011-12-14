#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QStackedWidget;

namespace LBGui {

class Splitter;
class Sidebar;
class SidebarChildCategorie;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(QString  settingsName READ settingsName WRITE setSettingsName)
    Q_PROPERTY(bool     saveSettings READ saveSettings WRITE setSaveSettings)
    Q_PROPERTY(QString  confirmCloseMessage READ confirmCloseMessage WRITE setConfirmCloseMessage)
    Q_PROPERTY(bool     confirmClose READ confirmClose WRITE setConfirmClose)
    Q_PROPERTY(QWidget* centralWidget READ centralWidget WRITE setCentralWidget)

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void closeEvent(QCloseEvent *event);

    QString    settingsName () const;
    void    setSettingsName (const QString &settingsName);
    bool       saveSettings () const;
    void    setSaveSettings (bool saveSettings);

    QString    confirmCloseMessage () const;
    void    setConfirmCloseMessage (const QString &confirmCloseMessage);
    bool       confirmClose () const;
    void    setConfirmClose (bool confirmClose);

    QWidget   *centralWidget() const;
    void    setCentralWidget(QWidget *widget);

    void setLeftSideBar(QWidget* sidebar);
    void setLeftSideBar(Sidebar* sidebar);

public slots:
    void showCategorieWidget(::LBGui::SidebarChildCategorie*);

protected:
    void restoreSettings();

    QString m_settingsName;
    bool    m_saveSettings;

    QString m_confirmCloseMessage;
    bool    m_confirmClose;

    bool m_leftSideBarVisible;
    bool m_rightSideBarVisible;

    Splitter*       m_verticalSplitter;
    QWidget*        m_leftSideBar;
    QStackedWidget* m_centralViewStackedWidget;
    QWidget*        m_centralWidget;
    QWidget*        m_rightSideBar;

//    ToolBar* m_toolbar;
//    Sidebar* m_sidebar;
//    MenuBar* m_menubar;
//    ActionsManager* m_actionsManager;
//    QStackedWidget* m_stackedWidget;
//    QVBoxLayout* m_vBoxLayout;
//    Statusbar* m_statusbar;

    void _setupMainspace();

    void _saveSettings();
};

} // namespace LBGui

#endif // MAINWINDOW_H
