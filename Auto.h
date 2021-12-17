#pragma once
#include "Types.h"

class Auto
{
public:
	Auto();
	Auto(int, ESelectKit, ESelectKit);

	void performDiagnostic();
	void removeUsedKit(ESelectKit removedKit);
	bool decreaseTimeKit();
	
	void setCurrentKit(ESelectKit selectedKit, int timerTime);

	int getAutoId() const;
	ESelectKit getUsedKits() const;
	ESelectKit getCurrentKit() const;
	int getTimeKitRemaning() const;
	int getKitTimer() const;

private:
	int autoId;
	ESelectKit usedKits;
	ESelectKit currentKit;
	int timeKitRemaning = 10;
	int kitTimer = 10;
};

