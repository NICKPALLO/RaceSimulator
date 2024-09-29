#include "camel.h"

Camel::Camel()
{
	name = "Верблюд";
	speed = 10;
	timeToRelax = 30;
	type = ground;
}

double Camel::getRaceTime(int distance)
{
	double routeTime = distance / speed;

	int amountStop = static_cast<int>(routeTime / timeToRelax);

	// Если остановка выпадает на конец пути то она не засчитывается 
	if ((routeTime / timeToRelax) - amountStop == 0)  //если нет остатка
	{
		--amountStop;
	}


	if (amountStop >= 1)
	{
		routeTime = routeTime + 5 + (amountStop - 1) * 8;
	}

	return routeTime;       
}