#pragma once
#include "sinh_vien.h"

class SinhVienDaiHoc : public SinhVien
{
private:
	string tenBaiLuan;
	float diemBaiLuan;
public:
	SinhVienDaiHoc();
	~SinhVienDaiHoc();

	void Nhap();
	void Xuat();
	bool DauTotNghiep();
};

