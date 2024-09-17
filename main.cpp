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
	cout << "\x1B[2J\x1B[H"; //������������: system("clear")
#endif
}

void beginRace(Vehicle** regVeh, int& amountReg, int& distance, bool& endRace, bool& exitTheGame)
{
	//����������
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
		std::cout << i + 1 << ") " << regVeh[i]->getName() << ". �����: " << regVeh[i]->getRaceTime(distance) << std::endl;
	}

	int choice;
	bool fault = false;

	do
	{
		std::cout << "\n1. �������� ��� ���� �����\n";
		std::cout << "2. �����\n";
		std::cout << "�������� ��������: ";
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
		std::cout << raceType << ", ����������: " << distance << std::endl;

		if (amountReg > 0)
		{
			std::cout << "������������������ ������������ ��������: ";
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
		std::cout << "0) ��������� �����������\n";
		std::cout << "�������� ��������� ��� 0 ��� ��������� �������� �����������: ";
		std::cin >> choice;
		clear_screen();
		bool permission = true;

		if (choice > 0 && choice <= amountVehicle) //����� �������� ���� ������� ��� ����������� 
		{

			for (int i = 0; i < amountReg; i++)
			{
				if (vehicles[choice - 1]->getName() == regVeh[i]->getName())
				{
					std::cout << regVeh[i]->getName() << " ��� ���������������!\n";
					permission = false;
					break;
				}
			}

			if (vehicles[choice - 1]->getVehicleType() != choiceRace && choiceRace!=3) //�������� ���� ��
			{
				std::cout << "������� ���������������� ������������ ��� ������������� ��������!\n";
				permission = false;
			}


			if (permission)
			{
				regVeh[amountReg] = vehicles[choice - 1];
				std::cout << regVeh[amountReg]->getName() << " ������� ���������������!\n";
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


	std::cout << "����� ���������� � �������� ���������!\n";

	bool exitTheGame = false;
	bool fault = false;

	//������ �������� �����
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
			std::cout << "1. ����� ��� ��������� ����������\n";
			std::cout << "2. ����� ��� ���������� ����������\n";
			std::cout << "3. ����� ��� ��������� � ���������� ����������\n";
			std::cout << "�������� ��� �����: ";
			std::cin >> choiceRace;

			fault = false;
			switch (choiceRace)
			{
			case 1:
				raceType = "����� ��� ��������� ����������";
				break;
			case 2:
				raceType = "����� ��� ���������� ����������";
				break;
			case 3:
				raceType = "����� ��� ��������� � ���������� ����������";
				break;
			default:
				fault = true;
			}

			clear_screen();

		} while (fault);

		int distance;
		do
		{
			std::cout << "������� ����� ��������� (������ ���� ������������): ";
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
				std::cout << "������ ���� ����������������� ���� �� 2 ������������ ��������\n";
				std::cout << "1. ���������������� ���������\n";
			}
			else
			{
				std::cout << "1. ���������������� ���������\n2. ������ �����\n";
			}
			std::cout << "�������� ��������: ";
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


//������ ground.cpp flying.cpp flying.h