#include "sach_giao_khoa.h"

SachGiaoKhoa::SachGiaoKhoa() : Sach() 
{
    this->tenMon = "";
    this->sachLop = 0;
    this->check = 0;
}
SachGiaoKhoa::~SachGiaoKhoa()
{
}

void SachGiaoKhoa::Input() {
    Sach::Input();
    cout << "NHAP TEN MON: ";
    getline(cin, this->tenMon);
    do
    {
        cout << "NHAP SACH LOP: ";
        cin >> this->sachLop;
        if (this->sachLop <= 0 || this->sachLop > 12)
            cout << "LOP KHONG HOP LE\n";
    } while (this->sachLop <= 0 || this->sachLop > 12);
    cin.ignore();
}
void SachGiaoKhoa::Output() {
    Sach::Output();
    cout << setw(20) << left << this->tenMon;
    cout << setw(15) << left << this->sachLop;
}
