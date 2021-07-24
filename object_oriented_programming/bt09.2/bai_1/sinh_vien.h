#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class SinhVien
{
protected:
    string ID;
    string hoTen;
    string diaChi;
    int soTinChi;
    float diemTB;
    bool loai;
public:
    SinhVien();
    ~SinhVien();
    
    float GetterDiemTB();
    bool LoaiSV();

    virtual void Nhap();
    virtual void Xuat();
    virtual bool DauTotNghiep() = 0;
};
