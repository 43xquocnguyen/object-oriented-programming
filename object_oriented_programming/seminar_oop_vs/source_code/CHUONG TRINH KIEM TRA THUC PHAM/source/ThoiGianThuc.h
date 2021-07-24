#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include"Date.h"

using namespace std;

class ThoiGianThuc {
private:
	Date thoigianthuc;
public:
	ThoiGianThuc();
	~ThoiGianThuc();


	Date getterThoiGianThuc();
	void KhoiTao();
	//void Xuat();
};

