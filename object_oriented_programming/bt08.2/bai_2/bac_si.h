#pragma once
#include "nguoi.h"

class BacSi : public Nguoi
{
private:
	string khoaChuyenMon;
	int soNamChua;
public:
	BacSi();
	~BacSi();

	void Input();
	void Output();
};

