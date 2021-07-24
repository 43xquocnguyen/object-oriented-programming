#pragma once
#include "quadrangle.h"

class Parallelogram : public Quadrangle
{
public:
	Parallelogram();
	~Parallelogram();

	void Input();
	bool Check();
};

