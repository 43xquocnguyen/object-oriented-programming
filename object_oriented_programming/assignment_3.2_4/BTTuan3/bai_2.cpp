#include "point.h"
#include <cmath>

class TriAngle
{
private:
	Point *point;
public:
	TriAngle();
    TriAngle(Point, Point, Point);
    ~TriAngle();

	void Input();
	void Output();

	void Trans(float, float);
    float CalcS();
    float CalcC();
};

TriAngle::TriAngle() {
	point = new Point[3];
}
TriAngle::TriAngle(Point a, Point b, Point c) {
    point = new Point[3];
    point[0] = a;
    point[1] = b;
    point[2] = c;
}
TriAngle::~TriAngle() {
	delete[] point;
}

void TriAngle::Input() {
	bool check = false;
	do
	{
		cout << "NHAP DIEM A\n";
		this->point[0].Input();
		cout << "NHAP DIEM B\n";
		this->point[1].Input();
		cout << "NHAP DIEM C\n";
		this->point[2].Input();

		float AB = point[0].CalcLenght(point[1]);
		float BC = point[1].CalcLenght(point[2]);
		float CA = point[2].CalcLenght(point[0]);

		if (AB + BC <= CA || BC + CA <= AB || AB + CA <= BC) {
			check = true;
			cout << "TAM GIAC KHONG TON TAI\n";
		}
	} while (check);
}
void TriAngle::Output() {
	for (int i = 0; i < 3; i++)
	{
		cout << (char)(65 + i);
		point[i].Output();
		cout << "\t";
	}
}
void TriAngle::Trans(float a, float b) {
	for (int i = 0; i < 3; i++) {
		point[i].Trans(a, b);
	}
}
float TriAngle::CalcC() {
    float AB = point[0].CalcLenght(point[1]);
	float BC = point[1].CalcLenght(point[2]);
	float CA = point[2].CalcLenght(point[0]);
    return AB + BC + CA;
}
float TriAngle::CalcS() {
    float AB = point[0].CalcLenght(point[1]);
	float BC = point[1].CalcLenght(point[2]);
	float CA = point[2].CalcLenght(point[0]);
    float p = this->CalcC() / 2;
    return sqrt(p * (p - AB) * (p - BC) * (p - CA));
}

void Program(vector<TriAngle*> *list)
{
    list = new vector<TriAngle*>;
    while (true)
    {
        system("cls");
        cout << "1. THEM N TAM GIAC (N > 0)\n";
        cout << "2. XUAT N TAM GIAC\n";
        cout << "3. TINH TIEN MOT DIEM THEO VECTOR(a,b) VA XUAT\n";
        cout << "4. TAM GIAC CO CHU VI LON NHAT\n";
        cout << "5. TAM GIAC CO DIEN TICH LON NHAT\n";
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
            cout << "NHAP SO TAM GIAC CAN THEM: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                system("cls");
				cout << "NHAP TAM GIAC THU " << i + 1 << endl << endl;
				TriAngle *a = new TriAngle;
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
				cout << "TAM GIAC THU "<< i + 1 << ": ";
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
            cout << "CAC TAM GIAC SAU KHI TINH TIEN LA\n";
            for (int i = 0; i < n; i++)
            {
                cout << "TAM GIAC THU "<< i + 1 << ": ";
				list->at(i)->Output();
				cout << endl;
            }
            cout << endl;
            system("pause");
        }
        else if (lc == '4') {
            system("cls");
            int size = list->size();
            float max = list->at(0)->CalcC();
			int vti = 0;
			for (int i = 1; i < size; i++)
            {
                if (max < list->at(i)->CalcC())
				{
					max = list->at(i)->CalcC();
					vti = i;
				}
            }

            cout << "TAM GIAC CO CHU VI LON NHAT LA: ";
			list->at(vti)->Output();
			cout << endl;

            system("pause");
        }
        else if (lc == '5') {
            system("cls");
            int size = list->size();
            float max = list->at(0)->CalcS();
			int vti = 0;
			for (int i = 1; i < size; i++)
            {
                if (max < list->at(i)->CalcS())
				{
					max = list->at(i)->CalcS();
					vti = i;
				}
            }

            cout << "TAM GIAC CO DIEN TICH LON NHAT LA: ";
			list->at(vti)->Output();
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
    vector<TriAngle *> *p;
    Program(p);
    return 0;
}