#include "sach.h"

Sach::Sach()
{
    this->giaBan = this->check = 0;
    this->tenSach = this->tenTacGia = "";
}
Sach::~Sach()
{
}

void Sach::Input() {
    cout << "NHAP TEN SACH: ";
    getline(cin, this->tenSach);
    cout << "NHAP TAC GIA: ";
    getline(cin, this->tenTacGia);
    do
    {
        cout << "NHAP GIA BAN ($): ";
        cin >> this->giaBan;
        if (this->giaBan <= 0)
            cout << "GIA BAN KHONG HOP LE\n";
    } while (this->giaBan <= 0);
    cin.ignore();
}
void Sach::Output() {
    cout << setw(20) << left << this->tenSach;
    cout << setw(20) << left << this->tenTacGia;
    cout << setw(20) << left << this->giaBan;
}