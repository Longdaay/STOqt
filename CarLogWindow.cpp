#include "CarLogWindow.h"

CarLogWindow::CarLogWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

CarLogWindow::~CarLogWindow()
{
}

void CarLogWindow::closeEvent(QCloseEvent* event)
{
	emit clearCLReference();
}

void CarLogWindow::enterCarLog(const QVector<QString>& carLogInfo)
{
	for (auto& elem : carLogInfo)
	{
		ui.listWidget->addItem(elem);
	}
}
