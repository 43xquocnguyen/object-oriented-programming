#include "point.h"

Point::Point()
{
    this->x = this->y = 0;
}
Point::Point(float x, float y)
{
    this->x = x;
    this->y = y;
}
Point::~Point()
{
    this->x = this->y = 0;
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

float Point::GetterX() { return this->x; }
float Point::GetterY() { return this->y; }
void Point::SetterX(float x) { this->x = x; }
void Point::SetterY(float y) { this->y = y; }

void Point::Trans(float a, float b) {
    this->x += a;
    this->y += b;
}
void Point::Retale(float rad) {
    this->x = this->x * cos(rad) + this->y * sin(rad);
    this->y = this->x * sin(rad) + this->y * cos(rad);
}
float Point::Module(Point a) {
    return sqrt(pow(a.x - this->x, 2) + pow(a.y - this->y, 2));
}
float Point::MultiCoor(Point a) {
    return this->x * a.x + this->y * a.y;
}
Point Point::operator-(Point a) {
    return Point(this->x - a.x, this->y - a.y);
}
bool Point::operator==(Point a) {
    if (this->x == a.x && this->y == a.y) return true;
    return false;
}