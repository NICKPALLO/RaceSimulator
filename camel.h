#pragma once
#include "ground.h"

class Camel : public Ground
{
public:
	Camel();
	double getRaceTime(int distance) override;
};