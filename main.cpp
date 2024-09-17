#include "Windows.h"
#include <iostream>
#include "vehicle.h"
#include "camel.h"
#include "fastCamel.h"
#include "centaur.h"
#include "boots.h"
#include "carpet.h"
#include "eagle.h"
#include "broom.h"

void clear_screen()
{
#ifdef _WIN32
	system("cls");
#else
	cout << "\x1B[2J\x1B[H"; //Альтернатива: system("clear")
#endif
}

void beginRace(Vehicle** regVeh, int& amountReg, int& distance, bool& endRace, bool& exitTheGame)
{
	//сортировка
	for (int i = 0; i < amountReg; i++)
	{
		for (int j = 0; j < amountReg; j++)
		{
			if (regVeh[i]->getRaceTime(distance) < regVeh[j]->getRaceTime(distance))
			{
				std::swap(regVeh[i], regVeh[j]);
			}
		}
	}

	for (int i = 0; i < amountReg; i++)
	{
		std::cout << i + 1 << ") " << regVeh[i]->getName() << ". Время: " << regVeh[i]->getRaceTime(distance) << std::endl;
	}

	int choice;
	bool fault = false;

	do
	{
		std::cout << "\n1. Провести еще одну гонку\n";
		std::cout << "2. Выйти\n";
		std::cout << "Выберете действие: ";
		std::cin >> choice;
		fault = false;
		switch (choice)
		{
		case 2:
			exitTheGame = true;
		case 1:
			endRace = true;
			break;
		default:
			fault = true;
		}
		clear_screen();
	} while (fault);
}

void registration(std::string& raceType,int& distance,const int& amountVehicle, Vehicle** vehicles, Vehicle** regVeh, int& amountReg, int& choiceRace)
{
	int choice = -1;
	while (choice!=0)
	{
		std::cout << raceType << ", Расстояние: " << distance << std::endl;

		if (amountReg > 0)
		{
			std::cout << "Зарегестрированные транспортные средства: ";
			for (int i = 0; i < amountReg; i++)
			{
				std::cout << regVeh[i]->getName();
				if (i != amountReg-1)
				{
					std::cout << " ,";
				}
			}
			std::cout << std::endl;
		}

		for (int i = 0; i < amountVehicle; i++)
		{
			std::cout << i+1 << ") " << vehicles[i]->getName() << std::endl;
		}
		std::cout << "0) Закончить регистрацию\n";
		std::cout << "Выберете транспорт или 0 для окончания процесса регистрации: ";
		std::cin >> choice;
		clear_screen();
		bool permission = true;

		if (choice > 0 && choice <= amountVehicle) //здесь проверка всех условий для регистрации 
		{

			for (int i = 0; i < amountReg; i++)
			{
				if (vehicles[choice - 1]->getName() == regVeh[i]->getName())
				{
					std::cout << regVeh[i]->getName() << " уже зарегестрирован!\n";
					permission = false;
					break;
				}
			}

			if (vehicles[choice - 1]->getVehicleType() != choiceRace && choiceRace!=3) //Проверка типа ТС
			{
				std::cout << "Попытка зарегестрировать неправильный тип транспортного средства!\n";
				permission = false;
			}


			if (permission)
			{
				regVeh[amountReg] = vehicles[choice - 1];
				std::cout << regVeh[amountReg]->getName() << " успешно зарегестрирован!\n";
				++amountReg;
			}
		}

	}
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	const int amountVehicle = 7;
	Camel camel;
	FastCamel fastCamel;
	Centaur centaur;
	Boots boots;
	Carpet carpet;
	Eagle eagle;
	Broom broom;


	std::cout << "Добро пожаловать в гоночный симулятор!\n";

	bool exitTheGame = false;
	bool fault = false;

	//начало игрового цикла
	do
	{
		Vehicle** vehicles = new Vehicle* [amountVehicle];

		vehicles[0] = &camel;
		vehicles[1] = &fastCamel;
		vehicles[2] = &centaur;
		vehicles[3] = &boots;
		vehicles[4] = &carpet;
		vehicles[5] = &eagle;
		vehicles[6] = &broom;
		
		int choiceRace;
		std::string raceType;
		do
		{
			std::cout << "1. Гонка для наземного транспорта\n";
			std::cout << "2. Гонка для воздушного транспорта\n";
			std::cout << "3. Гонка для наземного и воздушного транспорта\n";
			std::cout << "Выберите тип гонки: ";
			std::cin >> choiceRace;

			fault = false;
			switch (choiceRace)
			{
			case 1:
				raceType = "Гонка для наземного транспорта";
				break;
			case 2:
				raceType = "Гонка для воздушного транспорта";
				break;
			case 3:
				raceType = "Гонка для наземного и воздушного транспорта";
				break;
			default:
				fault = true;
			}

			clear_screen();

		} while (fault);

		int distance;
		do
		{
			std::cout << "Укажите длину дистанции (должна быть положительна): ";
			std::cin >> distance;
			clear_screen();
		} while (distance <= 0);


		Vehicle** regVeh = new Vehicle * [amountVehicle];
		int amountReg = 0;

		bool endRace = false;
		int choice;

		do
		{
			if (amountReg < 2)
			{
				std::cout << "Должно быть зарегестрированно хотя бы 2 транспортных средства\n";
				std::cout << "1. Зарегестрировать транспорт\n";
			}
			else
			{
				std::cout << "1. Зарегестрировать транспорт\n2. Начать гонку\n";
			}
			std::cout << "Выберете действие: ";
			std::cin >> choice;

			clear_screen();

			switch (choice)
			{
			case 1:
				registration(raceType, distance, amountVehicle, vehicles, regVeh, amountReg, choiceRace);
				break;
			case 2:
				if (amountReg >= 2)
				{
					beginRace(regVeh, amountReg, distance, endRace, exitTheGame);
					break;
				}
			}

		} while (!endRace);
		delete[] regVeh;
		delete[] vehicles;

	} while (!exitTheGame);

	return 0;
}


//удаляю ground.cpp flying.cpp flying.h