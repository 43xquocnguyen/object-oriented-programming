#include "point.h"

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

void Point::SetterX(float a) {
    this->x = a;
}
void Point::SetterY(float a) {
    this->y = a;
}

float Point::GetterX() { return this->x; }
float Point::GetterY() { return this->y; }

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
