#include "time.h"

void MENU(Time *a) {
    a = new Time();
    while (true)
    {
        system("cls");
        cout << "1. NHAP THOI GIAN\n";
        cout << "2. XUAT THOI GIAN\n";
        cout << "3. NGAY KE TIEP\n";
        cout << "4. KET THUC\n";
        cout << "\nNHAP VAO LUA CHON CUA BAN: ";
        char luachon;
        cin >> luachon;

        if (luachon == '4') {
            system("cls");
            cout << "CHUONG TRINH KET THUC\n";
            system("pause");
            break;
        }

        else if (luachon == '1') {
            system("cls");
            cout << "NHAP THOI GIAN:\n";
            a->Nhap();
        }

        else if (luachon == '2') {
            if(a->KiemTraDaNhap()) {
                system("cls");
                a->Xuat();
                cout << "\n";
                system("pause");
            }
            else {
                system("cls");
                cout << "DU LIEU CHUA DUOC NHAP! VUI LONG KIEM TRA LAI\n";
                system("pause");
            }
        }

        else if (luachon == '3') {
            if(a->KiemTraDaNhap()) {
                system("cls");
                cout << "NGAY KE TIEP\n";
                Time *temp = new Time;
                a->TimNgayKeTiep().Xuat();
                cout << "\n";
                system("pause");
            }
            else {
                system("cls");
                cout << "DU LIEU CHUA DUOC NHAP! VUI LONG KIEM TRA LAI\n";
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
    Time *a;
    MENU(a);
    return 0;
}