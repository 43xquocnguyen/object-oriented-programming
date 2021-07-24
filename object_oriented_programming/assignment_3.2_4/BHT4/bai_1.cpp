#include "time.h"
#include <vector>

void MENU(vector<Time *> list) {
    while (true)
    {
        system("cls");
        cout << "1. NHAP THEM 1 THOI GIAN\n";
        cout << "2. XUAT DANH SACH THOI GIAN\n";
        cout << "3. CONG 2 THOI GIAN\n";
        cout << "4. TRU 2 THOI GIAN\n";
        cout << "0. KET THUC\n";
        cout << "\nNHAP VAO LUA CHON CUA BAN: ";
        char luachon;
        cin >> luachon;

        if (luachon == '0') {
            system("cls");
            cout << "CHUONG TRINH KET THUC\n";
            system("pause");
            break;
        }

        else if (luachon == '1') {
            system("cls");
            Time *temp = new Time;
            temp->Input();
            list.push_back(temp);
        }

        else if (luachon == '2') {
            system("cls");
            if(list.size() >= 1) {
                int size = list.size();
                for (int i = 0; i < size; i++)
                {
                    cout << "THOI GIAN " << i + 1 << ": ";
                    list[i]->Output();
                    cout << endl;
                }
            }
            else {
                cout << "DU LIEU CHUA DUOC NHAP! VUI LONG KIEM TRA LAI\n";
            }
            system("pause");
        }
        else if (luachon == '3') {
            system("cls");
            if(list.size() >= 2) {
                int a, b;
                do
                {
                    cout << "NHAP VAO INDEX THOI GIAN 1: ";
                    cin >> a;
                    cout << "NHAP VAO INDEX THOI GIAN 2: ";
                    cin >> b;
                    if (a == b || a < 0 || a >= list.size() || b < 0 || b >= list.size())
                        cout << "INDEX CUA 2 THOI GIAN KHONG TON TAI\n";
                } while (a == b || a < 0 || a >= list.size() || b < 0 || b >= list.size());
                Time result = list[a]->Add2Time(*list[b]);
                cout << "\nTHOI GIAN TONG LA: ";
                result.Output();
                cout << endl;
            }
            else {
                cout << "DU LIEU CHUA DUOC NHAP! VUI LONG KIEM TRA LAI\n";
            }
            system("pause");
        }
        else if (luachon == '4') {
            system("cls");
            if(list.size() >= 2) {
                int a, b;
                do
                {
                    cout << "NHAP VAO INDEX THOI GIAN 1: ";
                    cin >> a;
                    cout << "NHAP VAO INDEX THOI GIAN 2: ";
                    cin >> b;
                    if (a == b || a < 0 || a >= list.size() || b < 0 || b >= list.size())
                        cout << "INDEX CUA 2 THOI GIAN KHONG TON TAI\n";
                } while (a == b || a < 0 || a >= list.size() || b < 0 || b >= list.size());
                Time result = list[a]->Sub2Time(*list[b]);
                cout << "\nTHOI GIAN HIEU LA: ";
                result.Output();
                cout << endl;
            }
            else {
                cout << "DU LIEU CHUA DUOC NHAP! VUI LONG KIEM TRA LAI\n";
            }
            system("pause");
        }
        else {
            system("cls");
            cout << "LUA CHON KHONG HOP LE! THU LAI\n";
            system("pause");
        }
    }
}
int main() {
    vector<Time *> list;
    MENU(list);
    return 0;
}