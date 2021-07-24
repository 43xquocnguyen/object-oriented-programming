#pragma once
#include <iostream>
#include <string>
using namespace std;

class PhanSo
{
private:
    int tuSo, mauSo;
    bool daNhap;
    int UCLN()
    {
        int n = tuSo, m = mauSo;
        if (n < 0)
        {
            n *= -1;
        }
        if (m < 0)
        {
            m *= -1;
        }
        while (n != m)
        {
            if (n > m)
            {
                n -= m;
            }
            if (m > n)
            {
                m -= n;
            }
        }
        return n;
    }
public:
    PhanSo();
    PhanSo(int, int);
    ~PhanSo();

    bool KiemTraDaNhap();
    void NhapPhanSo();
    void RutGonPhanSo();
    void XuatPhanSo();
    bool SoSanhPhanSo(PhanSo *);
    int getTuSo();

    PhanSo TinhTong(PhanSo);
    PhanSo TinhHieu(PhanSo);
    PhanSo TinhTich(PhanSo);
    PhanSo TinhThuong(PhanSo);
};