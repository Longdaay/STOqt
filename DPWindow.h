#pragma once

#include <QWidget>
#include "ui_DPWindow.h"

class DPWindow : public QWidget
{
	Q_OBJECT

public:
	DPWindow(QWidget *parent = Q_NULLPTR);
	~DPWindow();

private:
	Ui::DPWindow ui;
};
