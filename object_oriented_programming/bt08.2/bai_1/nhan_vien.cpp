#include "nhan_vien.h"

NhanVien::NhanVien() {
	this->hoTen = "";
	this->ngaySinh = NULL;
	this->luong = 0;
}
NhanVien::NhanVien(string hoTen, Date* ngaySinh) {
	this->hoTen = hoTen;
	this->ngaySinh = new Date;
	*this->ngaySinh = *ngaySinh;
}
void NhanVien::Input() {
	cout << "NHAP TEN NHAN VIEN: ";
	cin.ignore();
	getline(cin, this->hoTen);
	cout << "NHAP NGAY THANG NAM SINH\n";
	this->ngaySinh = new Date;
	this->ngaySinh->Input();
	this->luong = 100000000;
}
long NhanVien::getLuong() {
	return this->luong;
}
void NhanVien::Output() {
	cout << setw(25) << left << this->hoTen;
	this->ngaySinh->Output();
}
NhanVien::~NhanVien() {
	delete ngaySinh;
}