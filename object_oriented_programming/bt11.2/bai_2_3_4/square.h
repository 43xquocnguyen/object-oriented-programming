#pragma once
#include "quadrangle.h"

class Square : public Quadrangle
{
public:
	Square();
	~Square();

	void Input();
	bool Check();
};

