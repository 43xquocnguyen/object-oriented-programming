#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Point
{
private:
    float x, y;
public:
    Point();
    Point(float, float);
    Point(const Point&);
    ~Point();

    void Input();
    void Output();

    void Trans(float, float);
    void Retale(float);
    float CalcLenght(Point a);
};

Point::Point()
{
    this->x = 0;
    this->y = 0;
}
Point::Point(float x, float y)
{
    this->x = x;
    this->y = y;
}
Point::Point(const Point& a) {
    this->x = a.x;
    this->y = a.y;
}
Point::~Point()
{
}

void Point::Input() {
    do
    {
        cout << "NHAP HOANH DO: ";
        cin >> this->x;
        if (cin.fail()) {
            cout << "HOANH DO KHONG HOP LE\n";
        }
    } while (cin.fail());

    do
    {
        cout << "NHAP TUNG DO: ";
        cin >> this->y;
        if (cin.fail()) {
            cout << "TUNG DO KHONG HOP LE\n";
        }
    } while (cin.fail());

}
void Point::Output() {
    cout << "(" << this->x << ";" << this->y << ")";
}

void Point::Trans(float a, float b) {
    this->x += a;
    this->y += b;
}
float Point::CalcLenght(Point a) {
    return sqrt(pow(a.x - this->x, 2) + pow(a.y - this->y, 2));
}


void Program(vector<Point*> *list)
{
    list = new vector<Point*>;
    while (true)
    {
        system("cls");
        cout << "1. THEM N DIEM (N > 0)\n";
        cout << "2. XUAT N DIEM\n";
        cout << "3. TINH TIEN MOT DIEM THEO VECTOR(a,b) VA XUAT\n";
        cout << "4. HAI DIEM CO KHOANG CACH NHO NHAT\n";
        cout << "5. HAI DIEM CO KHOANG CACH LON NHAT\n";
        cout << "0. KET THUC\n";
        cout << "\nNHAP VAO LUA CHON CUA BAN: ";
        char lc;
        cin >> lc;
        cin.ignore();

        if (lc == '0') {
            system("cls");
            cout << "CHUONG TRINH KET THUC\n";
            break;
            system("pause");
        }
        else if (lc == '1') {
            system("cls");
            int n;
            cout << "NHAP SO DIEM CAN THEM: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                system("cls");
                cout << "NHAP DIEM THU " << i + 1 << endl;
                Point *a = new Point;
                a->Input();
                list->push_back(a);
            }
            system("pause");
        }
        else if (lc == '2') {
            system("cls");
            int size = list->size();
            for (int i = 0; i < size; i++)
            {
                cout << (char)(i + 65);
                list->at(i)->Output();
                if (i < size - 1) {
                    cout << " - ";
                }
            }
            cout << endl;
            system("pause");
        }
        else if (lc == '3') {
            system("cls");
            float x, y;
            cout << "NHAP VECTOR(a, b) CAN TINH TIEN\n";
            cout << "NHAP a: ";
            cin >> x;
            cout << "NHAP b: ";
            cin >> y;
            int n = list->size();
            for (int i = 0; i < n; i++)
            {
                list->at(i)->Trans(x, y);
            }
            system("cls");
            cout << "CAC DIEM SAU KHI TINH TIEN LA\n";
            for (int i = 0; i < n; i++)
            {
                cout << (char)(i + 65);
                list->at(i)->Output();
                if (i < n - 1) {
                    cout << " - ";
                }
            }
            cout << endl;
            system("pause");
        }
        else if (lc == '4') {
            system("cls");
            int size = list->size();
            float max = list->at(0)->CalcLenght(*list->at(1));
            int vti = 0, vtj = 1;

            for (int i = 0; i < size - 1; i++)
            {
                for (int j = i + 1; j < size; j++)
                {
                    if (max < list->at(i)->CalcLenght(*list->at(j))) {
                        max = list->at(i)->CalcLenght(*list->at(j));
                        vti = i;
                        vtj = j;
                    }
                }
                
            }

            cout << "HAI DIEM KHOANG CACH LON NHAT LA: ";
            cout << (char)(vti + 65);
            list->at(vti)->Output();
            cout << " - " << (char)(vtj + 65);
            list->at(vtj)->Output();
            cout << endl;

            system("pause");
        }
        else if (lc == '5') {
            system("cls");
            int size = list->size();
            float min = list->at(0)->CalcLenght(*list->at(1));
            int vti = 0, vtj = 1;

            for (int i = 0; i < size - 1; i++)
            {
                for (int j = i + 1; j < size; j++)
                {
                    if (min > list->at(i)->CalcLenght(*list->at(j))) {
                        min = list->at(i)->CalcLenght(*list->at(j));
                        vti = i;
                        vtj = j;
                    }
                }
                
            }

            cout << "HAI DIEM KHOANG CACH NHO NHAT LA: ";
            cout << (char)(vti + 65);
            list->at(vti)->Output();
            cout << " - " << (char)(vtj + 65);
            list->at(vtj)->Output();
            cout << endl;

            system("pause");
        }
        else {
            system("cls");
            cout << "LUA CHON KHONG HOP LE\nKIEM TRA LAI\n";
            system("pause");
        }
    }
    delete list;
}
int main() {
    vector<Point *> *p;
    Program(p);
    return 0;
}