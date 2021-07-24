#include "triangle.h"

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
		check = false;
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
	cout << "A";
	point[0].Output();
	cout << " - ";
	cout << "B";
	point[1].Output();
	cout << " - ";
	cout << "C";
	point[2].Output();
}
void TriAngle::Trans(float a, float b) {
	for (int i = 0; i < 3; i++) {
		point[i].Trans(a, b);
	}
}
Point *TriAngle::Center() {
    double xx = point[0].GetterX() + point[1].GetterX() + point[2].GetterX();
    double yy = point[0].GetterY() + point[1].GetterY() + point[2].GetterY();
    Point *t = new Point(xx / 3, yy / 3);
    return t;
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