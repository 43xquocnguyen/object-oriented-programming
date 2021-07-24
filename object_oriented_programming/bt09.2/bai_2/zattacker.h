#pragma once
#include "robot.h"

class Zattacker : public Robot
{
private:
	float* P;
public:
	Zattacker();
	~Zattacker();

	float EnergyConsum(float);
	void Output(float);
};

