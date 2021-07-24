#include "sv_dai_hoc.h"

SinhVienDaiHoc::SinhVienDaiHoc() : SinhVien() {
	this->tenBaiLuan = "";
	this->diemBaiLuan = 0;
	this->loai = true;
}
SinhVienDaiHoc::~SinhVienDaiHoc() {

}

void SinhVienDaiHoc::Nhap() {
	SinhVien::Nhap();
	cout << "NHAP TEN BAI LUAN: ";
	getline(cin, this->tenBaiLuan);
	do
	{
		cout << "NHAP DIEM BAI LUAN: ";
		cin >> this->diemBaiLuan;
		if (this->diemBaiLuan < 0 || this->diemBaiLuan > 10) {
			cout << "DIEM KHONG HOP LE\n";
		}
	} while (this->diemBaiLuan < 0 || this->diemBaiLuan > 10);
}
void SinhVienDaiHoc::Xuat() {
	SinhVien::Xuat();
	cout << setw(18) << left << this->tenBaiLuan;
	cout << setw(15) << left << this->diemBaiLuan;
}
bool SinhVienDaiHoc::DauTotNghiep() {
	if (this->soTinChi >= 170 && this->diemTB >= 5 && this->diemBaiLuan >= 5) return true;
	return false;
}
