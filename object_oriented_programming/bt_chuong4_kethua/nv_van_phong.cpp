#include "nv_van_phong.h"

NVVanPhong::NVVanPhong() : NhanVien() {
	this->soNgayLam = 0;
}
NVVanPhong::NVVanPhong(string hoTen, Date* ngaySinh, int soNgayLam) : NhanVien(hoTen, ngaySinh) {
	this->soNgayLam = soNgayLam;
}
NVVanPhong::~NVVanPhong() {
	delete ngaySinh;
}

void NVVanPhong::Input() {
	NhanVien::Input();
	do
	{
		cout << "NHAP SO NGAY LAM: ";
		cin >> this->soNgayLam;
		if (this->soNgayLam <= 0) cout << "SO NGAY LAM KHONG HOP LE\n";
	} while (this->soNgayLam <= 0);
	this->luong = this->soNgayLam * 100000;
	this->check = 0;
}
void NVVanPhong::Output() {
	NhanVien::Output();
	cout << setw(15) << left << this->soNgayLam;
	cout << setw(20) << left << this->luong;
}