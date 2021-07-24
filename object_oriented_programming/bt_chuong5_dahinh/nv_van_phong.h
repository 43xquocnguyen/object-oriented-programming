#pragma once
#include "nhan_vien.h"
#include <string>

class NVVanPhong : public NhanVien
{
private:
	int soNgayLam;
public:
	NVVanPhong();
	NVVanPhong(string, Date*, int);
	~NVVanPhong();

	void Input();
	void Output();
};

