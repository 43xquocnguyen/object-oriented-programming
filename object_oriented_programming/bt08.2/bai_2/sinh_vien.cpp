#include "sinh_vien.h"

SinhVien::SinhVien() : Nguoi() {
	this->maSV = "";
	this->diemTB = 0;
	this->check = 0;
}
SinhVien::~SinhVien() {

}

void SinhVien::Input() {
	Nguoi::Input();
	cout << "NHAP MA SINH VIEN: ";
	getline(cin, this->maSV);
	do
	{
		cout << "NHAP DIEM TB: ";
		cin >> this->diemTB;
		if (this->diemTB <= 0 || this->diemTB > 10)
			cout << "DIEM TB KHONG HOP LE\n";
	} while (this->diemTB <=0 || this->diemTB > 10);
	this->noiLamViec = "TRUONG HOC";
}
void SinhVien::Output() {
	Nguoi::Output();
	cout << setw(20) << left << this->maSV;
	cout << setw(15) << left << this->diemTB;
	cout << setw(20) << left << this->noiLamViec;
}