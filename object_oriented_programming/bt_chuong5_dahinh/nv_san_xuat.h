#pragma once
#include "nhan_vien.h"

class NVSanXuat : public NhanVien
{
private:
	int luongCanBan;
	int soSanPham;
public:
	NVSanXuat();
	NVSanXuat(string, Date*, int, int);
	~NVSanXuat();

	void Input();
	void Output();
};

