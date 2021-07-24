#include "tieu_thuyet.h"

TieuThuyet::TieuThuyet() : Sach() 
{
    this->noiDungTT = "";
    this->soTap = 0;
    this->check = 2;
}
TieuThuyet::~TieuThuyet()
{
}

void TieuThuyet::Input() {
    Sach::Input();
    cout << "NHAP NOI DUNG CHINH: ";
    getline(cin, this->noiDungTT);
    do
    {
        cout << "NHAP SO TAP: ";
        cin >> this->soTap;
        if (this->soTap <= 0)
            cout << "LOP KHONG HOP LE\n";
    } while (this->soTap <= 0);
    cin.ignore();
}
void TieuThuyet::Output() {
    Sach::Output();
    cout << setw(20) << left << this->noiDungTT;
    cout << setw(15) << left << this->soTap;
}
