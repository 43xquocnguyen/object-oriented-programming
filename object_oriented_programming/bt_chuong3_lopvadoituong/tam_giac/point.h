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

