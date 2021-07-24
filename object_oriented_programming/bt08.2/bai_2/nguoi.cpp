#include "nguoi.h"

Nguoi::Nguoi() {
	this->hoTen = "";
	this->ngaySinh = NULL;
	this->diaChi = "";
}
Nguoi::~Nguoi() {
	delete this->ngaySinh;
}
int Nguoi::Check() { return this->check; }

void Nguoi::Input() {
	cout << "NHAP TEN: ";
	getline(cin, this->hoTen);
	this->ngaySinh = new ThoiGian;
	cout << "NHAP NGAY THANG NAM SINH\n";
	this->ngaySinh->Input();
	cin.ignore();
	cout << "NHAP DIA CHI: ";
	getline(cin, this->diaChi);
}
void Nguoi::Output() {
	cout << setw(25) << left << this->hoTen;
	this->ngaySinh->Output();
	cout << setw(25) << left << this->diaChi;
}