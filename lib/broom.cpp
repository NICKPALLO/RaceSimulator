#include "broom.h"

Broom::Broom()
{
	name = "Метла";
	speed = 20;
	type = flying;
}

double Broom::getRaceTime(int distance)
{
	double routeTime = distance / speed;

	int k = distance / 1000;

	routeTime = routeTime * (100-k)/100;

	return routeTime;
}