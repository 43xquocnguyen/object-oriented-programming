#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Time
{
private:
    int hour, minute, second;
    void Format() {
        while (this->second >= 60 || this->second < 0)
        {
            if (this->second >= 60) {
                this->second -= 60;
                this->minute++;
            }
            else {
                this->second += 60;
                this->minute--;
            }
        }
        while (this->minute >= 60 || this->minute < 0)
        {
            if (this->minute >= 60) {
                this->minute -= 60;
                this->hour++;
            }
            else {
                this->minute += 60;
                this->hour--;
            }
        }
    }
public:
    Time();
    Time(int, int, int);
    ~Time();

    void Input();
    void Output();

    Time Add2Time(const Time);
    Time Sub2Time(const Time);
};