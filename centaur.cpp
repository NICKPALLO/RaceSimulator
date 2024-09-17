#include "centaur.h"

Centaur::Centaur()
{
	name = "�������";
	speed = 15;
	timeToRelax = 8;
	type = ground;
}

double Centaur::getRaceTime(int distance)
{
	double routeTime = distance / speed;

	int amountStop = static_cast<int>(routeTime / timeToRelax);

	// ���� ��������� �������� �� ����� ���� �� ��� �� ������������� 
	if ((routeTime / timeToRelax) - amountStop == 0)  //���� ��� �������
	{
		--amountStop;
	}

	routeTime = routeTime + 2 * amountStop;

	return routeTime;
}