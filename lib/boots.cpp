#include "boots.h"

Boots::Boots()
{
	name = "�������-���������";
	speed = 6;
	timeToRelax = 60;
	type = ground;
}

double Boots::getRaceTime(int distance)
{
	double routeTime = distance / speed;

	int amountStop = static_cast<int>(routeTime / timeToRelax);

	// ���� ��������� �������� �� ����� ���� �� ��� �� ������������� 
	if ((routeTime / timeToRelax) - amountStop == 0)  //���� ��� �������
	{
		--amountStop;
	}


	if (amountStop >= 1)
	{
		routeTime = routeTime + 10 + (amountStop - 1) * 5;
	}

	return routeTime;
}