#include "time.h"

Time::Time() {
    this->hour = 0;
    this->minute = 0;
    this->second = 0;
}
Time::Time(int hour, int minute, int second) {
    this->hour = hour;
    this->minute = minute;
    this->second = second;
    this->Format();
}
Time::~Time() { }
void Time::Input() {
    do
    {
        cout << "NHAP SO GIO: ";
        cin >> this->hour;
        if (this->hour < 0) {
            cout << "GIO KHONG HOP LE\n";
        }
        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            this->hour = -1;
        }
    } while (this->hour < 0);

    do
    {
        cout << "NHAP SO PHUT: ";
        cin >> this->minute;
        if (this->minute < 0) {
            cout << "SO PHUT KHONG HOP LE\n";
        }
        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            this->minute = -1;
        }
    } while (this->minute < 0);

    do
    {
        cout << "NHAP SO GIAY: ";
        cin >> this->second;
        if (this->second < 0) {
            cout << "SO GIAY KHONG HOP LE\n";
        }
        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            this->second = -1;
        }
    } while (this->second < 0);
    this->Format();
}
void Time::Output() {
    if (this->hour < 10) cout << 0 << this->hour << ":";
    else cout << this->hour << ":";
    if (this->minute < 10) cout << 0 << this->minute << ":";
    else cout << this->minute << ":";
    if (this->second < 10) cout << 0 << this->second;
    else cout << this->second;
}
Time Time::Add2Time(const Time right) {
    Time temp(this->hour + right.hour, this->minute + right.minute, this->second + right.second);
    temp.Format();
    return temp;
}
Time Time::Sub2Time(const Time right) {
    Time temp(this->hour - right.hour, this->minute - right.minute, this->second - right.second);
    temp.Format();
    return temp;
}