#pragma once
#include "flying.h"

class Broom : public Flying
{
public:
	Broom();
	double getRaceTime(int distance) override;
};
