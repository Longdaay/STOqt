#pragma once
#include "Types.h"
class DiagnosticPost
{
public:
	void addKit(ESelectKit selectedKit);
	void removeKit(ESelectKit selectedKit);

	int getCountKit(ESelectKit seletedKit);
private:
	int countFirstKit = 2;
	int firstKitTime = 10;
	int countSecondKit = 3;
	int secondKitTime = 5;
};

