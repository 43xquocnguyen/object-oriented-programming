#pragma once
#include "nguoi.h"

class SinhVien : public Nguoi
{
private:
	string maSV;
	float diemTB;
public:
	SinhVien();
	~SinhVien();

	void Input();
	void Output();
};

