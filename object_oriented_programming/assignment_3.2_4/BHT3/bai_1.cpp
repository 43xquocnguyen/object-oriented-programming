#include "point.h"
#include <vector>

void Program(vector<Point*> list)
{
    while (true)
    {
        system("cls");
        cout << "1. THEM 1 DIEM\n";
        cout << "2. XUAT DANH SACH DIEM\n";
        cout << "3. XEM THANH PHAN DU LIEU 1 DIEM\n";
        cout << "4. THAY DOI THANH PHAN DU LIEU 1 DIEM\n";
        cout << "5. TINH TIEN DIEM THEO VECTOR(a,b) VA XUAT\n";
        cout << "6. HAI DIEM CO KHOANG CACH NHO NHAT\n";
        cout << "7. HAI DIEM CO KHOANG CACH LON NHAT\n";
        cout << "0. KET THUC\n";
        cout << "\nNHAP VAO LUA CHON CUA BAN: ";
        char lc;
        cin >> lc;
        cin.ignore();
        system("cls");

        if (lc == '0') {
            cout << "CHUONG TRINH KET THUC\n";
            break;
        }
        else if (lc == '1') {
            Point *a = new Point;
            a->Input();
            list.push_back(a);
        }
        else if (lc == '2') {
            if (list.size() > 0) {
                int size = list.size();
                for (int i = 0; i < size; i++)
                {
                    cout << (char)(i + 65);
                    list.at(i)->Output();
                    if (i < size - 1) {
                        cout << " - ";
                    }
                }
                cout << endl;
            }
            else cout << "KHONG CO DU LIEU\n";
        }
        else if (lc == '3') {
            if (list.size() >= 1) {
                int x;
                do
                {
                    cout << "NHAP VI TRI DIEM CAN XEM DU LIEU: ";
                    cin >> x;
                    if (x < 0 || x >= list.size())
                        cout << "DIEM KHONG TON TAI\n";
                } while (x < 0 || x >= list.size());
                while (true)
                {
                    system("cls");
                    cout << "1. HOANH DO\n";
                    cout << "2. TUNG DO\n";
                    cout << "0. THOAT\n";
                    cout << "\nLUA CHON: ";
                    char lcx;
                    cin >> lcx;
                    cin.ignore();
                    system("cls");

                    if (lcx == '0') break;
                    else if (lcx == '1') {
                        cout << "HOANH DO: " << list.at(x)->GetterX() << endl;
                        break;
                    }
                    else if (lcx == '2') {
                        cout << "TUNG DO: " << list.at(x)->GetterY() << endl;
                        break;
                    }
                    else {
                        cout << "LUA CHON KHONG HOP LE\n" << endl;
                    }
                    system("pause");
                }
            }
            else {
                cout << "KHONG CO BO DU LIEU\n";
            }
        }
        else if (lc == '4') {
            if (list.size() > 0) {
                int x;
                float value;
                do
                {
                    cout << "NHAP VI TRI DIEM CAN THAY DOI: ";
                    cin >> x;
                    cout << "NHAP GIA TRI: ";
                    cin >> value;
                    if (x < 0 || x >= list.size())
                        cout << "DIEM KHONG TON TAI\n";
                } while (x < 0 || x >= list.size());
                while (true)
                {
                    
                    system("cls");
                    cout << "1. HOANH DO\n";
                    cout << "2. TUNG DO\n";
                    cout << "0. THOAT\n";
                    cout << "\nLUA CHON: ";
                    char lcx;
                    cin >> lcx;
                    cin.ignore();
                    system("cls");

                    if (lcx == '0')
                        break;
                    else if (lcx == '1') {
                        list.at(x)->SetterX(value);
                        cout << "DA THAY DOI\n" << endl;
                        break;
                    }
                    else if (lcx == '2') {
                        list.at(x)->SetterY(value);
                        cout << "DA THAY DOI\n" << endl;
                        break;
                    }
                    else {
                        cout << "LUA CHON KHONG HOP LE\n" << endl;
                        system("pause");
                    }
                }
            }
            else {
                cout << "KHONG CO BO DU LIEU\n";
            }
        }
        else if (lc == '5') {
            if (list.size() >= 1) {
                float x, y;
                cout << "NHAP VECTOR(a, b) CAN TINH TIEN\n";
                cout << "NHAP a: ";
                cin >> x;
                cout << "NHAP b: ";
                cin >> y;
                int n = list.size();
                for (int i = 0; i < n; i++)
                {
                    list.at(i)->Trans(x, y);
                }
                system("cls");
                cout << "CAC DIEM SAU KHI TINH TIEN LA\n";
                for (int i = 0; i < n; i++)
                {
                    cout << (char)(i + 65);
                    list.at(i)->Output();
                    if (i < n - 1) {
                        cout << " - ";
                    }
                }
                cout << endl;
            }
            else {
                cout << "KHONG CO BO DU LIEU\n";
            }
        }
        else if (lc == '6') {
            if (list.size() >= 1) {
                int size = list.size();
                float max = list.at(0)->CalcLenght(*list.at(1));
                int vti = 0, vtj = 1;

                for (int i = 0; i < size - 1; i++)
                {
                    for (int j = i + 1; j < size; j++)
                    {
                        if (max < list.at(i)->CalcLenght(*list.at(j))) {
                            max = list.at(i)->CalcLenght(*list.at(j));
                            vti = i;
                            vtj = j;
                        }
                    }
                }

                cout << "HAI DIEM KHOANG CACH LON NHAT LA: ";
                cout << (char)(vti + 65);
                list.at(vti)->Output();
                cout << " - " << (char)(vtj + 65);
                list.at(vtj)->Output();
                cout << endl;
            }
            else {
                cout << "KHONG CO BO DU LIEU\n";
            }
        }
        else if (lc == '7') {
            if (list.size() >= 1) {
                int size = list.size();
                float min = list.at(0)->CalcLenght(*list.at(1));
                int vti = 0, vtj = 1;

                for (int i = 0; i < size - 1; i++)
                {
                    for (int j = i + 1; j < size; j++)
                    {
                        if (min > list.at(i)->CalcLenght(*list.at(j))) {
                            min = list.at(i)->CalcLenght(*list.at(j));
                            vti = i;
                            vtj = j;
                        }
                    }
                }
                cout << "HAI DIEM KHOANG CACH NHO NHAT LA: ";
                cout << (char)(vti + 65);
                list.at(vti)->Output();
                cout << " - " << (char)(vtj + 65);
                list.at(vtj)->Output();
                cout << endl;
            }
            else {
                cout << "KHONG CO BO DU LIEU\n";
            }
            
        }
        else {
            cout << "LUA CHON KHONG HOP LE! VUI LONG KIEM TRA LAI\n";
        }
        system("pause");
    }
}
int main() {
    vector<Point*> list;
    Program(list);
    return 0;
}