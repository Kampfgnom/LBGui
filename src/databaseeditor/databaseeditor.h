#ifndef DATABASEWINDOW_H
#define DATABASEWINDOW_H

#include "mainwindow/mainwindow.h"

namespace LBGui {

class TabWidget;

class DatabaseEditor : public MainWindow
{
    Q_OBJECT

public:
    explicit DatabaseEditor(QWidget *parent = 0);
};

} //namespace LBGui

#endif // DATABASEWINDOW_H
