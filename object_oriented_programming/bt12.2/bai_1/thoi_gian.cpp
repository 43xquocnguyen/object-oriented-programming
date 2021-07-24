#include "thoi_gian.h"

Time::Time() {
    this->day = this->hour = this->minute = this->second = 0;
}
Time::Time(int hour, int minute, int second) {
    this->day = 0;
    this->hour = hour;
    this->minute = minute;
    this->second = second;
    this->Format();
}
Time::Time(int day, int hour, int minute, int second) {
    this->day = day;
    this->hour = hour;
    this->minute = minute;
    this->second = second;
    this->Format();
}
Time::~Time() {

}

ostream &operator<<(ostream &os, const Time &a) {
    cout << a.day << " ngay, ";
    if (a.hour >= 10) cout << a.hour << ":";
    else cout << 0 << a.hour << ":";
    if (a.minute >= 10) cout << a.minute << ":";
    else cout << 0 << a.minute << ":";
    if (a.second >= 10) cout << a.second;
    else cout << 0 << a.second;
    return os;
}
istream &operator>>(istream &is, Time &a) {
    do
    {
        cout << "NHAP GIO: ";
        is >> a.hour;
        if (a.hour < 0)
            cout << "GIO KHONG HOP LE\n";
    } while (a.hour < 0);
    do
    {
        cout << "NHAP PHUT: ";
        is >> a.minute;
        if (a.minute < 0)
            cout << "GIO KHONG HOP LE\n";
    } while (a.minute < 0);
    do
    {
        cout << "NHAP GIAY: ";
        is >> a.second;
        if (a.second < 0)
            cout << "GIAY KHONG HOP LE\n";
    } while (a.second < 0);
    a.Format();
    return is;
}

Time Time::operator+(const Time &a) {
    Time kq(this->day + a.day, this->hour + a.hour
    , this->minute + a.minute, this->second + a.second);
    kq.Format();
    return kq;
}
Time Time::operator-(const Time &a) {
    Time kq(this->day - a.day, this->hour - a.hour
    , this->minute - a.minute, this->second - a.second);
    kq.Format();
    return kq;
}

Time Time::operator+(const int &a) {
    Time kq(this->day, this->hour
    , this->minute, this->second + a);
    kq.Format();
    return kq;
}
Time Time::operator-(const int &a) {
    Time kq(this->day, this->hour
    , this->minute, this->second - a);
    kq.Format();
    return kq;
}

Time& Time::operator++() {
    this->second++;
    this->Format();
    return *this;
}
Time& Time::operator--() {
    this->second--;
    this->Format();
    return *this;
}
Time Time::operator++(int a) {
    Time temp = *this;
    ++*this;
    this->Format();
    return temp;
}
Time Time::operator--(int a) {
    Time temp = *this;
    --*this;
    this->Format();
    return temp;
}

Time Time::operator=(const Time &a) {
    this->day = a.day;
    this->hour = a.hour;
    this->minute = a.minute;
    this->second = a.second;
    return *this;
}

bool Time::operator==(const Time &a) {
    return (this->day == a.day && this->hour == a.hour 
    && this->minute == a.minute && this->second == a.second);
}
bool Time::operator!=(const Time &a) {
    return !(*this == a);
}
bool Time::operator>(const Time &a) {
    if (this->day > a.day) return true;
    else if (this->day < a.day) return false;
    if (this->hour > a.hour) return true;
    else if (this->hour < a.hour) return false;
    if (this->minute > a.minute) return true;
    else if (this->minute < a.minute) return false;
    if (this->second > a.second) return true;
    else if (this->second < a.second) return false;
    return false;
}
bool Time::operator>=(const Time &a) {
    if (*this > a || *this == a) return true;
    return false;
}
bool Time::operator<(const Time &a) {
    if (*this >= a) return false;
    return true;
}
bool Time::operator<=(const Time &a) {
    return !(*this > a);
}
