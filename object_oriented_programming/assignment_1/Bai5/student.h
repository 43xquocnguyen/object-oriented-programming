#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Student
{
private:
	string hoTen;
    float diemToan;
    float diemVan;
    void Bang() {
		cout << setfill(' ');
        cout << setw(35) << left << "HO VA TEN";
        cout << setw(15) << left << "DIEM TOAN";
        cout << setw(15) << left << "DIEM VAN";
        cout << setw(18) << left << "DIEM TRUNG BINH" << endl;
        cout << setfill('-') << setw(80) << "-" << endl;
	}
public:
    float TinhDiemTrungBinh();
	void Nhap();
	void Xuat();
};