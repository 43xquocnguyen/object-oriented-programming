#pragma once
#include "point.h"
#include <vector>

class Polygon
{
private:
	Point* point;
	int n;
public:
	Polygon();
	~Polygon();

	void Input();
	void Output();

	void Trans(float, float);
	Point Center_Point();
};