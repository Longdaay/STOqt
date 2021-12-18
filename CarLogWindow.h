#pragma once

#include <QWidget>
#include "ui_CarLogWindow.h"

class CarLogWindow : public QWidget
{
	Q_OBJECT

public:
	CarLogWindow(QWidget *parent = Q_NULLPTR);
	~CarLogWindow();
	void closeEvent(QCloseEvent* event) override;
	void enterCarLog(const QVector<QString>& carLogInfo);

private:
	Ui::CarLogWindow ui;

signals:
	void clearCLReference();
};
