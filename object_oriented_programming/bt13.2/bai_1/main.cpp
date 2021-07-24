#include "thoi_gian.h"

void Menu(vector<Time*> list) {
    while (1)
    {
        system("cls");
        cout << "1. THEM THOI GIAN\n";
        cout << "2. XUAT THOI GIAN\n";
        cout << "3. CONG TRU 2 KHOANG THOI GIAN\n";
        cout << "4. SO SANH 2 KHOANG THOI GIAN\n";
        cout << "0. THOAT\n";
        cout << "\nLUA CHON: ";
        char lc;
        cin >> lc;
        cin.ignore();
        system("cls");

        if (lc == '0') break;
        else if (lc == '1') {
            cout << "KHONG GIOI HAN SO GIO - PHUT - GIAY TOI DA\n";
            Time *temp = new Time;
            cin >> *temp;
            list.push_back(temp);
        }
        else if (lc == '2') {
            for (int i = 0; i < list.size(); i++)
            {
                cout << "THOI GIAN " << i + 1 << ": " << *list.at(i) << endl;
            }
        }
        else if (lc == '3') {
            if (list.size() >= 2) {
                int x, y;
                do
                {
                    cout << "NHAP VI TRI PHAN TU 1: ";
                    cin >> x;
                    cout << "NHAP VI TRI PHAN TU 2: ";
                    cin >> y;
                    if (x == y || x < 0 || x >= list.size() || y < 0 || y >= list.size()) {
                        cout << "KHONG TON TAI PHAN TU NAY\n";
                    }
                } while (x == y || x < 0 || x >= list.size() || y < 0 || y >= list.size());
                
                while (true)
                {
                    system("cls");
                    cout << "1. CONG (+)\n";
                    cout << "2. TRU (-)\n";
                    cout << "0. THOAT\n";
                    cout << "\nLUA CHON: ";
                    char lc1;
                    cin >> lc1;
                    cin.ignore();
                    system("cls");

                    if (lc1 == '0') break;
                    else if (lc1 == '1') cout << "KET QUA: " << *list.at(x) + *list.at(y) << endl;
                    else if (lc1 == '2') cout << "KET QUA: " << *list.at(x) - *list.at(y) << endl;
                    else cout << "LUA CHON KHONG HOP LE\n" << endl;
                    system("pause");
                }
            }
            else {
                cout << "KHONG CO DU LIEU DE THUC HIEN! VUI LONG NHAP THEM\n";;
            }
        }
        else if (lc == '4') {
            if (list.size() >= 2) {
                int x, y;
                do
                {
                    cout << "NHAP VI TRI PHAN TU 1: ";
                    cin >> x;
                    cout << "NHAP VI TRI PHAN TU 2: ";
                    cin >> y;
                    if (x == y || x < 0 || x >= list.size() || y < 0 || y >= list.size()) {
                        cout << "KHONG TON TAI PHAN TU NAY\n";
                    }
                } while (x == y || x < 0 || x >= list.size() || y < 0 || y >= list.size());

                while (true)
                {
                    system("cls");
                    cout << "1. BANG NHAU (==)\n";
                    cout << "2. KHAC NHAU (!=)\n";
                    cout << "3. LON HON (>)\n";
                    cout << "4. NHO HON (<)\n";
                    cout << "0. THOAT\n";
                    cout << "\nCHON CACH BAN MUON SO SANH: ";
                    char lc1;
                    cin >> lc1;
                    cin.ignore();
                    system("cls");

                    if (lc1 == '0') break;
                    else if (lc1 == '1') {
                        if (*list.at(x) == *list.at(y)) {
                            cout << *list.at(x) << " BANG " << *list.at(y) << endl;
                        }
                        else {
                            cout << *list.at(x) << " KHONG BANG " << *list.at(y) << endl;
                        }
                    }
                    else if (lc1 == '2') {
                        if (*list.at(x) != *list.at(y)) {
                            cout << *list.at(x) << " KHAC " << *list.at(y) << endl;
                        }
                        else {
                            cout << *list.at(x) << " BANG " << *list.at(y) << endl;
                        }
                    }
                    else if (lc1 == '3') {
                        if (*list.at(x) > *list.at(y)) {
                            cout << *list.at(x) << " LON HON " << *list.at(y) << endl;
                        }
                        else {
                            cout << *list.at(x) << " KHONG LON HON " << *list.at(y) << endl;
                        }
                    }
                    else if (lc1 == '4') {
                        if (*list.at(x) <= *list.at(y)) {
                            cout << *list.at(x) << " NHO HON " << *list.at(y) << endl;
                        }
                        else {
                            cout << *list.at(x) << " KHONG NHO HON " << *list.at(y) << endl;
                        }
                    }
                    else {
                        cout << "LUA CHON KHONG HOP LE\n";
                    }
                    system("pause");
                }
            }
            else {
                cout << "KHONG CO DU LIEU DE THUC HIEN! VUI LONG NHAP THEM\n";
            }
        }
        else {
            cout << "LUA CHON KHONG HOP LE\n";
        }
        system("pause");
    }
}

int main() {
    vector<Time *> list;
    Menu(list);
    return 0;
}

