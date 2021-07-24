#include "polygon.h"

Polygon::Polygon() {
	this->n = 0;
	this->point = NULL;
	this->tick = 0;
}
Polygon::Polygon(int n) {
	this->n = n;
	this->point = new Point[this->n];
}
Polygon::~Polygon() {
	delete[] this->point;
	this->n = 0;
}
void Polygon::Input() {
	do
	{
		for (int i = 0; i < this->n; i++)
		{
			cout << "NHAP DIEM " << (char)(65 + i) << endl;
			point[i].Input();
		}
		if (!this->Check()) {
			cout << "HINH KHONG TON TAI\n";
		}
	} while (!this->Check());
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
bool Polygon::Check() {
	for (int i = 0; i < this->n - 1; i++)
	{
		for (int j = i + 1; j < this->n; j++)
		{
			if (this->point[i] == this->point[j]) {
				return false;
			}
		}
	}
	return true;
}
void Polygon::Trans(float a, float b) {
	for (int i = 0; i < this->n; i++)
	{
		point[i].Trans(a, b);
	}
}
void Polygon::Relate(float rad) {
	for (int i = 0; i < this->n; i++)
	{
		point[i].Retale(rad);
	}
}
void Polygon::Zoom(float l) {
	for (int i = 0; i < this->n; i++)
	{
		point[i].SetterX(point[i].GetterX() * l);
		point[i].SetterY(point[i].GetterY() * l);
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