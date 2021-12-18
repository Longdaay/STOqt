#pragma once
#include "Types.h"
#include "Auto.h"
#include <qvector.h>

class DiagnosticPost
{
public:
	void addKit(ESelectKit selectedKit);
	void removeKit(ESelectKit selectedKit);
	void performCarDiagnostic(QVector<Auto>& CarQueue);
	void releaseFullDiagnosticCars(QVector<Auto>& CarQueue);
	void assignFreeKits(QVector<Auto>& CarQueue);


	int getKitTime(ESelectKit selectedKit) const;
	int getCountKit(ESelectKit seletedKit) const;
private:
	int countFirstKit = 2;
	int firstKitTime = 10;
	int countSecondKit = 3;
	int secondKitTime = 5;
};

