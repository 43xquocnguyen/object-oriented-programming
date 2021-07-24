#include "bac_si.h"

BacSi::BacSi() : Nguoi() {
	this->khoaChuyenMon = "";
	this->soNamChua = 0;
	this->check = 3;
}
BacSi::~BacSi() {

}

void BacSi::Input() {
	Nguoi::Input();

	cout << "NHAP KHOA CHUYEN MON: ";
	getline(cin, this->khoaChuyenMon);

	do
	{
		cout << "NHAP SO NAM CHUA BENH: ";
		cin >> this->soNamChua;
		if (this->soNamChua <= 0) cout << "SO NAM CHUA BENH KHONG HOP LE\n";
	} while (this->soNamChua <= 0);

	this->noiLamViec = "BENH VIEN";
}
void BacSi::Output() {
	Nguoi::Output();
	cout << setw(20) << left << this->khoaChuyenMon;
	cout << setw(15) << left << this->soNamChua;
	cout << setw(20) << left << this->noiLamViec;
}