#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Date
{
private:
    int day, month, year;
    bool TrueDate(int d, int m, int y) {
        if (y < 0) return false;
        switch (m)
        {
            case 2: {
                if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0)) {
                    if (d < 0 || d > 29) return false;
                    return true;
                }
                if (d < 0 || d > 28) return false;
                return true;
            }
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: {
                if (d < 0 || d > 31) return false;
                return true;
            }
            case 4: case 6: case 9: case 11: {
                if (d < 0 || d > 30) return false;
                return true;
            }
        }
    }
    int DayofMonth(int m, int y) {
        switch (m)
        {
            case 4: case 6: case 9: case 11: {
                return 30;
            }
            case 2: {
                if ((y % 4 == 0) && (y % 100 != 0)|| (y % 400 == 0)) 
                    return 29;
                return 28;
            }
        }
        return 31;
    }
    void Format() {
        while (this->day > this->DayofMonth(this->month, this->year) || this->day <= 0) {
            if (this->day > this->DayofMonth(this->month, this->year)) {
                this->day -= this->DayofMonth(this->month, this->year);
                this->month++;
            }
            if (this->day <= 0) {
                this->month--;
                this->day += this->DayofMonth(this->month, this->year);
            }
        }
        while (this->month > 12 || this->month <= 0)
        {
            if (this->month > 12) {
                this->month -= 12;
                this->year++;
            }
            if (this->month <= 0) {
                this->year--;
                this->month += 12;
            }
        }
    }
    int ConvertDay(int d, int m, int y) {
        m--;
        while (m != 0)
        {
            d += this->DayofMonth(m, y);
            m--;
        }
        while (y != 0)
        {
            if ((y % 4 == 0) && (y % 100 != 0)|| (y % 400 == 0)) {
                d += 366;
            }
            else d += 365;
            y--;
        }
        return d;
    }
public:
    Date();
    Date(int, int, int);
    ~Date();

    friend ostream &operator<<(ostream &, const Date &);
    friend istream &operator>>(istream &, Date &);

    Date operator+(const int &);
    Date operator-(const int &);
    int operator-(Date);

    Date& operator++();
    Date operator++(int);
    Date& operator--();
    Date operator--(int);

    Date operator=(const Date &);

    bool operator==(const Date &);
    bool operator!=(const Date &);
    bool operator>(const Date &);
    bool operator>=(const Date &);
    bool operator<(const Date &);
    bool operator<=(const Date &);

};

Date::Date() {
    this->year = this->month = this->day = 0;
}
Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
    this->Format();
}
Date::~Date() { }

ostream &operator<<(ostream &os, const Date &a) {
    cout << "Ngay " << a.day << ", Thang " << a.month << ", Nam " << a.year;
    return os;
}
istream &operator>>(istream &is, Date &a) {
    do
    {
        cout << "NHAP NGAY: ";
        cin >> a.day;
        cout << "NHAP THANG: ";
        cin >> a.month;
        cout << "NHAP NAM: ";
        cin >> a.year;
        if (!a.TrueDate(a.day, a.month, a.year)) {
            cout << "VUI LONG KIEM TRA LAI! NGAY THANG NAM KHONG HOP LE\n";
        }
    } while (!a.TrueDate(a.day, a.month, a.year));
    return is;
}

Date Date::operator+(const int &day)
{
    Date temp(this->day + day, this->month, this->year);
    temp.Format();
    return temp;
}
Date Date::operator-(const int &day) {
    Date temp(this->day - day, this->month, this->year);
    temp.Format();
    return temp;
}
int Date::operator-(Date right) {
    if (*this > right) {
        int a = this->ConvertDay(this->day, this->month, this->year);
        int b = right.ConvertDay(right.day, right.month, right.year);
        return a - b;
    }
    return 0;
}

Date& Date::operator++() {
    this->day++;
    this->Format();
    return *this;
}
Date Date::operator++(int) {
    Date temp = *this;
    ++*this;
    this->Format();
    return temp;
}
Date& Date::operator--() {
    this->day--;
    this->Format();
    return *this;
}
Date Date::operator--(int) {
    Date temp = *this;
    --*this;
    this->Format();
    return temp;
}

Date Date::operator=(const Date &right) {
    this->day = right.day;
    this->month = right.month;
    this->year = right.year;
    return *this;
}

bool Date::operator==(const Date &a) {
    if (this->day != a.day || this->month != a.month || this->year != a.year) {
        return false;
    }
    return true;
}
bool Date::operator!=(const Date &a) {
    if (*this == a)
        return false;
    return true;
}
bool Date::operator>(const Date &a) {
    if (this->year > a.year) return true;
    else if (this->year < a.year) return false;
    if (this->month > a.month) return true;
    else if (this->month < a.month) return false;
    if (this->day > a.day) return true;
    else if (this->day < a.day) return false;
    return false;
}
bool Date::operator>=(const Date &a) {
    if (*this > a || *this == a) return true;
    return false;
}
bool Date::operator<(const Date &a) {
    if (*this >= a) return false;
    return true;
}
bool Date::operator<=(const Date &a) {
    if (*this < a || *this == a) return true;
    return false;
}

void Menu(vector<Date*> list) {
    while (1)
    {
        system("cls");
        cout << "1. THEM MOT NGAY THANG\n";
        cout << "2. XUAT CAC NGAY THANG\n";
        cout << "3. THEM BOT 1 SO NGAY\n";
        cout << "4. TINH KHOANG CACH CUA 2 NGAY\n";
        cout << "5. SO SANH\n";
        cout << "0. THOAT\n";
        cout << "\nLUA CHON: ";
        char lc;
        cin >> lc;
        cin.ignore();
        system("cls");

        if (lc == '0') break;
        else if (lc == '1') {
            Date *temp = new Date;
            cin >> *temp;
            list.push_back(temp);
        }
        else if (lc == '2') {
            if (list.size() > 0) {
                for (int i = 0; i < list.size(); i++)
                {
                    cout << "NGAY THANG NAM " << i + 1 << ": " << *list.at(i) << endl;
                }
            }
            else {
                cout << "KHONG CO DU LIEU\n";
            }
        }
        else if (lc == '3') {
            if (list.size() > 0) {
                int x, vt;
                char sign;
                do
                {
                    cout << "NHAP VI TRI PHAN TU NGAY THANG CAN THEM BOT(INDEX): ";
                    cin >> vt;
                    cout << "CAN THEM HOAC BOT('+' or '-'): ";
                    cin >> sign;
                    cout << "NHAP SO NGAY: ";
                    cin >> x;
                    if ((sign != '+' && sign != '-' ) || vt < 0 || vt > list.size() || x <= 0) {
                        cout << "KHONG HOP LE! VUI LONG KIEM TRA LAI\n";
                    }
                } while ((sign != '+' && sign != '-' ) || vt < 0 || vt > list.size() || x <= 0);
                if (sign == '+')
                    *list.at(vt) = *list.at(vt) + x;
                else
                    *list.at(vt) = *list.at(vt) - x;
                cout << "DA THUC HIEN\n\n";
                cout << "KET QUA: " << *list.at(vt) << endl;
            }
            else {
                cout << "KHONG CO DU LIEU\n";
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
                if (*list.at(x) == *list.at(y)) cout << "KHOANG CACH: 0 NGAY" << endl;
                else if (*list.at(x) > *list.at(y)) cout << "KHOANG CACH: " << *list.at(x) - *list.at(y) << " NGAY" << endl;
                else cout << "KHOANG CACH: " << *list.at(y) - *list.at(x) << " NGAY" << endl;
            }
            else {
                cout << "KHONG CO DU LIEU\n";
            }
        }
        else if (lc == '5') {
            if (list.size() > 1) {
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
                if (*list.at(x) == *list.at(y)) cout << *list.at(x) << "BANG NHAU" << *list.at(y) << endl;
                else if (*list.at(x) > *list.at(y)) cout << *list.at(x) << "LON HON" << *list.at(y) << endl;
                else cout << *list.at(x) << "NHO HON" << *list.at(y) << endl;
            }
            else {
                cout << "KHONG CO DU LIEU\n";
            }
        }
        else {
            cout << "LUA CHON KHONG HOP LE\n";
        }
        system("pause");
    }
}

int main() {
    vector<Date *> list;
    Menu(list);
    return 0;
}