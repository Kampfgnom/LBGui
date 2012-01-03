TARGET = lbgui
TEMPLATE = lib
CONFIG += staticlib
QT += sql

INCLUDEPATH += $$PWD/include
DESTDIR = $$PWD/../lib

LIBS += -L$$PWD/../../LBDatabase/lib/ -llbdatabase
INCLUDEPATH += $$PWD/../../LBDatabase/include
PRE_TARGETDEPS += $$PWD/../../LBDatabase/lib/liblbdatabase.a

HEADERS += \
    LBGui.h \
    databaseeditor/databaseeditor.h \
    mainwindow/mainwindow.h \
    mainwindow/sidebar/sidebar.h \
    mainwindow/sidebar/sidebarstatusbar.h \
    mainwindow/sidebar/sidebarstatusbardragbutton.h \
    mainwindow/sidebar/sidebartreeview.h \
    widgets/splitter.h \
    widgets/tabwidget.h \
    mainwindow/sidebar/sidebarparentcategorie.h \
    mainwindow/sidebar/sidebarchildcategorie.h \
    mainwindow/menubar.h \
    shared/actionsmanager.h \
    shared/action.h \
    databaseeditor/databaseeditoractions.h \
    databaseeditor/databaseeditorcontroller.h \
    shared/global.h \
    databaseeditor/databaseeditorsidebar.h \
    shared/recentfilesmanager.h \
    mainwindow/toolbar.h \
    databaseeditor/databasewidget.h \
    widgets/groupbox.h \
    databaseeditor/tablewidget.h \
    widgets/treeview.h \
    widgets/treeviewheader.h \
    widgets/listeditbuttonswidget.h \
    databaseeditor/attributestable.h \
    databaseeditor/addattributedialog.h \
    widgets/backgroundwidget.h \
    shared/autosavefile.h \
    databaseeditor/addcolumndialog.h \
    databaseeditor/createtabledialog.h \
    databaseeditor/columneditline.h \
    databaseeditor/edittabledialog.h

SOURCES += \
    databaseeditor/databaseeditor.cpp \
    mainwindow/mainwindow.cpp \
    mainwindow/sidebar/sidebar.cpp \
    mainwindow/sidebar/sidebarstatusbar.cpp \
    mainwindow/sidebar/sidebarstatusbardragbutton.cpp \
    mainwindow/sidebar/sidebartreeview.cpp \
    widgets/splitter.cpp \
    widgets/tabwidget.cpp \
    mainwindow/sidebar/sidebarparentcategorie.cpp \
    mainwindow/sidebar/sidebarchildcategorie.cpp \
    mainwindow/menubar.cpp \
    shared/actionsmanager.cpp \
    shared/action.cpp \
    databaseeditor/databaseeditoractions.cpp \
    databaseeditor/databaseeditorcontroller.cpp \
    shared/global.cpp \
    databaseeditor/databaseeditorsidebar.cpp \
    shared/recentfilesmanager.cpp \
    mainwindow/toolbar.cpp \
    databaseeditor/databasewidget.cpp \
    widgets/groupbox.cpp \
    databaseeditor/tablewidget.cpp \
    widgets/treeview.cpp \
    widgets/treeviewheader.cpp \
    widgets/listeditbuttonswidget.cpp \
    widgets/backgroundwidget.cpp \
    shared/autosavefile.cpp \
    databaseeditor/createtabledialog.cpp \
    databaseeditor/columneditline.cpp \
    databaseeditor/edittabledialog.cpp

OTHER_FILES += \
    ressources/sidebar/macos_lionmail/stylesheet.css \
    ressources/tabwidget/itunes_white/stylesheet.css \
    ressources/groupbox/itunes_white/stylesheet.css \
    ressources/pushbutton/itunes_white/stylesheet.css \
    ressources/listwidget/itunes_white/stylesheet.css \
    ressources/treeview/itunes_white/stylesheet.css \
    ressources/backgroundwidget/gray/stylesheet.css

RESOURCES += \
    ressources/sidebar/sidebar.qrc \
    ressources/tabwidget/tabwidget.qrc \
    ressources/databaseeditor/databaseeditor.qrc \
    ressources/groupbox/groupbox.qrc \
    ressources/pushbutton/pushbutton.qrc \
    ressources/listwidget/listwidget.qrc \
    ressources/treeview/treeview.qrc \
    ressources/backgroundwidget/backgroundwidget.qrc

macx {
    HEADERS += \
        mainwindow/sidebar/sidebaritemdelegatemac.h

    SOURCES += \
        mainwindow/sidebar/sidebaritemdelegatemac.cpp
}

FORMS += \
    databaseeditor/addattributedialog.ui \
    databaseeditor/addcolumndialog.ui \
    databaseeditor/createtabledialog.ui
