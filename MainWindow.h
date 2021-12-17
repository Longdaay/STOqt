#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "DPWindow.h"
#include "ControlWindow.h"
#include "Types.h"
#include "Auto.h"
#include "qtimer.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);
    void openControlWindow();
    void openDPWindow();
    void openCarLogWindow();
    void addKitCar(Auto);
    void closeEvent(QCloseEvent* event) override;
    void clearCWReference();
    void clearDPReference();
    void EventTick();

private:
    Ui::MainWindowClass ui;
    DPWindow* dpWindow = nullptr;
    ControlWindow* controlWindow = nullptr;

    QTimer* timer;

    

};
