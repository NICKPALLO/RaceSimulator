#pragma once
#include "flying.h"

class Eagle : public Flying
{
public:
	Eagle();
	double getRaceTime(int distance) override;
};
