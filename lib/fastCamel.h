#pragma once
#include "ground.h"

class FastCamel : public Ground
{
public:
	FastCamel();
	double getRaceTime(int distance) override;
};