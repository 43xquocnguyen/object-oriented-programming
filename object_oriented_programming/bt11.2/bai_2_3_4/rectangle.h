#pragma once
#include "quadrangle.h"

class Rectangle : public Quadrangle
{
public:
	Rectangle();
	~Rectangle();

	void Input();
	bool Check();
};

