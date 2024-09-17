#include "camel.h"

Camel::Camel()
{
	name = "�������";
	speed = 10;
	timeToRelax = 30;
	type = ground;
}

double Camel::getRaceTime(int distance)
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
		routeTime = routeTime + 5 + (amountStop - 1) * 8;
	}

	return routeTime;       
}