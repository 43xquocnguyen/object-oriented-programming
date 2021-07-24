#pragma once
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Time
{
private:
    int day, hour, minute, second;
    void Format() {
        int a = 0, b = 0, c = 0;

        if (this->second >= 60 || this->second < 0) {
            a = this->second / 60;
            this->second = this->second % 60;

            if (this->second < 0) {
                this->second += 60;
                a--;
            }
        }
    
        this->minute += a;

        if (this->minute >= 60 || this->minute < 0) {
            b = this->minute / 60;
            this->minute = this->minute % 60;

            if (this->minute < 0) {
                this->minute += 60;
                b--;
            }
        }

        this->hour += b;

        if (this->hour >= 24 || this->hour < 0) {
            c = this->hour / 24;
            this->hour = this->hour % 24;

            if (this->hour < 0) {
                this->hour += 24;
                c--;
            }
        }
        this->day += c;
    }
public:
    Time();
    Time(int, int, int);
    Time(int, int, int, int);
    ~Time();

    friend ostream &operator<<(ostream &, const Time &);
    friend istream &operator>>(istream &, Time &);

    Time operator+(const Time &);
    Time operator-(const Time &);
    Time operator+(const int &);
    Time operator-(const int &);

    Time& operator++();
    Time operator++(int);
    Time& operator--();
    Time operator--(int);

    Time operator=(const Time &);

    bool operator==(const Time &);
    bool operator!=(const Time &);
    bool operator>(const Time &);
    bool operator>=(const Time &);
    bool operator<(const Time &);
    bool operator<=(const Time &);
};