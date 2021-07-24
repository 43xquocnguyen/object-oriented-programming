#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class HocSinh
{
private:
    string hoTen;
    double diemToan, diemVan;
    bool daNhap;
public:
    HocSinh();
    ~HocSinh();
    float TinhDiemTrungBinh();
    void Nhap();
    void Xuat();
    bool KiemTraDaNhap();
};

HocSinh::HocSinh() {
    this->daNhap = false;
    this->hoTen = "";
    this->diemVan = 0;
    this->diemToan = 0;
}

HocSinh::~HocSinh() {

}

float HocSinh::TinhDiemTrungBinh() {
    return (this->diemToan + this->diemVan) / 2;
}

void HocSinh::Nhap() {
    cout << "NHAP TEN HOC SINH: ";
    getline(cin, this->hoTen);

    do
    {
        cout << "NHAP DIEM TOAN: ";
        cin >> this->diemToan;
        if (this->diemToan < 0 || this->diemToan > 10) {
            cout << "DIEM TOAN KHONG HOP LE\n";
        }
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            this->diemToan = -1;
        }
    } while (this->diemToan < 0 || this->diemToan > 10);

    do
    {
        cout << "NHAP DIEM VAN: ";
        cin >> this->diemVan;
        if (this->diemVan < 0 || this->diemVan > 10) {
            cout << "DIEM VAN KHONG HOP LE\n";
        }
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            this->diemVan = -1;
        }
    } while (this->diemVan < 0 || this->diemVan > 10);

    this->daNhap = true;
}

void HocSinh::Xuat() {
    cout << setfill(' ');
    cout << setw(30) << left << "HO VA TEN";
    cout << setw(15) << left << "DIEM TOAN";
    cout << setw(15) << left << "DIEM VAN";
    cout << setw(15) << left << "DIEM TRUNG BINH" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;

    cout << setfill(' ');
    cout << setw(30) << left << this->hoTen;
    cout << setw(15) << left << (size_t)this->diemToan;
    cout << setw(15) << left << (size_t)this->diemVan;
    cout << setw(15) << left << (size_t)TinhDiemTrungBinh() << endl;
}

bool HocSinh::KiemTraDaNhap() {
    return this->daNhap;
}

void MENU(HocSinh *a) {
    a = new HocSinh();
    while (true)
    {
        system("cls");
        cout << "1. NHAP THONG TIN CUA HOC SINH\n";
        cout << "2. XUAT THONG TIN CUA HOC SINH\n";
        cout << "3. KET THUC\n";
        cout << "\nNHAP VAO LUA CHON CUA BAN: ";
        char luachon;
        cin >> luachon;
        cin.ignore(10000, '\n');

        if (luachon == '3') {
            system("cls");
            cout << "CHUONG TRINH KET THUC\n";
            system("pause");
            break;
        }

        else if (luachon == '1') {
            system("cls");
            cout << "NHAP THONG TIN HOC SINH\n";
            a->Nhap();
            cout << "\n";
        }

        else if (luachon == '2') {
            if (a->KiemTraDaNhap()) {
                system("cls");
                cout << "\t\t\t\tTHONG TIN HOC SINH\n\n\n";
                a->Xuat();
                cout << "\n";
                system("pause");
            }
            else {
                system("cls");
                cout << "CHUA CO DU LIEU! VUI LONG KIEM TRA\n";
                system("pause");
            }
        }

        else {
            cout << "LUA CHON KHONG HOP LE\n! THU LAI";
        }
    }
    delete a;
}
int main() {
    HocSinh *a;
    MENU(a);
    return 0;
}