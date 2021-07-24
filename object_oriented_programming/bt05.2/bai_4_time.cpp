#pragma once
#include <iostream>
using namespace std;

class Time
{
private:
    int ngay, thang, nam;
    bool daNhap;
    bool LeapYear() {
        if ((this->nam % 4 == 0 && this->nam % 100 != 0) || this->nam % 400 == 0) {
            return true;
        }
        return false;
    }
    int SoNgayCuaThang() {
        switch (this->thang) {
        case 4: case 6: case 9: case 11: {
            return 30;
        }
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: {
            return 31;
        }
        case 2: {
            if (LeapYear()) {
                return 29;
            }
            return 28;
        }
        }
    }
public:
    Time();
    Time(int, int, int);
    ~Time();
    bool KiemTraDaNhap();
    void Nhap();
    void Xuat();
    Time TimNgayKeTiep();
};

Time::Time() {
    this->ngay = 0;
    this->thang = 0;
    this->nam = 0;
    this->daNhap = false;
}
Time::Time(int ngay, int thang, int nam) {
    this->ngay = ngay;
    this->thang = thang;
    this->nam = nam;
}
Time::~Time() { }

void Time::Nhap() {
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
            if (!LeapYear()) {
                cout << "DAY KHONG PHAI LA NAM NHUAN. VUI LONG KIEM TRA LAI\n";
                goto nhap;
            }
        }
    }

    this->daNhap = true;
}

void Time::Xuat() {
    cout << this->ngay << "/" << this->thang << "/" << this->nam;
}
Time Time::TimNgayKeTiep() {
    Time* temp = new Time(this->ngay, this->thang, this->nam);
    if (temp->ngay != SoNgayCuaThang())
    {
        temp->ngay++;
    }
    else {
        if (temp->ngay == SoNgayCuaThang() && temp->thang == 12) {
            temp->ngay = 1;
            temp->thang = 1;
            temp->nam++;
        }
        else {
            temp->ngay = 1;
            temp->thang++;
        }
    }
    return *temp;
}
bool Time::KiemTraDaNhap() {
    return this->daNhap;
}
