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
    ~Point();

    void Input();
    void Output();
    float GetterX();
    float GetterY();
    void SetterX(float x);
    void SetterY(float y);
    void Trans(float, float);
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
float Point::GetterX() { return this->x; }
float Point::GetterY() { return this->y; }
void Point::SetterX(float x) {
    this->x = x;
}
void Point::SetterY(float y) {
    this->y = y;
}
void Point::Trans(float a, float b) {
    this->x += a;
    this->y += b;
}
float Point::CalcLenght(Point a) {
    return sqrt(pow(a.x - this->x, 2) + pow(a.y - this->y, 2));
}