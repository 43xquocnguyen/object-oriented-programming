#include "ca_si.h"

CaSi::CaSi() : Nguoi() {
	this->dongNhac = "";
	this->soShow = this->soAlbum = 0;
	this->check = 2;
}
CaSi::~CaSi() {

}

void CaSi::Input() {
	Nguoi::Input();
	cout << "NHAP DONG NHAC CUA CA SI: ";
	getline(cin, this->dongNhac);
	
	do
	{
		cout << "NHAP SO SHOW DA DIEN: ";
		cin >> this->soShow;
		if (this->soShow <= 0) {
			cout << "SO SHOW DIEN KHONG HOP HE\n";
		}
	} while (this->soShow <= 0);

	do
	{
		cout << "NHAP SO ALBUM DA RA MAT: ";
		cin >> this->soAlbum;
		if (this->soAlbum <= 0) {
			cout << "SO ALBUM DA RA MAT KHONG HOP HE\n";
		}
	} while (this->soAlbum <= 0);

	this->noiLamViec = "SAN KHAU";
}
void CaSi::Output() {
	Nguoi::Output();
	cout << setw(20) << left << this->dongNhac;
	cout << setw(15) << left << this->soShow;
	cout << setw(15) << left << this->soAlbum;
	cout << setw(20) << left << this->noiLamViec;
}