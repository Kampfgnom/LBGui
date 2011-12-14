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
    widgets/rowlistheader.h \
    widgets/rowlist.h \
    widgets/splitter.h \
    widgets/tabwidget.h \
    mainwindow/sidebar/sidebarparentcategorie.h \
    mainwindow/sidebar/sidebarchildcategorie.h

SOURCES += \
    databaseeditor/databaseeditor.cpp \
    mainwindow/mainwindow.cpp \
    mainwindow/sidebar/sidebar.cpp \
    mainwindow/sidebar/sidebarstatusbar.cpp \
    mainwindow/sidebar/sidebarstatusbardragbutton.cpp \
    mainwindow/sidebar/sidebartreeview.cpp \
    widgets/rowlistheader.cpp \
    widgets/rowlist.cpp \
    widgets/splitter.cpp \
    widgets/tabwidget.cpp \
    mainwindow/sidebar/sidebarparentcategorie.cpp \
    mainwindow/sidebar/sidebarchildcategorie.cpp

OTHER_FILES += \
    ressources/sidebar/macos_lionmail/stylesheet.css \
    ressources/tabwidget/itunes_white/stylesheet.css

RESOURCES += \
    ressources/sidebar/sidebar.qrc \
    ressources/tabwidget/tabwidget.qrc

macx {
    HEADERS += \
        mainwindow/sidebar/sidebaritemdelegatemac.h

    SOURCES += \
        mainwindow/sidebar/sidebaritemdelegatemac.cpp
}
