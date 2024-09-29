#include "fastCamel.h"

FastCamel::FastCamel()
{
	name = "Верблюд быстроход";
	speed = 40;
	timeToRelax = 10;
	type = ground;
}

double FastCamel::getRaceTime(int distance)
{
	double routeTime = distance / speed;

	int amountStop = static_cast<int>(routeTime / timeToRelax);

	// Если остановка выпадает на конец пути то она не засчитывается 
	if ((routeTime / timeToRelax) - amountStop == 0)  //если нет остатка
	{
		--amountStop;
	}

	if (amountStop > 0)
	{
		routeTime = routeTime + 5;
	}
	if (amountStop > 1)
	{
		routeTime = routeTime + 6 + 8 * (amountStop - 2);
	}

	return routeTime;
}