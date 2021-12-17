#include "Auto.h"

Auto::Auto()
{
	autoId = 0;
	usedKits = ESelectKit::none;
	currentKit = ESelectKit::none;
}

Auto::Auto(int id, ESelectKit current, ESelectKit used)
{
	autoId = id;
	usedKits = used;
	currentKit = current;
}

void Auto::performDiagnostic()
{
	ESelectKit removedKit = currentKit;
	currentKit = ESelectKit::none;
	removeUsedKit(removedKit);
}

void Auto::removeUsedKit(ESelectKit removedKit)
{
	if (usedKits == ESelectKit::both)
	{
		if (removedKit == ESelectKit::first)
		{
			usedKits = ESelectKit::second;
		}
		else if (removedKit == ESelectKit::second)
		{
			usedKits = ESelectKit::first;
		}
	}
	else
	{
		usedKits = ESelectKit::none;
	}
}

bool Auto::decreaseTimeKit()
{
	timeKitRemaning--;
	return timeKitRemaning != 0;
}

void Auto::setCurrentKit(ESelectKit selectedKit, int timerTime)
{
	currentKit = selectedKit;
	timeKitRemaning = timerTime;
	kitTimer = timerTime;
}

int Auto::getAutoId() const
{
	return autoId;
}

ESelectKit Auto::getUsedKits() const
{
	return usedKits;
}

ESelectKit Auto::getCurrentKit() const
{
	return currentKit;
}

int Auto::getTimeKitRemaning() const
{
	return timeKitRemaning;
}

int Auto::getKitTimer() const
{
	return kitTimer;
}
