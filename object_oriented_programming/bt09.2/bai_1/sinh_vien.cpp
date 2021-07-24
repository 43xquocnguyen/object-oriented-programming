#include "sinh_vien.h"

SinhVien::SinhVien()
{
	this->ID = "";
	this->hoTen = "";
	this->diaChi = "";
	this->soTinChi = this->diemTB = 0;
}
SinhVien::~SinhVien()
{

}

float SinhVien::GetterDiemTB() {
	return this->diemTB;
}

bool SinhVien::LoaiSV() { return this->loai; }

void SinhVien::Nhap() {
	cout << "NHAP MSSV: ";
	getline(cin, this->ID);
	cout << "NHAP HO TEN: ";
	getline(cin, this->hoTen);
	cout << "NHAP DIA CHI: ";
	getline(cin, this->diaChi);

	do
	{
		cout << "NHAP SO TIN CHI: ";
		cin >> this->soTinChi;
		if (this->soTinChi <= 0) {
			cout << "SO TIN CHI KHONG HOP LE\n";
		}
	} while (this->soTinChi <= 0);

	do
	{
		cout << "NHAP DIEM TRUNG BINH: ";
		cin >> this->diemTB;
		if (this->diemTB <= 0 || this->diemTB > 10) {
			cout << "DIEM KHONG HOP LE\n";
		}
	} while (this->diemTB <= 0 || this->diemTB > 10);
	cin.ignore();
}
void SinhVien::Xuat() {
	cout << setw(15) << left << this->ID;
	cout << setw(25) << left << this->hoTen;
	cout << setw(20) << left << this->diaChi;
	cout << setw(15) << left << this->soTinChi;
	cout << setw(10) << left << this->diemTB;
}