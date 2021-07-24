#include "nv_san_xuat.h"

NVSanXuat::NVSanXuat() : NhanVien() {
	this->soSanPham = this->luongCanBan = 0;
}
NVSanXuat::NVSanXuat(string hoTen, Date* ns, int scoutP, int luongCB) : NhanVien(hoTen, ns) {
	this->soSanPham = scoutP;
	this->luongCanBan = luongCB;
}
NVSanXuat::~NVSanXuat() {
	delete ngaySinh;
}

void NVSanXuat::Input() {
	NhanVien::Input();
	do
	{
		cout << "NHAP SO SAN PHAM: ";
		cin >> this->soSanPham;
		if (this->soSanPham <= 0) cout << "SO SAN PHAM KHONG THE NHO HON 0\n";
	} while (this->soSanPham <= 0);
	do
	{
		cout << "NHAP LUONG CAN BAN: ";
		cin >> this->luongCanBan;
		if (this->luongCanBan <= 0) cout << "LUONG CAN BAN KHONG THE NHO HON 0\n";
	} while (this->luongCanBan <= 0);
	this->luong = this->luongCanBan + this->soSanPham * 5000;
	this->check = 1;
}
void NVSanXuat::Output() {
	NhanVien::Output();
	cout << setw(25) << left << this->soSanPham;
	cout << setw(25) << left << this->luongCanBan;
	cout << setw(25) << left << this->luong;
}