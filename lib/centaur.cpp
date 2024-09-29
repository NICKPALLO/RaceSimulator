#include "centaur.h"

Centaur::Centaur()
{
	name = " ентавр";
	speed = 15;
	timeToRelax = 8;
	type = ground;
}

double Centaur::getRaceTime(int distance)
{
	double routeTime = distance / speed;

	int amountStop = static_cast<int>(routeTime / timeToRelax);

	// ≈сли остановка выпадает на конец пути то она не засчитываетс€ 
	if ((routeTime / timeToRelax) - amountStop == 0)  //если нет остатка
	{
		--amountStop;
	}

	routeTime = routeTime + 2 * amountStop;

	return routeTime;
}