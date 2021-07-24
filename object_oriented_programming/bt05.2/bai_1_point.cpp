#include <iostream>
#include <cmath>
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

    void SetterX(float hoanhDo);
    void SetterY(float tungDo);

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
float Point::CalcLenght(Point a) {
    return sqrt(pow(a.x - this->x, 2) + pow(a.y - this->y, 2));
}

