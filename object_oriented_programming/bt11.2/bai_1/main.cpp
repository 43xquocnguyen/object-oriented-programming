#include "list_sach.h"

void MENU(ListSach a) {
    while (true)
    {
        system("cls");
        cout << "1. THEM SACH\n";
        cout << "2. XUAT DANH SACH SACH\n";
        cout << "0. THOAT\n\n";
        cout << "LUA CHON: ";
        char x;
        cin >> x;
        cin.ignore();
        system("cls");

        if (x == '0') break;
        else if (x == '1') {
            a.Input();
        }
        else if (x == '2') {
            a.Output();
        }
        else
            cout << "LUA CHON KHONG HOP LE\n";
        system("pause");
    }
    
}

int main() {
    ListSach a;
    MENU(a);
    return 0;
}