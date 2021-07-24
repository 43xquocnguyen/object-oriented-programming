#pragma once
#include "robot.h"
#include "carrier.h"
#include "pedion.h"
#include "zattacker.h"
#include <vector>

class ListRobot
{
private:
	vector<Robot*>list;
	float S;
	unsigned int num;
public:
	ListRobot();
	~ListRobot();

	void Input();
	void Output();
	void SetterS(float);
	float GetterS();
	unsigned int GetterNum();

	Robot* TheMostEnergy();
	float SumEnergy();
};

