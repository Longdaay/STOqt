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
	LabelArray.push_back(autoIdLabel);

	QLabel* haveFirstKitLabel;
	QLabel* haveSecondKitLabel;
	QProgressBar* firstKitProgressBar;
	QProgressBar* secondtKitProgressBar;

	ui.DPGridLayout->addWidget(autoIdLabel, gridRow, 0);
	ui.DPGridLayout->setAlignment(autoIdLabel, Qt::AlignHCenter);
	autoIdLabel->setFont(QFont("MS Shell Dlg 2", 14, 5));
	bool bIsHaveCurrentKit = carInfo.getCurrentKit() != ESelectKit::none;

	switch (carInfo.getUsedKits())
	{
	case ESelectKit::first:
		firstKitProgressBar = new QProgressBar();
		ProgressBarArray.push_back(firstKitProgressBar);
		firstKitProgressBar->setMinimum(0);
		firstKitProgressBar->setValue(bIsHaveCurrentKit ? carInfo.getKitTimer() - carInfo.getTimeKitRemaning() : 0);
		firstKitProgressBar->setMaximum(carInfo.getKitTimer());

		haveSecondKitLabel = new QLabel("-");
		LabelArray.push_back(haveSecondKitLabel);

		ui.DPGridLayout->addWidget(firstKitProgressBar, gridRow, 1);
		ui.DPGridLayout->setAlignment(firstKitProgressBar, Qt::AlignHCenter);
		ui.DPGridLayout->addWidget(haveSecondKitLabel, gridRow, 2);
		ui.DPGridLayout->setAlignment(haveSecondKitLabel, Qt::AlignHCenter);
		haveSecondKitLabel->setFont(QFont("MS Shell Dlg 2", 14, 5));
		break;

	case ESelectKit::second:
		haveFirstKitLabel = new QLabel("-");
		LabelArray.push_back(haveFirstKitLabel);

		secondtKitProgressBar = new QProgressBar();
		ProgressBarArray.push_back(secondtKitProgressBar);
		secondtKitProgressBar->setMinimum(0);
		secondtKitProgressBar->setValue(bIsHaveCurrentKit ? carInfo.getKitTimer() - carInfo.getTimeKitRemaning() : 0);
		secondtKitProgressBar->setMaximum(carInfo.getKitTimer());


		ui.DPGridLayout->addWidget(haveFirstKitLabel, gridRow, 1);
		ui.DPGridLayout->setAlignment(haveFirstKitLabel, Qt::AlignHCenter);
		haveFirstKitLabel->setFont(QFont("MS Shell Dlg 2", 14, 5));
		ui.DPGridLayout->addWidget(secondtKitProgressBar, gridRow, 2);
		ui.DPGridLayout->setAlignment(secondtKitProgressBar, Qt::AlignHCenter);
		break;

	case ESelectKit::both:
		
		firstKitProgressBar = new QProgressBar();
		ProgressBarArray.push_back(firstKitProgressBar);
		firstKitProgressBar->setMinimum(0);
		firstKitProgressBar->setMaximum(carInfo.getKitTimer());

		secondtKitProgressBar = new QProgressBar();
		ProgressBarArray.push_back(secondtKitProgressBar);
		secondtKitProgressBar->setMinimum(0);
		secondtKitProgressBar->setMaximum(carInfo.getKitTimer());

		if (carInfo.getCurrentKit() == ESelectKit::first)
		{
			firstKitProgressBar->setValue(bIsHaveCurrentKit ? carInfo.getKitTimer() - carInfo.getTimeKitRemaning() : 0);
		}
		else if (carInfo.getCurrentKit() == ESelectKit::second)
		{
			secondtKitProgressBar->setValue(bIsHaveCurrentKit ? carInfo.getKitTimer() - carInfo.getTimeKitRemaning() : 0);
		}

		ui.DPGridLayout->addWidget(firstKitProgressBar, gridRow, 1);
		ui.DPGridLayout->setAlignment(firstKitProgressBar, Qt::AlignHCenter);
		ui.DPGridLayout->addWidget(secondtKitProgressBar, gridRow, 2);
		ui.DPGridLayout->setAlignment(secondtKitProgressBar, Qt::AlignHCenter);
		break;
	default:
		break;
	}
	
	gridRow++;
}

void DPWindow::updateKitsCount(int firstKitCount, int secondKitCount)
{
	ui.FirstKitCountLabel->setText(QString::number(firstKitCount));
	ui.SecondKitCountLabel->setText(QString::number(secondKitCount));
}

void DPWindow::clearGridLayout()
{
	for each (auto var in ProgressBarArray)
	{
		delete var;
	}
	for each (auto var in LabelArray)
	{
		delete var;
	}
	ProgressBarArray.clear();
	LabelArray.clear();
}
