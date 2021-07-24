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
    if (a.tuSo == 0) {
        cout << "KHONG TINH DUOC\n";
        return;
    }
    PhanSo kq;
    kq.tuSo = this->tuSo * a.mauSo;
    kq.mauSo = this->mauSo * a.tuSo;
    kq.RutGonPhanSo();
    return kq;
}

void MENU(PhanSo *a, PhanSo *b)
{
    a = new PhanSo();
    b = new PhanSo();
    while (true)
    {
        system("cls");
        cout << "1. NHAP 2 PHAN SO\n";
        cout << "2. XUAT 2 PHAN SO\n";
        cout << "3. RUT GON 2 PHAN SO\n";
        cout << "4. SO SANH 2 PHAN SO\n";
        cout << "5. TINH TONG\n";
        cout << "6. TINH HIEU\n";
        cout << "7. TINH TICH\n";
        cout << "8. TINH THUONG\n";
        cout << "0. KET THUC\n";
        cout << "\nNHAP VAO LUA CHON CUA BAN: ";

        char luachon;
        cin >> luachon;
        cin.ignore(32767, '\n');

        if (luachon == '0')
        {
            system("cls");
            cout << "CHUONG TRINH KET THUC\n";
            system("pause");
            break;
        }

        switch (luachon)
        {
        case '1':
        {
            system("cls");
            cout << "NHAP VAO PHAN SO THU NHAT\n";
            a->NhapPhanSo();
            system("cls");
            cout << "NHAP VAO PHAN SO THU HAI\n";
            b->NhapPhanSo();
            break;
        }
        case '2':
        {
            system("cls");
            if (!a->KiemTraDaNhap() || !b->KiemTraDaNhap())
            {
                cout << "KHONG TIM THAY DU LIEU CUA HAI PHAN SO!\n";
            }
            else
            {
                cout << "PHAN SO THU NHAT: ";
                a->XuatPhanSo();
                cout << "\n";
                cout << "PHAN SO THU HAI: ";
                b->XuatPhanSo();
                cout << "\n";
            }
            system("pause");
            break;
        }
        case '3':
        {
            system("cls");
            if (!a->KiemTraDaNhap() || !b->KiemTraDaNhap())
            {
                cout << "KHONG TIM THAY DU LIEU CUA HAI PHAN SO!\n";
            }
            else
            {
                cout << "PHAN SO THU NHAT SAU KHI RUT GON: ";
                a->RutGonPhanSo();
                a->XuatPhanSo();
                cout << "\n";
                cout << "PHAN SO THU HAI SAU KHI RUT GON: ";
                b->RutGonPhanSo();
                b->XuatPhanSo();
                cout << "\n";
            }
            system("pause");
            break;
        }
        case '4':
        {
            system("cls");
            if (!a->KiemTraDaNhap() || !b->KiemTraDaNhap())
            {
                cout << "KHONG TIM THAY DU LIEU CUA HAI PHAN SO!";
            }
            else
            {
                cout << "PHAN SO LON HON LA: ";
                if (a->SoSanhPhanSo(b))
                {
                    a->XuatPhanSo();
                }
                else
                {
                    b->XuatPhanSo();
                }
            }
            cout << endl;
            system("pause");
            break;
        }
        case '5':
        {
            system("cls");
            if (!a->KiemTraDaNhap() || !b->KiemTraDaNhap())
            {
                cout << "KHONG TIM THAY DU LIEU CUA HAI PHAN SO";
            }
            else
            {
                PhanSo *kq = new PhanSo();
                *kq = a->TinhTong(*b);
                cout << "KET QUA: ";
                kq->XuatPhanSo();
            }
            cout << "\n";
            system("pause");
            break;
        }
        case '6':
        {
            system("cls");
            if (!a->KiemTraDaNhap() || !b->KiemTraDaNhap())
            {
                cout << "KHONG TIM THAY DU LIEU CUA HAI PHAN SO";
            }
            else
            {
                PhanSo *kq = new PhanSo();
                *kq = a->TinhHieu(*b);
                cout << "KET QUA: ";
                kq->XuatPhanSo();
                delete kq;
            }
            cout << "\n";
            system("pause");
            break;
        }
        case '7':
        {
            system("cls");
            if (!a->KiemTraDaNhap() || !b->KiemTraDaNhap())
            {
                cout << "KHONG TIM THAY DU LIEU CUA HAI PHAN SO";
            }
            else
            {
                if (b->getTuSo() == 0 || a->getTuSo() == 0) {
                    cout << 0;
                }
                else {
                    PhanSo *kq = new PhanSo();
                    *kq = a->TinhTich(*b);
                    cout << "KET QUA: ";
                    kq->XuatPhanSo();
                    delete kq;
                }
            }
            cout << "\n";
            system("pause");
            break;
        }
        case '8':
        {
            system("cls");
            if (!a->KiemTraDaNhap() || !b->KiemTraDaNhap())
            {
                cout << "KHONG TIM THAY DU LIEU CUA HAI PHAN SO";
            }
            else
            {
                if (b->getTuSo() == 0) {
                    cout << "KHONG THE CHIA 2 PHAN SO";
                }
                else {
                    PhanSo *kq = new PhanSo();
                    *kq = a->TinhThuong(*b);
                    cout << "KET QUA: ";
                    kq->XuatPhanSo();
                    delete kq;
                }
                
            }
            cout << "\n";
            system("pause");
            break;
        }
        default:
            {
                system("cls");
                cout << "LUA CHON CUA BAN KHONG HOP LE! VUI LONG THU LAI\n";
                system("pause");
            }
        }
    }
    delete a;
    delete b;
}
int main()
{
    PhanSo *a, *b;
    MENU(a, b);
    return 0;
}