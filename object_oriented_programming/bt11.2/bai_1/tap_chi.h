#pragma once
#include "sach.h"

class TapChi : public Sach
{
private:
    string tenBia;
    int soTrang;
public:
    TapChi();
    ~TapChi();

    void Input();
    void Output();
};