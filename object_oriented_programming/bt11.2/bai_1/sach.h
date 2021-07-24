#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Sach
{
protected:
    string tenSach;
    string tenTacGia;
    int giaBan;
    int check;
public:
    Sach();
    virtual ~Sach();
    
    int GetterCheck() { return this->check; }

    virtual void Input();
    virtual void Output();
};