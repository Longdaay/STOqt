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

int DiagnosticPost::getCountKit(ESelectKit selectedKit)
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
