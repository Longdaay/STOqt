#include "MainWindow.h"
#include "qpushbutton.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.DPButton, &QPushButton::clicked, this, &MainWindow::openDPWindow);
    connect(ui.ControlWindowButton, &QPushButton::clicked, this, &MainWindow::openControlWindow);
    connect(ui.CarLogButton, &QPushButton::clicked, this, &MainWindow::openControlWindow);

    openControlWindow();
    openDPWindow();
    this->move(QPoint(650, 500));

    timer = new QTimer;
    connect(timer, &QTimer::timeout,dpWindow, &DPWindow::updateProgressBar);
    connect(timer, &QTimer::timeout, this, &MainWindow::EventTick);
    timer->start(1000);
}

void MainWindow::openControlWindow()
{
    if (controlWindow == nullptr)
    {
        controlWindow = new ControlWindow;
        controlWindow->activateWindow();
        controlWindow->show();
        controlWindow->move(QPoint(1000, 500));
        connect(controlWindow, &ControlWindow::addKitCar, this, &MainWindow::addKitCar);
        connect(controlWindow, &ControlWindow::clearCWReference, this, &MainWindow::clearCWReference);
    }
}

void MainWindow::openDPWindow()
{
    if (dpWindow == nullptr)
    {
        dpWindow = new DPWindow;
        dpWindow->activateWindow();
        dpWindow->show();
        dpWindow->move(QPoint(650, 100));
        connect(dpWindow, &DPWindow::clearDPReference, this, &MainWindow::clearDPReference);
    }
}

void MainWindow::openCarLogWindow()
{

}

void MainWindow::addKitCar(Auto carInfo)
{
    if (dpWindow == nullptr)
    {
        openDPWindow();
        // TODO закинуть все текущие машины
    }
    dpWindow->addCar(carInfo);
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    quick_exit(0);
}

void MainWindow::clearCWReference()
{
    controlWindow = nullptr;
}

void MainWindow::clearDPReference()
{
    dpWindow = nullptr;
}

void MainWindow::EventTick()
{
    // TODO decrease time remanig cars
}

