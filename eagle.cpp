#include "eagle.h"

Eagle::Eagle ()
{
	name = "���";
	speed = 8;
	type = flying;
}

double Eagle::getRaceTime(int distance)
{
	double routeTime = distance / speed;

	routeTime = routeTime * 0.94;

	return routeTime;
}