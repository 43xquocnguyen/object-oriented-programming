#pragma once
#include "polygon.h"

class TriAngle : public Polygon
{
private:
	const int v = 3;
public:
	TriAngle();
	~TriAngle();

	void Input();
	bool Check();
};

