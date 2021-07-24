#pragma once
#include <iostream>
#include <string>
#include "thoi_gian.h"
#include <iomanip>

class Nguoi
{	
protected:
	string hoTen;
	ThoiGian *ngaySinh;
	string diaChi;
	string noiLamViec;
	int check;
public:
	int Check();
	Nguoi();
	~Nguoi();

	virtual void Input();
	virtual void Output();
};

