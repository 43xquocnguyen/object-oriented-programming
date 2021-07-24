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
    ~Point();

    void Input();
    void Output();

    float GetterX();
    float GetterY();

    void SetterX(float);
    void SetterY(float);

    void Trans(float, float);
    void Retale(float);
    float Module(Point);
    float MultiCoor(Point);
    Point operator-(Point);
    bool operator==(Point);
};