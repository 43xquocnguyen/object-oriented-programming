#pragma once
#include "polygon.h"

class Quadrangle : public Polygon
{
private:
	const int v = 4;
public:
	Quadrangle();
	~Quadrangle();

	virtual void Input();
	virtual bool Check();
};