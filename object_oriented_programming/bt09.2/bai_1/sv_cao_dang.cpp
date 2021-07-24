#include "sv_cao_dang.h"

SinhVienCaoDang::SinhVienCaoDang() : SinhVien() {
	this->diemThiTN = 0;
	this->loai = false;
}
SinhVienCaoDang::~SinhVienCaoDang() {

}

void SinhVienCaoDang::Nhap() {
	SinhVien::Nhap();
	do
	{
		cout << "NHAP DIEM THI TOT NGHIEP: ";
		cin >> this->diemThiTN;
		if (this->diemThiTN < 0 || this->diemThiTN > 10) {
			cout << "DIEM THI TN KHONG HOP LE\n";
		}
	} while (this->diemThiTN < 0 || this->diemThiTN > 10);
}
void SinhVienCaoDang::Xuat() {
	SinhVien::Xuat();
	cout << setw(15) << left << this->diemThiTN;
}
bool SinhVienCaoDang::DauTotNghiep() {
	if (this->soTinChi >= 120 && this->diemTB >= 5 && this->diemThiTN >= 5) return true;
	return false;
}