#pragma once
#include "robot.h"

class Carrier : public Robot
{
private:
	float* E;
public:
	Carrier();
	~Carrier();

	float EnergyConsum(float);
	void Output(float);
};

