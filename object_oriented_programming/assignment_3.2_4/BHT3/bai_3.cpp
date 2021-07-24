#include "polygon.h"
#include <vector>

void Program(vector<Polygon*> list)
{
    while (true)
    {
        system("cls");
        cout << "1. THEM 1 DA GIAC\n";
        cout << "2. XUAT CAC DA GIAC\n";
        cout << "3. TINH TIEN MOT DIEM THEO VECTOR(a,b) VA XUAT\n";
        cout << "4. TRONG TAM CUA CAC DA GIAC\n";
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
            Polygon *a = new Polygon;
            a->Input();
            list.push_back(a);
        }
        else if (lc == '2') {
            if (list.size() >= 1) {
                int size = list.size();
                for (int i = 0; i < size; i++)
                {
                    cout << "DA GIAC THU "<< i + 1 << ": ";
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
                for (int i = 0; i < n; i++)
                {
                    list.at(i)->Trans(x, y);
                }
                system("cls");
                cout << "CAC DA GIAC SAU KHI TINH TIEN LA\n";
                for (int i = 0; i < n; i++)
                {
                    cout << "DA GIAC THU "<< i + 1 << ": ";
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
                    Point t = list.at(i)->Center_Point();
                    Point *t2 = &t;
                    trongTam.push_back(t2);
                }
                for (int i = 0; i < count; i++)
                {
                    cout << "TRONG TAM DA GIAC " << i + 1 << ": ";
                    trongTam.at(i)->Output();
                    cout << endl;
                }
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
    vector<Polygon *> p;
    Program(p);
    return 0;
}