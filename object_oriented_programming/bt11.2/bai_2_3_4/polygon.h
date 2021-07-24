#pragma once
#include "point.h"
#include <vector>

class Polygon
{
protected:
	Point* point;
	int n;
	int tick;
public:
	Polygon();
	Polygon(int);
	~Polygon();
	int Tick() { return this->tick; }

	virtual void Input();
	virtual void Output();
	virtual bool Check();

	void Trans(float, float);
	void Relate(float);
	void Zoom(float);
	Point Center_Point();
};