#pragma once
#include "vehicle.h"


class Ground: public Vehicle
{
private:

protected:
	int timeToRelax;
	vehicleType type = ground;
public:
	vehicleType getVehicleType() override;
};