#pragma once
#include "vehicle.h"


class Flying : public Vehicle
{
private:

protected:
	vehicleType type = flying;
public:
	vehicleType getVehicleType() override;
};