#include "phan_so.h"

int PhanSo::getTuSo() {
    return this->tuSo;
}
PhanSo::PhanSo()
{
    this->tuSo = 0;
    this->mauSo = 1;
    this->daNhap = false;
}
PhanSo::PhanSo(int tuSo, int mauSo) {
    this->tuSo = tuSo;
    if (mauSo != 0) {
        this->mauSo = mauSo;
    }
}
PhanSo::~PhanSo() {}

bool PhanSo::KiemTraDaNhap()
{
    return this->daNhap;
}
void PhanSo::NhapPhanSo()
{
    bool checkTuSo;
    do
    {
        cout << "NHAP TU SO: ";
        cin >> this->tuSo;
        if (cin.fail())
        {
            cout << "TU SO KHONG HOP LE!\n";
            cin.clear();
            fflush(stdin);
            this->tuSo = -1;
            checkTuSo = false;
        }
        else
        {
            checkTuSo = true;
        }
        if (checkTuSo)
        {
            break;
        }
    } while (!checkTuSo);

    fflush(stdin);
    
    bool checkMauSo;
    do
    {
        cout << "NHAP MAU SO: ";
        cin >> this->mauSo;
        if (this->mauSo == 0 || cin.fail()) {
            cout << "PHAN SO KHONG TON TAI!\n";
            cout << "MAU SO KHONG HOP LE\n";
            cin.clear();
            cin.ignore(32767, '\n');
            this->mauSo = -1;
            checkMauSo = false;
        }
        else
        {
            checkMauSo = true;
        }
        if (checkMauSo)
        {
            break;
        }
    } while (this->mauSo == 0 || !checkMauSo);
    

    this->daNhap = true;
}
void PhanSo::XuatPhanSo()
{
    if (this->tuSo == 0)
    {
        cout << 0;
        return;
    }
    else if (this->mauSo == 1)
    {
        cout << this->tuSo;
    }
    else if (this->mauSo < 0) {
        if (this->tuSo < 0) {
            cout << this->tuSo * -1 << "/" << this->mauSo * -1;
        }
        else {
            cout << this->tuSo * -1 << "/" << this->mauSo * -1;
        }
    }
    else
    {
        cout << this->tuSo << "/" << this->mauSo;
    }
}
void PhanSo::RutGonPhanSo()
{
    int n = UCLN();
    this->tuSo /= n;
    this->mauSo /= n;
}
bool PhanSo::SoSanhPhanSo(PhanSo *a)
{
    double n = this->tuSo / this->mauSo;
    double m = a->tuSo / a->mauSo;
    if (n > m)
    {
        return true;
    }
    return false;
}

PhanSo PhanSo::TinhTong(PhanSo a)
{
    PhanSo kq;
    kq.tuSo = this->tuSo * a.mauSo + a.tuSo * this->mauSo;
    kq.mauSo = this->mauSo * a.mauSo;
    kq.RutGonPhanSo();
    return kq;
}
PhanSo PhanSo::TinhHieu(PhanSo a)
{
    PhanSo kq;
    kq.tuSo = this->tuSo * a.mauSo - a.tuSo * this->mauSo;
    kq.mauSo = this->mauSo * a.mauSo;
    kq.RutGonPhanSo();
    return kq;
}
PhanSo PhanSo::TinhTich(PhanSo a)
{
    PhanSo kq;
    kq.tuSo = this->tuSo * a.tuSo;
    kq.mauSo = this->mauSo * a.mauSo;
    kq.RutGonPhanSo();
    return kq;
}
PhanSo PhanSo::TinhThuong(PhanSo a)
{
    PhanSo kq;
    kq.tuSo = this->tuSo * a.mauSo;
    kq.mauSo = this->mauSo * a.tuSo;
    return kq;
}
