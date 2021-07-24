#pragma once
#include "sinh_vien.h"

class SinhVienCaoDang : public SinhVien
{
private:
	float diemThiTN;
public:
	SinhVienCaoDang();
	~SinhVienCaoDang();

	void Nhap();
	void Xuat();
	bool DauTotNghiep();
};

