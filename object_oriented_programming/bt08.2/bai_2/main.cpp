#include "bac_si.h"
#include "cong_nhan.h"
#include "ca_si.h"
#include "sinh_vien.h"
#include <vector>
using namespace std;

void Nhap(vector<Nguoi*> *&list) {
	while (true)
	{
		system("cls");
		cout << "1. SINH VIEN\n";
		cout << "2. CONG NHAN\n";
		cout << "3. BAC SI\n";
		cout << "4. CA SI\n";
		cout << "0. THOAT\n";
		cout << "\nLUA CHON: ";
		char lc;
		cin >> lc;
		cin.ignore();

		if (lc == '0') break;
		else if (lc == '1') {
			system("cls");
			Nguoi* p = new SinhVien;
			p->Input();
			list->push_back(p);
		}
		else if (lc == '2') {
			system("cls");
			Nguoi* p = new CongNhan;
			p->Input();
			list->push_back(p);
		}
		else if (lc == '3') {
			system("cls");
			Nguoi* p = new BacSi;
			p->Input();
			list->push_back(p);
		}
		else if (lc == '4') {
			system("cls");
			Nguoi* p = new CaSi;
			p->Input();
			list->push_back(p);
		}
		else {
			system("cls");
			cout << "LUA CHON KHONG HOP LE\n";
			system("pause");
		}
	}
}

void XuatSinhVien(vector<Nguoi*>* list) {
	system("cls");
	int size = list->size();
	cout << setw(25) << left << "HO VA TEN";
	cout << setw(15) << left << "NGAY SINH";
	cout << setw(25) << left << "DIA CHI";
	cout << setw(20) << left << "MSSV";
	cout << setw(15) << left << "DIEM TB";
	cout << setw(20) << left << "NOI LAM VIEC" << endl;
	cout << setfill('-') << setw(120) << "-" << endl;
	cout << setfill(' ') << endl;
	for (int i = 0; i < size; i++)
	{
		if (!list->at(i)->Check()) {
			list->at(i)->Output();
			cout << endl;
		}
	}
}
void XuatCongNhan(vector<Nguoi*>* list) {
	system("cls");
	int size = list->size();
	cout << setw(25) << left << "HO VA TEN";
	cout << setw(15) << left << "NGAY SINH";
	cout << setw(25) << left << "DIA CHI";
	cout << setw(20) << left << "LUONG CO BAN";
	cout << setw(15) << left << "SO NGAY PHEP";
	cout << setw(15) << left << "SO NAM KN";
	cout << setw(20) << left << "NOI LAM VIEC" << endl;
	cout << setfill('-') << setw(120) << "-" << endl;
	cout << setfill(' ') << endl;
	for (int i = 0; i < size; i++)
	{
		if (list->at(i)->Check() == 1) {
			list->at(i)->Output();
			cout << endl;
		}
	}
}
void XuatCaSi(vector<Nguoi*>* list) {
	system("cls");
	int size = list->size();
	cout << setw(25) << left << "HO VA TEN";
	cout << setw(15) << left << "NGAY SINH";
	cout << setw(25) << left << "DIA CHI";
	cout << setw(20) << left << "DONG NHAC";
	cout << setw(15) << left << "SO SHOW";
	cout << setw(15) << left << "SO ALBUM";
	cout << setw(20) << left << "NOI LAM VIEC" << endl;
	cout << setfill('-') << setw(120) << "-" << endl;
	cout << setfill(' ') << endl;
	for (int i = 0; i < size; i++)
	{
		if (list->at(i)->Check() == 2) {
			list->at(i)->Output();
			cout << endl;
		}
	}
}
void XuatBacSi(vector<Nguoi*>* list) {
	system("cls");
	int size = list->size();
	cout << setw(25) << left << "HO VA TEN";
	cout << setw(15) << left << "NGAY SINH";
	cout << setw(25) << left << "DIA CHI";
	cout << setw(20) << left << "KHOA CHUYEN MON";
	cout << setw(15) << left << "SO NAM CHUA";
	cout << setw(20) << left << "NOI LAM VIEC" << endl;
	cout << setfill('-') << setw(120) << "-" << endl;
	cout << setfill(' ') << endl;
	for (int i = 0; i < size; i++)
	{
		if (list->at(i)->Check() == 3) {
			list->at(i)->Output();
			cout << endl;
		}
	}
}

void Xuat(vector<Nguoi*>* list) {
	while (true)
	{
		system("cls");
		cout << "1. SINH VIEN\n";
		cout << "2. CONG NHAN\n";
		cout << "3. CA SI\n";
		cout << "4. BAC SI\n";
		cout << "0. THOAT\n";
		cout << "\nLUA CHON: ";
		char lc;
		cin >> lc;
		cin.ignore();

		if (lc == '0') break;
		else if (lc == '1') {
			system("cls");
			XuatSinhVien(list);
			system("pause");
		}
		else if (lc == '2') {
			system("cls");
			XuatCongNhan(list);
			system("pause");
		}
		else if (lc == '3') {
			system("cls");
			XuatCaSi(list);
			system("pause");
		}
		else if (lc == '4') {
			system("cls");
			XuatBacSi(list);
			system("pause");
		}
		else {
			system("cls");
			cout << "LUA CHON KHONG HOP LE\n";
			system("pause");
		}
	}
}

void Menu(vector<Nguoi*>* list) {
	while (true)
	{
		system("cls");
		cout << "1. THEM THONG TIN\n";
		cout << "2. XUAT THONG TIN\n";
		cout << "0. THOAT\n";
		cout << "\nLUA CHON: ";
		char lc1;
		cin >> lc1;
		cin.ignore();

		if (lc1 == '0') break;
		else if (lc1 == '1') {
			Nhap(list);
		}
		else if (lc1 == '2') {
			Xuat(list);
			system("pause");
		}
		else {
			system("cls");
			cout << "LUA CHON KHONG HOP LE\n";
			system("pause");
		}
	}
}


int main() {
	vector<Nguoi*>* list;
	list = new vector<Nguoi*>;
	Menu(list);
	delete list;
	return 0;
}