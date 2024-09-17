#pragma once
#include "ground.h"

class Centaur : public Ground
{
public:
	Centaur();
	double getRaceTime(int distance) override;
};