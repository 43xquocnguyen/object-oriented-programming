#pragma once
#include <iostream>
using namespace std;

class Date
{
private:
    int ngay, thang, nam;
    bool LeapYear() {
        if ((this->nam % 4 == 0 && this->nam % 100 != 0) || this->nam % 400 == 0) return true;
        return false;
    }
public:
    Date();
    ~Date();

    void Input();
    void Output();
};