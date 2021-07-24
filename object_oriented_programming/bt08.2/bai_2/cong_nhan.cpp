#include "cong_nhan.h"

CongNhan::CongNhan() : Nguoi() {
	this->luongCoBan = this->soNamKinhNghiem = this->soNgayPhep = 0;
	this->check = 1;
}
CongNhan::~CongNhan() {

}

void CongNhan::Input() {
	Nguoi::Input();
	do
	{
		cout << "NHAP LUONG CO BAN: ";
		cin >> this->luongCoBan;
		if (this->luongCoBan <= 0) cout << "LUONG CO BAN KHONG HOP LE\n";
	} while (this->luongCoBan <= 0);

	do
	{
		cout << "NHAP SO NGAY PHEP: ";
		cin >> this->soNgayPhep;
		if (this->soNgayPhep < 0) cout << "SO NGAY PHEP KHONG HOP LE\n";
	} while (this->soNgayPhep < 0);

	do
	{
		cout << "NHAP SO NAM KINH NGHIEM: ";
		cin >> this->soNamKinhNghiem;
		if (this->soNamKinhNghiem < 0) cout << "SO NAM KINH NGHIEM KHONG HOP LE\n";
	} while (this->soNamKinhNghiem < 0);
	cin.ignore();

	this->noiLamViec = "NHA MAY";
}
void CongNhan::Output() {
	Nguoi::Output();
	cout << setw(20) << left << this->luongCoBan;
	cout << setw(15) << left << this->soNgayPhep;
	cout << setw(15) << left << this->soNamKinhNghiem;
	cout << setw(20) << left << this->noiLamViec;
}