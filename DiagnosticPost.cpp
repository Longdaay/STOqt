#include "DiagnosticPost.h"

void DiagnosticPost::addKit(ESelectKit selectedKit)
{
	if (selectedKit == ESelectKit::first)
	{
		countFirstKit++;
	}
	else if (selectedKit == ESelectKit::second)
	{
		countSecondKit++;
	}

}

void DiagnosticPost::removeKit(ESelectKit selectedKit)
{
	if (selectedKit == ESelectKit::first)
	{
		countFirstKit--;
	}
	else if (selectedKit == ESelectKit::second)
	{
		countSecondKit--;
	}
}

void DiagnosticPost::performCarDiagnostic(QVector<Auto>& CarQueue)
{
	for (int i = 0; i < CarQueue.size(); i++)
	{
		if (CarQueue[i].getCurrentKit() != ESelectKit::none)
		{
			bool bDiagnosticIsComplite = CarQueue[i].decreaseTimeKit();
			if (bDiagnosticIsComplite)
			{
				ESelectKit tempKit = CarQueue[i].getCurrentKit();
				CarQueue[i].performDiagnostic();
				addKit(tempKit);
			}
		}
	}
}

void DiagnosticPost::releaseFullDiagnosticCars(QVector<Auto>& CarQueue)
{

}

void DiagnosticPost::assignFreeKits(QVector<Auto>& CarQueue)
{
	if (countFirstKit == 0 && countSecondKit == 0)
		return;

	for (int i = 0; i < CarQueue.size(); i++)
	{
		if (CarQueue[i].getCurrentKit() == ESelectKit::none)
		{
			switch (CarQueue[i].getUsedKits())
			{
			case ESelectKit::first:
				if (countFirstKit != 0)
				{
					CarQueue[i].setCurrentKit(ESelectKit::first, firstKitTime);
					removeKit(ESelectKit::first);
				}
				break;
			case ESelectKit::second:
				if (countSecondKit != 0)
				{
					CarQueue[i].setCurrentKit(ESelectKit::second, secondKitTime);
					removeKit(ESelectKit::second);
				}
				break;
			case ESelectKit::both:
				if (countFirstKit != 0)
				{
					CarQueue[i].setCurrentKit(ESelectKit::first, firstKitTime);
					removeKit(ESelectKit::first);
				}
				else if (countSecondKit != 0)
				{
					CarQueue[i].setCurrentKit(ESelectKit::second, secondKitTime);
					removeKit(ESelectKit::second);
				}
				break;
			case ESelectKit::none:
				break;
			default:
				break;
			}
		}
	}
}

int DiagnosticPost::getKitTime(ESelectKit selectedKit) const
{
	if (selectedKit == ESelectKit::first)
	{
		return firstKitTime;
	}
	else if (selectedKit == ESelectKit::second)
	{
		return secondKitTime;
	}

	return 0;
}

int DiagnosticPost::getCountKit(ESelectKit selectedKit) const
{
	if (selectedKit == ESelectKit::first)
	{
		return countFirstKit;
	}
	else if (selectedKit == ESelectKit::second)
	{
		return countSecondKit;
	}

	return 0;
}
