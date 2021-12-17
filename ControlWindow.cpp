#include "ControlWindow.h"
#include <QRandomGenerator>

ControlWindow::ControlWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.FirstKitButton, &QPushButton::clicked, this, &ControlWindow::addFirstKitCar);
	connect(ui.SecondKitButton, &QPushButton::clicked, this, &ControlWindow::addSecondKitCar);
	connect(ui.BothKitButton, &QPushButton::clicked, this, &ControlWindow::addBothKitCar);
	
	srand(time(NULL));
}

ControlWindow::~ControlWindow()
{
}

void ControlWindow::addFirstKitCar()
{
	int autoId = rand() % 300;
	emit addKitCar({autoId, ESelectKit::none, ESelectKit::first});
}

void ControlWindow::addSecondKitCar()
{
	int autoId = rand() % 300;
	emit addKitCar({ autoId, ESelectKit::none, ESelectKit::second });
}

void ControlWindow::addBothKitCar()
{
	int autoId = rand() % 300;
	emit addKitCar({ autoId, ESelectKit::none, ESelectKit::both });
}

void ControlWindow::closeEvent(QCloseEvent* event)
{
	emit clearCWReference();
}
