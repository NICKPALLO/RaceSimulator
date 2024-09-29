#pragma once
#include "ground.h"

class Boots : public Ground
{
public:
	Boots();
	double getRaceTime(int distance) override;
};