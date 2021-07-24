#pragma once
#include "rectangle.h"
#include "parallelogram.h"
#include "square.h"
#include "quadrangle.h"
#include "triangle.h"
#include "pentagon.h"
#include "polygon.h"
#include <vector>

class ListPolygons
{
private:
	vector <Polygon*>list;
	int size;
public:
	ListPolygons();
	~ListPolygons();

	void Input();
	void Output();

	void Trans(float, float);
	void Relate(float);
	void ZoomIn_Out(float);
};

