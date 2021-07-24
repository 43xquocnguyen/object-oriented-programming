#include <iostream>
#include <cmath>
using namespace std;

class SoPhuc
{
private:
    int thuc, ao;
public:
    SoPhuc();
    SoPhuc(int, int);
    ~SoPhuc();

    void Nhap();
    void Xuat();

    float GiaTriTuyetDoi();

    SoPhuc TinhTong(SoPhuc);
    SoPhuc TinhHieu(SoPhuc);
    SoPhuc TinhTich(SoPhuc);
    SoPhuc TinhThuong(SoPhuc);
};

SoPhuc::SoPhuc()
{
    this->thuc = 0;
    this->ao = 0;
}
SoPhuc::SoPhuc(int thuc, int ao) {
    this->thuc = thuc;
    this->ao = ao;
}
SoPhuc::~SoPhuc()
{
}

void SoPhuc::Nhap() {
    cout << "NHAP PHAN THUC: ";
    cin >> this->thuc;
    cout << "NHAP PHAN AO: ";
    cin >> this->ao;
}
void SoPhuc::Xuat() {
    if (this->thuc == 0) {
        if (this->ao == 0) {
            cout << 0;
        } 
        else {
            cout << this->ao << "i";
        }
    }
    else if (this->ao == 1) {
        cout << this->thuc << " + i";
    }
    else if (this->ao == 0) {
        cout << this->thuc;
    }
    else if (this->ao < 0) {
        cout << this->thuc << " - " << abs(this->ao) << "i";
    }
    else {
        cout << this->thuc << " + " << this->ao << "i";
    }
}

float SoPhuc::GiaTriTuyetDoi() {
    return sqrt(pow(this->thuc, 2) + pow(this->ao, 2));
}
SoPhuc SoPhuc::TinhTong(SoPhuc a) {
    SoPhuc kq;
    kq.thuc = this->thuc + a.thuc;
    kq.ao = this->ao + a.ao;
    return kq;
}
SoPhuc SoPhuc::TinhHieu(SoPhuc a) {
    SoPhuc kq;
    kq.thuc = this->thuc - a.thuc;
    kq.ao = this->ao - a.ao;
    return kq;
}
SoPhuc SoPhuc::TinhTich(SoPhuc a) {
    SoPhuc kq;
    kq.thuc = this->thuc * a.thuc - this->ao * a.ao;
    kq.ao = this->thuc * a.ao + this->ao * a.thuc;
    return kq;
}
SoPhuc SoPhuc::TinhThuong(SoPhuc a) {
    SoPhuc kq;
    kq.thuc = (this->thuc * a.thuc + this->ao * a.ao) / (a.thuc * a.thuc + a.ao * a.ao);
    kq.ao = (a.thuc * this->ao - this->thuc * a.ao) / (a.thuc * a.thuc + a.ao * a.ao);
    return kq;
}

void Menu(SoPhuc *a, SoPhuc *b) {

    a = new SoPhuc;
    b = new SoPhuc;
nhap:
    system("cls");
    cout << "NHAP SO PHUC A\n";
    a->Nhap();
    a->Xuat();
    cout << "\nNHAP SO PHUC B\n";
    b->Nhap();
    b->Xuat();

    while (true)
    {
        system("cls");
        cout << "1. TINH TOAN VOI 2 SO PHUC\n";
        cout << "2. GIA TRI TUYET DOI CUA 2 SO PHUC\n";
        cout << "3. NHAP LAI 2 SO PHUC\n";
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
                    cout << "TONG 2 SO PHUC LA: ";
                    SoPhuc kq = a->TinhTong(*b);
                    kq.Xuat();
                    cout << endl;
                    system("pause");
                }
                else if (lc1 == '2')
                {
                    system("cls");
                    cout << "HIEU 2 SO PHUC LA: ";
                    SoPhuc kq = a->TinhHieu(*b);
                    kq.Xuat();
                    cout << endl;
                    system("pause");
                }
                else if (lc1 == '3')
                {
                    system("cls");
                    cout << "TICH 2 SO PHUC LA: ";
                    SoPhuc kq = a->TinhTich(*b);
                    kq.Xuat();
                    cout << endl;
                    system("pause");
                }
                else if (lc1 == '4')
                {
                    system("cls");
                    SoPhuc kq = a->TinhThuong(*b);
                    cout << "THUONG 2 SO PHUC LA: ";
                    kq.Xuat();
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
            cout << "PHAN SO THU NHAT: " << a->GiaTriTuyetDoi() << endl;
            cout << "PHAN SO THU HAI: " << b->GiaTriTuyetDoi() << endl;
            system("pause");
        }
        else if (lc == '3') {
            while (true)
            {
                system("cls");
                cout << "1. NHAP A\n";
                cout << "2. NHAP B\n";
                cout << "3. NHAP CA 2\n";
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
                    cout << "NHAP SO PHUC A: ";
                    a->Nhap();
                    cout << endl;
                    system("pause");
                }
                else if (lc1 == '2')
                {
                    system("cls");
                    cout << "NHAP SO PHUC B: ";
                    b->Nhap();
                    cout << endl;
                    system("pause");
                }
                else if (lc1 == '3')
                {
                    goto nhap;
                }
                else {
                    system("cls");
                    cout << "LUA CHON KHONG HOP LE\n";
                    system("pause");
                }
            }
        }
        else {
            system("cls");
            cout << "LUA CHON KHONG HOP LE\n";
            system("pause");
        }
    }
    delete a;
    delete b;
}

int main() {
    SoPhuc *a, *b;
    Menu(a, b);
    return 0;
}