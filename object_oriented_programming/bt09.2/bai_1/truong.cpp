#include "truong.h"

Truong::Truong() {
	this->soLuongCD = this->soLuongDH = 0;
}
Truong::~Truong() {

}

void Truong::Input(int n) {
	for (int i = 0; i < n; i++)
	{
		char lc;
		do
		{
			system("cls");
			cout << "1. SINH VIEN CAO DANG\n";
			cout << "2. SINH VIEN DAI HOC\n";
			cout << "\nLUA CHON: ";
			cin >> lc;
			if (lc != '1' && lc != '2') cout << "LUA CHON KHONG HOP LE\n";
			cin.ignore();
		} while (lc != '1' && lc != '2');

		SinhVien* p;
		if (lc == '1') {
			p = new SinhVienCaoDang;
			p->Nhap();
			list.push_back(p);
			this->soLuongCD++;
		}
		else {
			p = new SinhVienDaiHoc;
			p->Nhap();
			list.push_back(p);
			this->soLuongDH++;
		}

	}
}
void Truong::Output() {
	if (this->soLuongDH) {
		cout << "\t\t\t\t\tDANH SACH SINH VIEN DAI HOC\n\n";
		this->BangDH();
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i]->LoaiSV()) {
				list[i]->Xuat();
				cout << endl;
			}
		}
	}
	else {
		cout << "\t\t\t\t\tKHONG CO SINH VIEN DAI HOC NAO\n\n";
	}

	cout << "\n\n";

	if (this->soLuongCD) {
		cout << "\t\t\t\t\tDANH SACH SINH VIEN CAO DANG\n\n";
		this->BangCD();
		for (int i = 0; i < list.size(); i++)
		{
			if (!list[i]->LoaiSV()) {
				list[i]->Xuat();
				cout << endl;
			}
		}
	}
	else {
		cout << "\t\t\t\t\tKHONG CO SINH VIEN CAO DANG NAO\n\n";
	}
}
int Truong::SoLuongDauTN() {
	int pass = 0;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->DauTotNghiep()) pass++;
	}
	return pass;
}

SinhVien* Truong::DHGioiNhat() {
	if (!this->soLuongDH) return NULL;
	int diemTBMax = INT_MIN;
	int vt = 0;
	int size = list.size();

	for (int i = 0; i < size; i++)
	{
		if (list.at(i)->LoaiSV() && diemTBMax < list.at(i)->GetterDiemTB()) {
			diemTBMax = list.at(i)->GetterDiemTB();
			vt = i;
		}
	}
	return list[vt];
}
SinhVien* Truong::CDGioiNhat() {
	if (!this->soLuongCD) return NULL;
	int diemTBMax = INT_MIN;
	int vt = 0;
	int size = list.size();

	for (int i = 0; i < size; i++)
	{
		if (!list.at(i)->LoaiSV() && diemTBMax < list.at(i)->GetterDiemTB()) {
			diemTBMax = list.at(i)->GetterDiemTB();
			vt = i;
		}
	}
	return list[vt];
}