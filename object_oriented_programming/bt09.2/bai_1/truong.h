#pragma once
#include "sinh_vien.h"
#include "sv_dai_hoc.h"
#include "sv_cao_dang.h"
#include <vector>

class Truong
{
private:
	vector<SinhVien *> list;
	int soLuongDH, soLuongCD;
	
public:
	void Bang() {
		cout << setw(15) << left << "MSSV";
		cout << setw(25) << left << "HO VA TEN";
		cout << setw(20) << left << "DIA CHI";
		cout << setw(15) << left << "SO TIN CHI";
		cout << setw(10) << left << "DIEM TB";
	}
	void BangDH() {
		this->Bang();
		cout << setw(18) << left << "TEN BAI LUAN";
		cout << setw(15) << left << "DIEM BAI LUAN" << endl;
		cout << setfill('-') << setw(115) << "-" << endl;
		cout << setfill(' ');
	}
	void BangCD() {
		this->Bang();
		cout << setw(15) << left << "DIEM THI TN" << endl;
		cout << setfill('-') << setw(100) << "-" << endl;
		cout << setfill(' ');
	}

	Truong();
	~Truong();

	void Input(int);
	void Output();

	int SoLuongDauTN();

	SinhVien* DHGioiNhat();
	SinhVien* CDGioiNhat();
};

