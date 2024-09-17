#pragma once
#include <string>

class Vehicle
{
protected:
	std::string name;
	enum vehicleType { ground = 1, flying };
	int speed;
public:
	std::string getName();
	virtual double getRaceTime(int distance);
	virtual vehicleType getVehicleType();
};