#include "polynomial.h"

void Menu(vector<Polynomial*> list) {
    while (1)
    {
        system("cls");
        cout << "1. THEM VAO 1 DA THUC (Polynomial)\n";
        cout << "2. XUAT RA DANH SACH DA THUC DA NHAP (Polynomial)\n";
        cout << "3. TINH TOAN VOI 2 DA THUC\n";
        cout << "4. SO SANH 2 DA THUC\n";
        cout << "0. THOAT\n";
        cout << "\nLUA CHON: ";
        char lc;
        cin >> lc;
        cin.ignore();
        system("cls");

        if (lc == '0') break;
        else if (lc == '1') {
            int x;
            do
            {
                cout << "NHAP BAC DA THUC: ";
                cin >> x;
                if (x <= 0) cout << "BAC CUA DA THUC KHONG HOP LE\n";
            } while (x <= 0);
            Polynomial *temp = new Polynomial(x);
            cin >> *temp;
            list.push_back(temp);
        }
        else if (lc == '2') {
            if (list.size() > 0) {
                for (int i = 0; i < list.size(); i++)
                {
                    cout << "DA THUC THU " << i + 1 << ": " << *list[i] << endl;
                }
            }
            else {
                cout << "KHONG CO DU LIEU\n";
            }
        }
        else if (lc == '3') {
            int x, y;
            do
            {
                cout << "NHAP VI TRI PHAN TU 1 (INDEX): ";
                cin >> x;
                cout << "NHAP VI TRI PHAN TU 2 (INDEX): ";
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
                cout << "3. NHAN (*)\n";
                cout << "4. CHIA (/)\n";
                cout << "5. TANG (++) VA GIAM (--)\n";
                cout << "6. TAI GIA GIA x\n";
                cout << "0. THOAT\n";
                cout << "\nLUA CHON: ";
                char lc1;
                cin >> lc1;
                cin.ignore();
                system("cls");

                if (lc1 == '0') break;
                else if (lc1 == '1') {
                    if (list.size() >= 2) {
                        cout << "KET QUA: " << *list[x] + *list[y] << endl;
                    }
                    else cout << "KHONG CO DU DU LIEU\n";
                }
                else if (lc1 == '2') {
                    if (list.size() >= 2) {
                        cout << "KET QUA: " << *list[x] - *list[y] << endl;
                    }
                    else cout << "KHONG CO DU DU LIEU\n";
                } 
                else if (lc1 == '3') {
                    if (list.size() >= 2) {
                        cout << "KET QUA: " << *list[x] * *list[y] << endl;
                    }
                    else cout << "KHONG CO DU DU LIEU\n";
                } 
                else if (lc1 == '4') {
                    if (list.size() >= 2) {
                        cout << "KET QUA: " << *list[x] / *list[y] << endl;
                    }
                    else cout << "KHONG CO DU DU LIEU\n";
                }
                else if (lc1 == '5') {
                    ++*list[x];
                    --*list[y];
                    cout << "TANG (++) DA THUC 1: " << *list.at(x) << endl;
                    cout << "GIAM (--) DA THUC 2: " << *list.at(y) << endl;
                }
                else if (lc1 == '6') {
                    double x;
                    cout << "NHAP GIA TRI x: ";
                    cin >> x;
                    for (int i = 0; i < list.size(); i++)
                    {
                        cout << "DA THUC " << i + 1 << " TAI x = " << x << ": " << list.at(i)->Evalue(x) << endl;
                    }
                    
                }
                else  cout << "LUA CHON KHONG HOP LE\n" << endl;
                system("pause");
        }
        }
        else if (lc == '4') {
            if (list.size() >= 2) {
                int x, y;
                do
                {
                    cout << "NHAP VI TRI PHAN TU 1 (INDEX): ";
                    cin >> x;
                    cout << "NHAP VI TRI PHAN TU 2 (INDEX): ";
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
                    cout << "3. LON HON XET BAC (>)\n";
                    cout << "4. NHO HON XET BAC (<)\n";
                    cout << "0. THOAT\n";
                    cout << "\nLUA CHON: ";
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
                    else  cout << "LUA CHON KHONG HOP LE\n" << endl;
                    system("pause");
                }
            }
        }
        else {
            cout << "LUA CHON KHONG HOP LE\n";
        }
        system("pause");
    }
}

int main() {
    vector<Polynomial *> list;
    Menu(list);
    return 0;
}