#include "polygon.h"

Polygon::Polygon() {
    this->n = 0;
    this->point = NULL;
}
Polygon::~Polygon() {
	delete[] point;
}
void Polygon::Input() {
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

