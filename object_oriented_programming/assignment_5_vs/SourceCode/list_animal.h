#pragma once
#include "animal.h" 
#include "goat.h"
#include "cow.h" 
#include "sheep.h" 
#include <vector>
#include <iomanip>

class ListAnimal
{
private:
	vector<Animal*> list;
	vector<string> ten;
	float* soLitSua;
	int* soConDe;
	int* soLuong;
public:
	ListAnimal();
	~ListAnimal();

	void Input();
	void DiVang();
	void ThongKe();
};

