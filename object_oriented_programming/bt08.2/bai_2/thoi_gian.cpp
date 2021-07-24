#include "thoi_gian.h"
#include <iomanip>

ThoiGian::ThoiGian() {
    this->ngay = 0;
    this->thang = 0;
    this->nam = 0;
}
ThoiGian::~ThoiGian() { }

void ThoiGian::Input() {
nhap:
    do
    {
        cout << "NHAP NGAY: ";
        cin >> this->ngay;
        if (this->ngay < 1 || this->ngay > 31) {
            cout << "NGAY KHONG HOP LE\n";
        }
        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            this->ngay = -1;
        }
    } while (this->ngay < 1 || this->ngay > 31);

    do
    {
        cout << "NHAP THANG: ";
        cin >> this->thang;
        if (this->thang < 1 || this->thang > 12) {
            cout << "THANG KHONG HOP LE\n";
        }
        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            this->thang = -1;
        }
    } while (this->thang < 1 || this->thang > 12);

    switch (this->thang) {
    case 4: case 6: case 9: case 11: {
        if (this->ngay == 31) {
            cout << "NGAY KHONG THE VUOT QUA 30\n";
            goto nhap;
        }
    }
    case 2: {
        if (this->ngay > 29) {
            cout << "NGAY KHONG THE VUOT QUA 29\n";
            goto nhap;
        }
    }
    }

    do
    {
        cout << "NHAP NAM: ";
        cin >> this->nam;
        if (this->nam <= 0) {
            cout << "NAM KHONG HOP LE\n";
        }
        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            this->nam = -1;
        }
    } while (this->nam <= 0);

    if (this->thang == 2) {
        if (this->ngay == 29) {
            if (!this->LeapYear()) {
                cout << "DAY KHONG PHAI LA NAM NHUAN. VUI LONG KIEM TRA LAI\n";
                goto nhap;
            }
        }
    }
}
void ThoiGian::Output() {
    if (this->ngay < 10) {
        cout << setw(1) << left << 0;
        cout << setw(1) << left << this->ngay;
    }
    else cout << setw(2) << left << this->ngay;
    cout << setw(1) << left << "/";
    if (this->thang < 10) {
        cout << setw(1) << left << 0;
        cout << setw(1) << left << this->thang;
    }
    else cout << setw(2) << left << this->thang;
    cout << setw(1) << left << "/";
    cout << setw(9) << left << this->nam;
}
