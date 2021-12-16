#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);
    void openControlWindow();
    void openDPWindow();
    void openCarLogWindow();

private:
    Ui::MainWindowClass ui;

private slots:

};
