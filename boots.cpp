#include "boots.h"

Boots::Boots()
{
	name = "Ѕотинки-вездеходы";
	speed = 6;
	timeToRelax = 60;
	type = ground;
}

double Boots::getRaceTime(int distance)
{
	double routeTime = distance / speed;

	int amountStop = static_cast<int>(routeTime / timeToRelax);

	// ≈сли остановка выпадает на конец пути то она не засчитываетс€ 
	if ((routeTime / timeToRelax) - amountStop == 0)  //если нет остатка
	{
		--amountStop;
	}


	if (amountStop >= 1)
	{
		routeTime = routeTime + 10 + (amountStop - 1) * 5;
	}

	return routeTime;
}