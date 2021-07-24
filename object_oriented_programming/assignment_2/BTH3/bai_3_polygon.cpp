#include "point.h"

class Polygon
{
private:
	Point* point;
	int n;
public:
	Polygon();
	~Polygon();

	void Input();
	void Output();

	void Trans(float, float);

	Point Center_Point();
};

Polygon::Polygon() {
	do
	{
		cout << "NHAP SO DIEM CUA DA GIAC: ";
		cin >> this->n;
		if (this->n <= 0) {
			cout << "SO LUONG DIEM CUA DA GIAC KHONG HOP LE\n";
		}
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX);
			this->n = -1;
		}
	} while (this->n <= 0);

	point = new Point[n];
}
Polygon::~Polygon() {
	delete[] point;
}
void Polygon::Input() {
	for (int i = 0; i < this->n; i++)
	{
		cout << "NHAP DIEM " << (char)(65 + i) << endl;
		point[i].Input();
	}
}
void Polygon::Output() {
	for (int i = 0; i < n; i++)
	{
		cout << (char)(65 + i);
		point[i].Output();
		if (i < this->n - 1)
		{
			cout << " - ";
		}
	}
}
void Polygon::Trans(float a, float b) {
	for (int i = 0; i < this->n; i++)
	{
		point[i].Trans(a, b);
	}
}
Point Polygon::Center_Point() {
	float x = 0, y = 0;
	for (int i = 0; i < this->n; i++)
	{
		x += this->point[i].GetterX();
		y += this->point[i].GetterY();
	}
	return Point(x / this->n, y / this->n);
}
void Program(vector<Polygon*> *list)
{
    list = new vector<Polygon*>;
    while (true)
    {
        system("cls");
        cout << "1. THEM N DA GIAC (N > 0)\n";
        cout << "2. XUAT N DA GIAC\n";
        cout << "3. TINH TIEN CAC DA GIAC THEO VECTOR(a,b) VA XUAT\n";
        cout << "4. TRONG TAM DA GIAC\n";
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
            cout << "NHAP SO DA GIAC CAN THEM: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                system("cls");
				cout << "NHAP DA GIAC THU " << i + 1 << endl << endl;
				Polygon *a = new Polygon;
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
				cout << "DA GIAC THU "<< i + 1 << ": ";
				list->at(i)->Output();
				cout << endl;
			}
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
            cout << "CAC DA GIAC SAU KHI TINH TIEN LA\n";
            for (int i = 0; i < n; i++)
            {
                cout << "DA GIAC THU "<< i + 1 << ": ";
				list->at(i)->Output();
				cout << endl;
            }
            cout << endl;
            system("pause");
        }
        else if (lc == '4') {
            system("cls");
            int size = list->size();
            for (int i = 0; i < size; i++)
            {
                Point tt = list->at(i)->Center_Point();
                cout << "TRONG TAM DA GIAC THU " << i + 1 << ": ";
                tt.Output();
                cout << endl;
            }
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
    vector<Polygon *> *p;
    Program(p);
    return 0;
}