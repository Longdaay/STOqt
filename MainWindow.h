#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "DPWindow.h"
#include "ControlWindow.h"
#include "Types.h"
#include "Auto.h"
#include "DiagnosticPost.h"
#include "CarLogWindow.h"
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
    void clearCLReference();
    void EventTick();
    void addCarToLog(Auto Car);

private:
    Ui::MainWindowClass ui;
    DPWindow* dpWindow = nullptr;
    ControlWindow* controlWindow = nullptr;
    CarLogWindow* carLogWindow = nullptr;

    QTimer* timer;
    QVector<Auto> CarQueue;
    DiagnosticPost diagnosticPost;
    QVector<QString> CarLog;

signals:
    int transferKitCount(int firstKitCount, int secondKitCount);
    

};
