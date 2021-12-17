#include "DPWindow.h"
#include "qpushbutton.h"
#include "qlabel.h"

DPWindow::DPWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

DPWindow::~DPWindow()
{
}

void DPWindow::closeEvent(QCloseEvent* event)
{
	emit clearDPReference();
}

void DPWindow::addCar(Auto carInfo)
{
	QLabel* autoIdLabel = new QLabel(QString::number(carInfo.getAutoId()));
	QLabel* haveFirstKitLabel;
	QLabel* haveSecondKitLabel;
	QProgressBar* firstKitProgressBar;
	QProgressBar* secondtKitProgressBar;

	ui.DPGridLayout->addWidget(autoIdLabel, gridRow, 0);

	
	switch (carInfo.getUsedKits())
	{
	case ESelectKit::first:
		firstKitProgressBar = new QProgressBar();
		ProgressBarArray.push_back(firstKitProgressBar);
		firstKitProgressBar->setMinimum(0);
		firstKitProgressBar->setValue(carInfo.getKitTimer() - carInfo.getTimeKitRemaning());
		firstKitProgressBar->setMaximum(carInfo.getKitTimer());
		haveSecondKitLabel = new QLabel("-");
		ui.DPGridLayout->addWidget(firstKitProgressBar, gridRow, 1);
		ui.DPGridLayout->addWidget(haveSecondKitLabel, gridRow, 2);
		break;
	case ESelectKit::second:
		haveFirstKitLabel = new QLabel("-");
		secondtKitProgressBar = new QProgressBar();
		ProgressBarArray.push_back(secondtKitProgressBar);
		secondtKitProgressBar->setMinimum(0);
		secondtKitProgressBar->setValue(carInfo.getKitTimer() - carInfo.getTimeKitRemaning());
		secondtKitProgressBar->setMaximum(carInfo.getKitTimer());
		ui.DPGridLayout->addWidget(haveFirstKitLabel, gridRow, 1);
		ui.DPGridLayout->addWidget(secondtKitProgressBar, gridRow, 2);
		break;
	case ESelectKit::both:
		firstKitProgressBar = new QProgressBar();
		ProgressBarArray.push_back(firstKitProgressBar);
		firstKitProgressBar->setMinimum(0);
		firstKitProgressBar->setValue(carInfo.getKitTimer() - carInfo.getTimeKitRemaning());
		firstKitProgressBar->setMaximum(carInfo.getKitTimer());

		secondtKitProgressBar = new QProgressBar();
		ProgressBarArray.push_back(secondtKitProgressBar);
		secondtKitProgressBar->setMinimum(0);
		secondtKitProgressBar->setValue(carInfo.getKitTimer() - carInfo.getTimeKitRemaning());
		secondtKitProgressBar->setMaximum(carInfo.getKitTimer());

		ui.DPGridLayout->addWidget(firstKitProgressBar, gridRow, 1);
		ui.DPGridLayout->addWidget(secondtKitProgressBar, gridRow, 2);
		break;
	default:
		break;
	}
	
	gridRow++;

}

void DPWindow::updateProgressBar()
{
	for(int i = 0; i < ProgressBarArray.count(); i++)
	{
		ProgressBarArray[i]->setValue(ProgressBarArray[i]->value() + 1);
	}
}
