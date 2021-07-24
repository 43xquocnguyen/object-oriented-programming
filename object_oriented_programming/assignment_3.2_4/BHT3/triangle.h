#pragma once
#include "point.h"
#include <vector>

class TriAngle
{
private:
	Point *point;
public:
	TriAngle();
    TriAngle(Point, Point, Point);
    ~TriAngle();

	void Input();
	void Output();

	void Trans(float, float);
    Point *Center();
    float CalcS();
    float CalcC();
};