#include "list_sach.h"

ListSach::ListSach()
{
    this->soSGK = this->soTC = this->soTT = 0;
}
ListSach::~ListSach()
{
}

void ListSach::Input() {
    while (true)
    {
        system("cls");
        cout << "1. SACH GIAO KHOA\n";
        cout << "2. TAP CHI\n";
        cout << "3. TIEU THUYET\n";
        cout << "0. THOAT\n\n";
        cout << "LUA CHON:";
        char x;
        cin >> x;
        cin.ignore();
        system("cls");

        if (x == '0') break;
        else if (x == '1') {
            Sach *t = new SachGiaoKhoa;
            cout << "NHAP THONG TIN SACH GIAO KHOA\n";
            t->Input();
            this->list.push_back(t);
            this->soSGK++;
        }
        else if (x == '2') {
            Sach *t = new TapChi;
            cout << "NHAP THONG TIN TAP CHI\n";
            t->Input();
            this->list.push_back(t);
            this->soTC++;
        }
        else if (x == '3') {
            Sach *t = new TieuThuyet;
            cout << "NHAP THONG TIN TIEU THUYET\n";
            t->Input();
            this->list.push_back(t);
            this->soTT++;
        }
        else
            cout << "LUA CHON KHONG HOP LE\n";
        system("pause");
    }
}
void ListSach::Output() {
    int j;
    if (this->soSGK) {
        j = 1;
        cout << "\t\t\t\t\tDANH SACH SACH GK\n\n";
        this->BangSGK();
        cout << setfill(' ');
        for (int i = 0; i < list.size(); i++)
        {
            if (!list[i]->GetterCheck()) {
                cout << setw(5) << left << j++;
                list[i]->Output();
                cout << endl;
            }
        }
        cout << "\n\n\n";
    }
    else cout << "\t\t\t\t\tKHONG CO CUON TIEU THUYET NAO!\n\n";

    if (this->soTC) {
        j = 1;
        cout << "\t\t\t\t\tDANH SACH TAP CHI\n\n";
        this->BangTC();
        cout << setfill(' ');
        for (int i = 0; i < list.size(); i++)
        {
            if (list[i]->GetterCheck() == 1) {
                cout << setw(5) << left << j++;
                list[i]->Output();
                cout << endl;
            }
        }
        cout << "\n\n\n";
    }
    else cout << "\t\t\t\t\tKHONG CO CUON TIEU THUYET NAO!\n\n";

    if (this->soTT) {
        j = 1;
        cout << "\t\t\t\t\tDANH SACH TIEU THUYET\n\n";
        this->BangTT();
        cout << setfill(' ');
        for (int i = 0; i < list.size(); i++)
        {
            if (list[i]->GetterCheck() == 2) {
                cout << setw(5) << left << j++;
                list[i]->Output();
                cout << endl;
            }
        }
        cout << "\n\n";
        cout << "\t\t\t\t\t\tEND!\n\n";
    }
    else cout << "\t\t\t\t\tKHONG CO CUON TIEU THUYET NAO!\n\n\n";


}
