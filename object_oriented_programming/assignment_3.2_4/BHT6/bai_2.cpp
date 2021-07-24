#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Fraction
{
private:
    int tu, mau;
    void Reduce() {
        int a = tu, b = mau;
        if (a < 0)
            a *= -1;
        if (b < 0)
            b *= -1;
        while(a != b) {
            if (a > b)
                a -= b;
            if (b > a)
                b -= a;
        }
        tu /= a;
        mau /= a;
    }
public:
    Fraction();
    Fraction(int, int);
    ~Fraction();
    int getY() { return this->tu; }

    friend ostream &operator<<(ostream &, const Fraction &);
    friend istream &operator>>(istream &, Fraction &);

    Fraction operator+(const Fraction &);
    Fraction operator-(const Fraction &);
    Fraction operator*(const Fraction &);
    Fraction operator/(const Fraction &);

    Fraction operator=(const Fraction &);

    bool operator==(const Fraction &);
    bool operator!=(const Fraction &);
    bool operator>(const Fraction &);
    bool operator>=(const Fraction &);
    bool operator<(const Fraction &);
    bool operator<=(const Fraction &);

};

Fraction::Fraction() {
    this->tu = 0;
    this->mau = 1;
}
Fraction::Fraction(int tu, int mau) {
    this->tu = tu;
    if (mau != 0)
        this->mau = mau;
}
Fraction::~Fraction() {

}

ostream &operator<<(ostream &os, const Fraction &a) {
    if (a.tu == 0) {
        cout << 0;
    }
    else if (a.tu > 0 && a.mau < 0 || a.tu < 0 && a.mau < 0) {
        cout << a.tu * -1 << "/" << a.mau * -1;
    }
    else {
        cout << a.tu << "/" << a.mau;
    }
    return os;
}
istream &operator>>(istream &is, Fraction &a) {
    cout << "NHAP TU SO: ";
    is >> a.tu;
    do
    {
        cout << "NHAP MAU SO: ";
        is >> a.mau;
        if (a.mau == 0)
            cout << "MAU SO KHONG HOP LE\n";
    } while (a.mau == 0);
    a.Reduce();
    return is;
}

Fraction Fraction::operator+(const Fraction &a) {
    Fraction kq(this->tu * a.mau + a.tu * this->mau, this->mau * a.mau);
    kq.Reduce();
    return kq;
}
Fraction Fraction::operator-(const Fraction &a) {
    Fraction kq(this->tu * a.mau - a.tu * this->mau, this->mau * a.mau);
    kq.Reduce();
    return kq;
}
Fraction Fraction::operator*(const Fraction &a) {
    Fraction kq(this->tu * a.tu, this->mau * a.mau);
    kq.Reduce();
    return kq;
}
Fraction Fraction::operator/(const Fraction &a) {
    Fraction kq(this->tu * a.mau, this->mau * a.tu);
    kq.Reduce();
    return kq;
}

Fraction Fraction::operator=(const Fraction &a) {
    this->tu = a.tu;
    this->mau = a.mau;
    return *this;
}

bool Fraction::operator==(const Fraction &a) {
    return (this->tu == a.tu && this->mau == a.mau);
}
bool Fraction::operator!=(const Fraction &a) {
    return (this->tu != a.tu || this->mau != a.mau);
}
bool Fraction::operator>(const Fraction &a) {
    if (double(this->tu / this->mau) > double(a.tu / a.mau))
        return true;
    return false;
}
bool Fraction::operator>=(const Fraction &a) {
    if (double(this->tu / this->mau) >= double(a.tu / a.mau))
        return true;
    return false;
}
bool Fraction::operator<(const Fraction &a) {
    if (double(this->tu / this->mau) < double(a.tu / a.mau))
        return true;
    return false;
}
bool Fraction::operator<=(const Fraction &a) {
    if (double(this->tu / this->mau) <= double(a.tu / a.mau))
        return true;
    return false;
}

void Menu(vector<Fraction*> list) {
    while (1)
    {
        system("cls");
        cout << "1. THEM PHAN SO\n";
        cout << "2. XUAT PHAN SO\n";
        cout << "3. TINH TOAN\n";
        cout << "4. SO SANH\n";
        cout << "0. THOAT\n";
        cout << "\nLUA CHON: ";
        char lc;
        cin >> lc;
        cin.ignore();
        system("cls");

        if (lc == '0') break;
        else if (lc == '1') {
            Fraction *temp = new Fraction;
            cin >> *temp;
            list.push_back(temp);
        }
        else if (lc == '2') {
            for (int i = 0; i < list.size(); i++)
            {
                cout << "PHAN SO " << i + 1 << ": " << *list.at(i) << endl;
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
                    cout << "3. NHAN (*)\n";
                    cout << "4. CHIA (/)\n";
                    cout << "0. THOAT\n";
                    cout << "\nLUA CHON: ";
                    char lc1;
                    cin >> lc1;
                    cin.ignore();
                    system("cls");

                    if (lc1 == '0') break;
                    else if (lc1 == '1') cout << "KET QUA: " << *list.at(x) + *list.at(y) << endl;
                    else if (lc1 == '2') cout << "KET QUA: " << *list.at(x) - *list.at(y) << endl; 
                    else if (lc1 == '3') cout << "KET QUA: " << *list.at(x) * *list.at(y) << endl; 
                    else if (lc1 == '4') {
                        if (list[y]->getY() == 0) cout << "KHONG THE CHIA\n";
                        else {
                            cout << "KET QUA: " << *list.at(x) / *list.at(y) << endl;
                        }
                    }
                    else  cout << "LUA CHON KHONG HOP LE\n" << endl;
                    system("pause");
                }
            }
            else {
                cout << "KHONG CO DU LIEU DE THUC HIEN! VUI LONG NHAP THEM\n";
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
                    cout << "\nLUA CHON: ";
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
                    else  cout << "LUA CHON KHONG HOP LE\n" << endl;
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
    vector<Fraction*> list;
    Menu(list);
    return 0;
}

