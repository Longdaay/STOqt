#pragma once

#include <QWidget>
#include "ui_ControlWindow.h"

class ControlWindow : public QWidget
{
	Q_OBJECT

public:
	ControlWindow(QWidget *parent = Q_NULLPTR);
	~ControlWindow();

private:
	Ui::ControlWindow ui;
};
