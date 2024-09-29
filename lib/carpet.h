#pragma once
#include "flying.h"

class Carpet : public Flying
{
public:
	Carpet();
	double getRaceTime(int distance) override;
};
