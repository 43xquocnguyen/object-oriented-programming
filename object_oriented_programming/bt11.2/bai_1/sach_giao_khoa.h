#pragma once
#include "sach.h"

class SachGiaoKhoa : public Sach
{
private:
    string tenMon;
    int sachLop;
public:
    SachGiaoKhoa();
    ~SachGiaoKhoa();

    void Input();
    void Output();
};