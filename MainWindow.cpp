#include "MainWindow.h"
#include "qpushbutton.h"
#include <time.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.DPButton, &QPushButton::clicked, this, &MainWindow::openDPWindow);
    connect(ui.ControlWindowButton, &QPushButton::clicked, this, &MainWindow::openControlWindow);
    connect(ui.CarLogButton, &QPushButton::clicked, this, &MainWindow::openCarLogWindow);

    openControlWindow();
    openDPWindow();
    this->move(QPoint(650, 500));

    timer = new QTimer;
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
        connect(this, &MainWindow::transferKitCount, dpWindow, &DPWindow::updateKitsCount);
    }
}

void MainWindow::openCarLogWindow()
{
    if (carLogWindow == nullptr)
    {
        carLogWindow = new CarLogWindow;
        carLogWindow->activateWindow();
        carLogWindow->show();
        carLogWindow->move(QPoint(200, 100));
        connect(carLogWindow, &CarLogWindow::clearCLReference, this, &MainWindow::clearCLReference);
        carLogWindow->enterCarLog(CarLog);
    }
}

void MainWindow::addKitCar(Auto carInfo)
{
    if (dpWindow == nullptr)
    {
        openDPWindow();
        for (int i = 0; i < CarQueue.size(); i++)
        {
            dpWindow->addCar(CarQueue[i]);
        }
    }
    dpWindow->addCar(carInfo);
    CarQueue.push_back(carInfo);
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

void MainWindow::clearCLReference()
{
    carLogWindow = nullptr;
}

void MainWindow::addCarToLog(Auto Car)
{
    time_t rawtime;
    struct tm* ptm;
    time(&rawtime);
    ptm = gmtime(&rawtime);
    CarLog.push_back(QString("Car " + QString::number(Car.getAutoId())
        + " finished diagnostics at " + QString::number(ptm->tm_hour) + ":" + QString::number(ptm->tm_min) + ", " + QString::number(ptm->tm_mday) + "." + QString::number(ptm->tm_mon + 1)));
}

void MainWindow::EventTick()
{
    diagnosticPost.performCarDiagnostic(CarQueue);

    int i = 0;
    while (i < CarQueue.size())
    {
        if (CarQueue[i].getUsedKits() == ESelectKit::none)
        {
            addCarToLog(CarQueue[i]);
            CarQueue.erase(CarQueue.begin() + i);
            i = 0;
            continue;
        }
        i++;
    }

    diagnosticPost.assignFreeKits(CarQueue);

    if (dpWindow != nullptr)
    {
        dpWindow->clearGridLayout();
        for (int i = 0; i < CarQueue.size(); i++)
        {
            dpWindow->addCar(CarQueue[i]);
        }
    }

    emit transferKitCount(diagnosticPost.getCountKit(ESelectKit::first), diagnosticPost.getCountKit(ESelectKit::second));

}

