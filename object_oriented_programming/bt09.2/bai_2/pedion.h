#pragma once
#include "robot.h"

class Pedion : public Robot
{
private:
	float* F;
public:
	Pedion();
	~Pedion();

	float EnergyConsum(float);
	void Output(float);
};

