#include <iostream>
#include <string>
using namespace std;

class PhanSo
{
private:
    int tuSo, mauSo;
    bool daNhap;
    void RutGonPhanSo()
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
        this->tuSo /= n;
        this->mauSo /= n;
    }

public:
    PhanSo();
    PhanSo(int, int);
    ~PhanSo();

    void NhapPhanSo();
    void XuatPhanSo();
    float GiaTriPhanSo();

    PhanSo TinhTong(PhanSo);
    PhanSo TinhHieu(PhanSo);
    PhanSo TinhTich(PhanSo);
    PhanSo *TinhThuong(PhanSo);
};

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
PhanSo::~PhanSo() { 

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
void PhanSo::XuatPhanSo() {
    if (this->tuSo == 0) {
        cout << 0;
    }
    else if (this->mauSo == 1) {
        cout << this->tuSo;
    }
    else {
        cout << this->tuSo << "/" << this->mauSo;
    }
}
float PhanSo::GiaTriPhanSo() {
    return (float)this->tuSo / this->mauSo;
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
PhanSo *PhanSo::TinhThuong(PhanSo a)
{
    if (a.tuSo == 0) {
        return NULL;
    }
    PhanSo *kq = new PhanSo;
    kq->tuSo = this->tuSo * a.mauSo;
    kq->mauSo = this->mauSo * a.tuSo;
    kq->RutGonPhanSo();
    return kq;
}

void Program(PhanSo *a, PhanSo *b)
{
    a = new PhanSo();
    b = new PhanSo();
nhap:
    system("cls");
    cout << "NHAP PHAN SO THU NHAT\n";
    a->NhapPhanSo();
    cout << "NHAP PHAN SO THU HAI\n";
    b->NhapPhanSo();
    system("cls");

    while (true)
    {
        system("cls");
        cout << "1. TINH TOAN VOI 2 PHAN SO\n";
        cout << "2. GIA TRI THUC TE CUA 2 PHAN SO\n";
        cout << "3. NHAP LAI 2 PHAN SO\n";
        cout << "0. KET THUC\n";
        cout << "\nNHAP VAO LUA CHON CUA BAN: ";
        char lc;
        cin >> lc;
        cin.ignore();

        if (lc == '0') {
            system("cls");
            cout << "CHUONG TRINH KET THUC\n";
            break;
            system("pause");
        }
        else if (lc == '1') {
            while (true)
            {
                system("cls");
                cout << "1. TINH TONG\n";
                cout << "2. TINH HIEU\n";
                cout << "3. TINH TICH\n";
                cout << "4. TINH THUONG\n";
                cout << "0. THOAT\n";
                cout << "\nNHAP VAO LUA CHON CUA BAN: ";
                char lc1;
                cin >> lc1;
                cin.ignore();

                if (lc1 == '0') {
                    break;
                }
                else if (lc1 == '1')
                {
                    system("cls");
                    cout << "TONG 2 PHAN SO LA: ";
                    PhanSo kq = a->TinhTong(*b);
                    kq.XuatPhanSo();
                    cout << endl;
                    system("pause");
                }
                else if (lc1 == '2')
                {
                    system("cls");
                    cout << "HIEU 2 PHAN SO LA: ";
                    PhanSo kq = a->TinhHieu(*b);
                    kq.XuatPhanSo();
                    cout << endl;
                    system("pause");
                }
                else if (lc1 == '3')
                {
                    system("cls");
                    cout << "TICH 2 PHAN SO LA: ";
                    PhanSo kq = a->TinhTich(*b);
                    kq.XuatPhanSo();
                    cout << endl;
                    system("pause");
                }
                else if (lc1 == '4')
                {
                    system("cls");
                    PhanSo *kq = a->TinhThuong(*b);
                    if (!kq) {
                        cout << "KHONG THE TINH DUOC";
                    }
                    else {
                        cout << "THUONG 2 PHAN SO LA: ";
                        kq->XuatPhanSo();
                    }
                    cout << endl;
                    system("pause");
                }
                else {
                    system("cls");
                    cout << "LUA CHON KHONG HOP LE\n";
                    system("pause");
                }
            }
        }
        else if (lc == '2') {
            system("cls");
            cout << "PHAN SO THU NHAT: " << a->GiaTriPhanSo() << endl;
            cout << "PHAN SO THU HAI: " << b->GiaTriPhanSo() << endl;
            system("pause");
        }
        else if (lc == '3') {
            goto nhap;
        }
        else {
            system("cls");
            cout << "LUA CHON KHONG HOP LE\nKIEM TRA LAI\n";
            system("pause");
        }
    }
    delete a;
    delete b;
}
int main()
{
    PhanSo *a, *b;
    Program(a, b);
    return 0;
}