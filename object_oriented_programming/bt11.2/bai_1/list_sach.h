#include "sach.h"
#include "sach_giao_khoa.h"
#include "tap_chi.h"
#include "tieu_thuyet.h"
#include <vector>

class ListSach
{
private:
    vector<Sach *> list;
    int soSGK, soTC, soTT;
    void Bang() {
        cout << setw(5) << left << "STT";
        cout << setw(20) << left << "TEN SACH";
        cout << setw(20) << left << "TEN TAC GIA";
        cout << setw(20) << left << "GIA BAN";
    }
    void BangSGK() {
        this->Bang();
        cout << setw(20) << left << "TEN MON";
        cout << setw(15) << left << "LOP" << endl;
        cout << setfill('-') << setw(100) << "-" << endl;
    }
    void BangTC() {
        this->Bang();
        cout << setw(20) << left << "TEN BIA";
        cout << setw(15) << left << "SO TRANG" << endl;
        cout << setfill('-') << setw(100) << "-" << endl;
    }
    void BangTT() {
        this->Bang();
        cout << setw(20) << left << "NOI DUNG";
        cout << setw(15) << left << "SO TAP" << endl;
        cout << setfill('-') << setw(100) << "-" << endl;
    }
public:
    ListSach();
    ~ListSach();

    void Input();
    void Output();
};
