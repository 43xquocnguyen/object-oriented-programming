#pragma once
#include "sach.h"

class TieuThuyet : public Sach
{
private:
    string noiDungTT;
    int soTap;
public:
    TieuThuyet();
    ~TieuThuyet();

    void Input();
    void Output();
};