#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class CTimeSpan
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
    CTimeSpan();
    CTimeSpan(int, int, int);
    CTimeSpan(int, int, int, int);
    ~CTimeSpan();

    friend ostream &operator<<(ostream &, const CTimeSpan &);
    friend istream &operator>>(istream &, CTimeSpan &);

    CTimeSpan operator+(const CTimeSpan &);
    CTimeSpan operator-(const CTimeSpan &);
    CTimeSpan operator+(const int &);
    CTimeSpan operator-(const int &);

    CTimeSpan& operator++();
    CTimeSpan operator++(int);
    CTimeSpan& operator--();
    CTimeSpan operator--(int);

    CTimeSpan operator=(const CTimeSpan &);

    bool operator==(const CTimeSpan &);
    bool operator!=(const CTimeSpan &);
    bool operator>(const CTimeSpan &);
    bool operator>=(const CTimeSpan &);
    bool operator<(const CTimeSpan &);
    bool operator<=(const CTimeSpan &);

};

CTimeSpan::CTimeSpan() {
    this->day = this->hour = this->minute = this->second = 0;
}
CTimeSpan::CTimeSpan(int hour, int minute, int second) {
    this->day = 0;
    this->hour = hour;
    this->minute = minute;
    this->second = second;
    this->Format();
}
CTimeSpan::CTimeSpan(int day, int hour, int minute, int second) {
    this->day = day;
    this->hour = hour;
    this->minute = minute;
    this->second = second;
    this->Format();
}
CTimeSpan::~CTimeSpan() {

}

ostream &operator<<(ostream &os, const CTimeSpan &a) {
    cout << a.day << " ngay, ";
    if (a.hour >= 10) cout << a.hour << ":";
    else cout << 0 << a.hour << ":";
    if (a.minute >= 10) cout << a.minute << ":";
    else cout << 0 << a.minute << ":";
    if (a.second >= 10) cout << a.second;
    else cout << 0 << a.second;
    return os;
}
istream &operator>>(istream &is, CTimeSpan &a) {
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

CTimeSpan CTimeSpan::operator+(const CTimeSpan &a) {
    CTimeSpan kq(this->day + a.day, this->hour + a.hour
    , this->minute + a.minute, this->second + a.second);
    kq.Format();
    return kq;
}
CTimeSpan CTimeSpan::operator-(const CTimeSpan &a) {
    CTimeSpan kq(this->day - a.day, this->hour - a.hour
    , this->minute - a.minute, this->second - a.second);
    kq.Format();
    return kq;
}

CTimeSpan CTimeSpan::operator+(const int &a) {
    CTimeSpan kq(this->day, this->hour
    , this->minute, this->second + a);
    kq.Format();
    return kq;
}
CTimeSpan CTimeSpan::operator-(const int &a) {
    CTimeSpan kq(this->day, this->hour
    , this->minute, this->second - a);
    kq.Format();
    return kq;
}

CTimeSpan& CTimeSpan::operator++() {
    this->second++;
    this->Format();
    return *this;
}
CTimeSpan& CTimeSpan::operator--() {
    this->second--;
    this->Format();
    return *this;
}
CTimeSpan CTimeSpan::operator++(int a) {
    CTimeSpan temp = *this;
    ++*this;
    this->Format();
    return temp;
}
CTimeSpan CTimeSpan::operator--(int a) {
    CTimeSpan temp = *this;
    --*this;
    this->Format();
    return temp;
}

CTimeSpan CTimeSpan::operator=(const CTimeSpan &a) {
    this->day = a.day;
    this->hour = a.hour;
    this->minute = a.minute;
    this->second = a.second;
    return *this;
}

bool CTimeSpan::operator==(const CTimeSpan &a) {
    return (this->day == a.day && this->hour == a.hour 
    && this->minute == a.minute && this->second == a.second);
}
bool CTimeSpan::operator!=(const CTimeSpan &a) {
    return !(*this == a);
}
bool CTimeSpan::operator>(const CTimeSpan &a) {
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
bool CTimeSpan::operator>=(const CTimeSpan &a) {
    if (*this > a || *this == a) return true;
    return false;
}
bool CTimeSpan::operator<(const CTimeSpan &a) {
    if (*this >= a) return false;
    return true;
}
bool CTimeSpan::operator<=(const CTimeSpan &a) {
    return !(*this > a);
}

void Menu(vector<CTimeSpan*> list) {
    while (1)
    {
        system("cls");
        cout << "1. THEM THOI GIAN\n";
        cout << "2. XUAT THOI GIAN\n";
        cout << "3. CONG TRU 2 KHOANG THOI GIAN\n";
        cout << "4. SO SANH 2 KHOANG THOI GIAN\n";
        cout << "0. THOAT\n";
        cout << "\nLUA CHON: ";
        char lc;
        cin >> lc;
        cin.ignore();
        system("cls");

        if (lc == '0') break;
        else if (lc == '1') {
            cout << "KHONG GIOI HAN SO GIO - PHUT - GIAY TOI DA\n";
            CTimeSpan *temp = new CTimeSpan;
            cin >> *temp;
            list.push_back(temp);
        }
        else if (lc == '2') {
            for (int i = 0; i < list.size(); i++)
            {
                cout << "THOI GIAN " << i + 1 << ": " << *list.at(i) << endl;
            }
        }
        else if (lc == '3') {
            if (list.size() >= 2) {
                int x, y;
                do
                {
                    cout << "NHAP VI TRI PHAN TU 1: ";
                    cin >> x;
                    cout << "NHAP VI TRI PHAN TU 2: ";
                    cin >> y;
                    if (x == y || x < 0 || x >= list.size() || y < 0 || y >= list.size()) {
                        cout << "KHONG TON TAI PHAN TU NAY\n";
                    }
                } while (x == y || x < 0 || x >= list.size() || y < 0 || y >= list.size());
                
                while (true)
                {
                    system("cls");
                    cout << "1. CONG (+)\n";
                    cout << "2. TRU (-)\n";
                    cout << "0. THOAT\n";
                    cout << "\nLUA CHON: ";
                    char lc1;
                    cin >> lc1;
                    cin.ignore();
                    system("cls");

                    if (lc1 == '0') break;
                    else if (lc1 == '1') cout << "KET QUA: " << *list.at(x) + *list.at(y) << endl;
                    else if (lc1 == '2') cout << "KET QUA: " << *list.at(x) - *list.at(y) << endl;
                    else cout << "LUA CHON KHONG HOP LE\n" << endl;
                    system("pause");
                }
            }
            else {
                cout << "KHONG CO DU LIEU DE THUC HIEN! VUI LONG NHAP THEM\n";;
            }
        }
        else if (lc == '4') {
            if (list.size() >= 2) {
                int x, y;
                do
                {
                    cout << "NHAP VI TRI PHAN TU 1: ";
                    cin >> x;
                    cout << "NHAP VI TRI PHAN TU 2: ";
                    cin >> y;
                    if (x == y || x < 0 || x >= list.size() || y < 0 || y >= list.size()) {
                        cout << "KHONG TON TAI PHAN TU NAY\n";
                    }
                } while (x == y || x < 0 || x >= list.size() || y < 0 || y >= list.size());

                while (true)
                {
                    system("cls");
                    cout << "1. BANG NHAU (==)\n";
                    cout << "2. KHAC NHAU (!=)\n";
                    cout << "3. LON HON (>)\n";
                    cout << "4. NHO HON (<)\n";
                    cout << "0. THOAT\n";
                    cout << "\nCHON CACH BAN MUON SO SANH: ";
                    char lc1;
                    cin >> lc1;
                    cin.ignore();
                    system("cls");

                    if (lc1 == '0') break;
                    else if (lc1 == '1') {
                        if (*list.at(x) == *list.at(y)) {
                            cout << *list.at(x) << " BANG " << *list.at(y) << endl;
                        }
                        else {
                            cout << *list.at(x) << " KHONG BANG " << *list.at(y) << endl;
                        }
                    }
                    else if (lc1 == '2') {
                        if (*list.at(x) != *list.at(y)) {
                            cout << *list.at(x) << " KHAC " << *list.at(y) << endl;
                        }
                        else {
                            cout << *list.at(x) << " BANG " << *list.at(y) << endl;
                        }
                    }
                    else if (lc1 == '3') {
                        if (*list.at(x) > *list.at(y)) {
                            cout << *list.at(x) << " LON HON " << *list.at(y) << endl;
                        }
                        else {
                            cout << *list.at(x) << " KHONG LON HON " << *list.at(y) << endl;
                        }
                    }
                    else if (lc1 == '4') {
                        if (*list.at(x) <= *list.at(y)) {
                            cout << *list.at(x) << " NHO HON " << *list.at(y) << endl;
                        }
                        else {
                            cout << *list.at(x) << " KHONG NHO HON " << *list.at(y) << endl;
                        }
                    }
                    else {
                        cout << "LUA CHON KHONG HOP LE\n";
                    }
                    system("pause");
                }
            }
            else {
                cout << "KHONG CO DU LIEU DE THUC HIEN! VUI LONG NHAP THEM\n";
            }
        }
        else {
            cout << "LUA CHON KHONG HOP LE\n";
        }
        system("pause");
    }
}

int main() {
    vector<CTimeSpan *> list;
    Menu(list);
    return 0;
}

