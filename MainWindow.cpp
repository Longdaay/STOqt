#include "MainWindow.h"
#include "qpushbutton.h"
#include "DPWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.DPButton, &QPushButton::clicked, this, &MainWindow::openDPWindow);
    connect(ui.ControlWindowButton, &QPushButton::clicked, this, &MainWindow::openControlWindow);
    connect(ui.CarLogButton, &QPushButton::clicked, this, &MainWindow::openControlWindow);
}

void MainWindow::openControlWindow()
{

}

void MainWindow::openDPWindow()
{
    DPWindow* dPWindow = new DPWindow;
    this->setEnabled(false);
    dPWindow->activateWindow();
    dPWindow->show();
}

void MainWindow::openCarLogWindow()
{
}
