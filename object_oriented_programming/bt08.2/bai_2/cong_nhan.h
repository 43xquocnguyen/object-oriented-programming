#pragma once
#include "nguoi.h"

class CongNhan : public Nguoi
{
private:
	long luongCoBan;
	int soNgayPhep, soNamKinhNghiem;
public:
	CongNhan();
	~CongNhan();

	void Input();
	void Output();
};

