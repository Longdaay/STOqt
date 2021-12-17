#pragma once

#include <QWidget>
#include "ui_ControlWindow.h"
#include "Types.h"
#include "Auto.h"
#include <ctime>

class ControlWindow : public QWidget
{
	Q_OBJECT

public:
	ControlWindow(QWidget *parent = Q_NULLPTR);
	~ControlWindow();
	void addFirstKitCar();
	void addSecondKitCar();
	void addBothKitCar();
	void closeEvent(QCloseEvent* event) override;

private:
	Ui::ControlWindow ui;

signals:
	void addKitCar(Auto);
	void clearCWReference();
};
