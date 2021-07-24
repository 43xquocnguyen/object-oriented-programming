#include "triangle.h"
#include <vector>

void Program(vector<TriAngle*> list)
{
    while (true)
    {
        system("cls");
        cout << "1. THEM 1 TAM GIAC\n";
        cout << "2. XUAT CAC TAM GIAC\n";
        cout << "3. TINH TIEN MOT DIEM THEO VECTOR(a,b) VA XUAT\n";
        cout << "4. TRONG TAM CUA TAM GIAC\n";
        cout << "5. TAM GIAC CO CHU VI LON NHAT\n";
        cout << "6. TAM GIAC CO DIEN TICH LON NHAT\n";
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
            TriAngle *a = new TriAngle;
            a->Input();
            list.push_back(a);
        }
        else if (lc == '2') {
            if (list.size() >= 1) {
                int size = list.size();
                for (int i = 0; i < size; i++)
                {
                    cout << "TAM GIAC THU "<< i + 1 << ": ";
                    list.at(i)->Output();
                    cout << endl;
                }
            }
            else {
                cout << "KHONG CO DU LIEU\n";
            }
        }
        else if (lc == '3') {
            if (list.size() >= 1) {
                float x, y;
                cout << "NHAP VECTOR(a, b) CAN TINH TIEN\n";
                cout << "NHAP a: ";
                cin >> x;
                cout << "NHAP b: ";
                cin >> y;
                int n = list.size();
                system("cls");
                for (int i = 0; i < n; i++)
                {
                    list.at(i)->Trans(x, y);
                }
                cout << "CAC TAM GIAC SAU KHI TINH TIEN LA\n";
                for (int i = 0; i < n; i++)
                {
                    cout << "TAM GIAC THU "<< i + 1 << ": ";
                    list.at(i)->Output();
                    cout << endl;
                }
            }
            else {
                cout << "KHONG CO DU LIEU\n";
            }
        }
        else if (lc == '4') {
            if (list.size() >= 1) {
                vector<Point *> trongTam;
                int count = list.size();
                for (int i = 0; i < count; i++)
                {
                    Point *t = list.at(i)->Center();
                    trongTam.push_back(t);
                }
                for (int i = 0; i < count; i++)
                {
                    cout << "TRONG TAM TAM GIAC " << i + 1 << ": ";
                    trongTam.at(i)->Output();
                    cout << endl;
                }
            }
            else {
                cout << "KHONG CO DU LIEU\n";
            }
        }
        else if (lc == '5') {
            if (list.size() >= 1) {
                int size = list.size();
                float max = list.at(0)->CalcC();
                int vti = 0;
                for (int i = 1; i < size; i++)
                {
                    if (max < list.at(i)->CalcC())
                    {
                        max = list.at(i)->CalcC();
                        vti = i;
                    }
                }

                cout << "TAM GIAC CO CHU VI LON NHAT LA: ";
                list.at(vti)->Output();
                cout << endl;

            }
            else {
                cout << "KHONG CO DU LIEU\n";
            }
        }
        else if (lc == '6') {
            if (list.size() >= 1) {
                int size = list.size();
                float max = list.at(0)->CalcS();
                int vti = 0;
                for (int i = 1; i < size; i++)
                {
                    if (max < list.at(i)->CalcS())
                    {
                        max = list.at(i)->CalcS();
                        vti = i;
                    }
                }

                cout << "TAM GIAC CO DIEN TICH LON NHAT LA: ";
                list.at(vti)->Output();
                cout << endl;

            }
            else {
                cout << "KHONG CO DU LIEU\n";
            }
        }
        else {
            cout << "LUA CHON KHONG HOP LE\nKIEM TRA LAI\n";
        }
        system("pause");
    }
}
int main() {
    vector<TriAngle *> list;
    Program(list);
    return 0;
}