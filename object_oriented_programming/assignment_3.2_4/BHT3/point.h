#pragma once
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
    Point(const Point&);
    ~Point();

    void Input();
    void Output();

    void SetterX(float);
    void SetterY(float);
    float GetterX();
    float GetterY();

    void Trans(float, float);
    void Retale(float);
    float CalcLenght(Point a);
};