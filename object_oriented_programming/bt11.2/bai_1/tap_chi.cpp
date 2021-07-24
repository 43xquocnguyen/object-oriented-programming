#include "tap_chi.h"

TapChi::TapChi() : Sach() 
{
    this->tenBia = "";
    this->soTrang = 0;
    this->check = 1;
}
TapChi::~TapChi()
{
}

void TapChi::Input() {
    Sach::Input();
    cout << "NHAP TEN BIA: ";
    getline(cin, this->tenBia);
    do
    {
        cout << "NHAP SO TRANG: ";
        cin >> this->soTrang;
        if (this->soTrang <= 0)
            cout << "SO TRANG KHONG HOP LE\n";
    } while (this->soTrang <= 0);
    cin.ignore();
}
void TapChi::Output() {
    Sach::Output();
    cout << setw(20) << left << this->tenBia;
    cout << setw(15) << left << this->soTrang;
}
