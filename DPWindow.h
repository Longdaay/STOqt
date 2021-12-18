#pragma once

#include <QWidget>
#include "ui_DPWindow.h"
#include "Auto.h"
#include "qprogressbar.h"
#include "qvector.h"

class DPWindow : public QWidget
{
	Q_OBJECT

public:
	DPWindow(QWidget *parent = Q_NULLPTR);
	~DPWindow();
	void closeEvent(QCloseEvent* event) override;
	void addCar(Auto);
	void updateKitsCount(int firstKitCount, int secondKitCount);
	void updateProgressBar();
	void clearGridLayout();
	int gridRow = 0;

private:
	Ui::DPWindow ui;
	QVector<QProgressBar*> ProgressBarArray;
	QVector<QLabel*> LabelArray;
	QProgressBar* progressBar_1 = nullptr;
	QProgressBar* progressBar_2 = nullptr;
	
signals:
	void clearDPReference();
};
