#pragma once
#include <iostream>
using namespace std;

class Time
{
private:
    int ngay, thang, nam;
    bool daNhap;

    bool LeapYear() {
        if ((this->nam % 4 == 0 && this->nam % 100 != 0) || this->nam % 400 ==0) {
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
            case 2:{
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