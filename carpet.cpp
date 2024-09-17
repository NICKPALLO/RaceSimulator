#include "carpet.h"

Carpet::Carpet()
{
	name = "Ковер самолет";
	speed = 10;
	type = flying;
}

double Carpet::getRaceTime(int distance)
{
	double routeTime = distance / speed;

	int k=0;

	if (distance > 1000 || distance <5000)
	{
		k = 3;
	}
	else if (distance < 10000)
	{
		k = 10;
	}
	else if (distance >= 10000)
	{
		k = 5;
	}
	
	routeTime = routeTime * (100 - k) / 100;

	return routeTime;
}