#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <ctime>

#include "Auto.h"
#include "DiagnosticPost.h"

DiagnosticPost diagnosticPost;

std::string getKitText(ESelectKit kit)
{
	switch (kit)
	{
	case ESelectKit::first:
		return "first";
		break;
	case ESelectKit::second:
		return "second";
		break;
	case ESelectKit::both:
		return "both";
		break;
	case ESelectKit::none:
		return "none";
		break;
	default:
		break;
	}
	return "";
}

void printCarInfo(const Auto& Auto)
{
	std::cout << Auto.getAutoId() << '\t';
	std::cout << getKitText(Auto.getCurrentKit()) << "\t\t";
	std::cout << getKitText(Auto.getUsedKits());
}

void printPostQueue(const std::vector<Auto>& CarsQueue)
{
	std::cout << "Auto\t" << "Current kit\t" << "Used Kit \t" << "1sKit = " << diagnosticPost.getCountKit(ESelectKit::first) << " 2ndKit = " << diagnosticPost.getCountKit(ESelectKit::second) << std::endl;
	for (int i = 0; i < CarsQueue.size(); i++)
	{
		printCarInfo(CarsQueue[i]);
		std::cout << std::endl;
	}
}

void performingCarDiagnostic(std::vector<Auto>& CarsQueue)
{
	for (int i = 0; i < CarsQueue.size(); i++)
	{
		if (CarsQueue[i].getCurrentKit() != ESelectKit::none)
		{
			ESelectKit tempKit = CarsQueue[i].getCurrentKit();
			CarsQueue[i].performDiagnostic();
			diagnosticPost.addKit(tempKit);
		}
	}
}

void assignFreeKits(std::vector<Auto>& CarsQueue)
{
	if (diagnosticPost.getCountKit(ESelectKit::first) == 0 && diagnosticPost.getCountKit(ESelectKit::second) == 0)
		return;

	for (int i = 0; i < CarsQueue.size(); i++)
	{
		if (CarsQueue[i].getCurrentKit() == ESelectKit::none)
		{
			switch (CarsQueue[i].getUsedKits())
			{
			case ESelectKit::first:
				if (diagnosticPost.getCountKit(ESelectKit::first) != 0)
				{
					CarsQueue[i].setCurrentKit(ESelectKit::first);
					diagnosticPost.removeKit(ESelectKit::first);
				}
				break;
			case ESelectKit::second:
				if (diagnosticPost.getCountKit(ESelectKit::second) != 0)
				{
					CarsQueue[i].setCurrentKit(ESelectKit::second);
					diagnosticPost.removeKit(ESelectKit::second);
				}
				break;
			case ESelectKit::both:
				if (diagnosticPost.getCountKit(ESelectKit::first) != 0)
				{
					CarsQueue[i].setCurrentKit(ESelectKit::first);
					diagnosticPost.removeKit(ESelectKit::first);
				}
				else if (diagnosticPost.getCountKit(ESelectKit::second) != 0)
				{
					CarsQueue[i].setCurrentKit(ESelectKit::second);
					diagnosticPost.removeKit(ESelectKit::second);
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

void addRandomCar(std::vector<Auto>& diagnosticCars)
{
	int resultAutoId = rand() % 300;
	int randomKit = rand() % 3;
	ESelectKit resultUsedKit = ESelectKit::none;
	switch (randomKit)
	{
	case 0:
		resultUsedKit = ESelectKit::first;
		break;
	case 1:
		resultUsedKit = ESelectKit::second;
		break;
	case 2:
		resultUsedKit = ESelectKit::both;
		break;
	default:
		break;
	}
	
	diagnosticCars.push_back({ resultAutoId, ESelectKit::none, resultUsedKit });
}

void releaseFullDiagnosticCars(std::vector<Auto>& diagnosticCars)
{
	int i = 0;
	while (i < diagnosticCars.size())
	{
		if (diagnosticCars[i].getUsedKits() == ESelectKit::none)
		{
			diagnosticCars.erase(diagnosticCars.begin() + i);
			i = 0;
			continue;
		}
		i++;
	}
}

int main()
{
	srand(time(NULL));
	std::vector<Auto> diagnosticCars;

	for (int i = 0; i < 3; i++)
	{
		addRandomCar(diagnosticCars);
	}

	while (true)
	{
		system("cls");
		printPostQueue(diagnosticCars);

		_getch();
		//Sleep(2000);

		performingCarDiagnostic(diagnosticCars);
		releaseFullDiagnosticCars(diagnosticCars);
		assignFreeKits(diagnosticCars);

		for (int i = 0; i < 2; i++) 
		{
			addRandomCar(diagnosticCars);
		}
		
	}
	return 0;
}