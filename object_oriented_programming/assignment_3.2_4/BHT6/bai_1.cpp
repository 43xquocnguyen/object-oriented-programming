#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Complex
{
private:
    float real, imag;

public:
    Complex(float = 0, float = 0);
    ~Complex();

    double Module();

    friend ostream &operator<<(ostream &, const Complex &);
    friend istream &operator>>(istream &, Complex &);

    Complex operator+(const Complex &);
    Complex operator-(const Complex &);
    Complex operator*(const Complex &);
    Complex operator/(const Complex &);

    Complex operator=(const Complex &);

    bool operator==(Complex);
    bool operator!=(Complex);
    bool operator>(Complex);
    bool operator>=(Complex);
    bool operator<(Complex);
    bool operator<=(Complex);
};

Complex::Complex(float real = 0, float imag = 0)
{
    this->real = real;
    this->imag = imag;
}
Complex::~Complex()
{
}
double Complex::Module()
{
    return sqrt(this->real * this->real + this->imag * this->imag);
}
ostream &operator<<(ostream &os, const Complex &a)
{
    if (a.real == 0 && a.imag != 0)
        os << a.imag << "i";
    else if (a.real != 0 && a.imag == 0)
        os << a.real;
    else if (a.real == 0 && a.imag == 0)
        os << 0;
    else
        os << a.real << ((a.imag > 0) ? "+" : "-") << abs(a.imag) << "i";
    return os;
}
istream &operator>>(istream &is, Complex &a)
{
    cout << "NHAP PHAN THUC: ";
    is >> a.real;
    cout << "NHAP PHAN AO: ";
    is >> a.imag;
    return is;
}

Complex Complex::operator+(const Complex &a)
{
    return Complex(this->real + a.real, this->imag + a.imag);
}
Complex Complex::operator-(const Complex &a)
{
    return Complex(this->real - a.real, this->imag - a.imag);
}
Complex Complex::operator*(const Complex &a)
{
    Complex result;
    result.real = this->real * a.real - this->imag * a.imag;
    result.imag = this->real * a.imag + this->imag * a.real;
    return result;
}
Complex Complex::operator/(const Complex &a)
{
    Complex result;
    result.real = (this->real * a.real + this->imag * a.imag) / a.imag * a.imag + a.real * a.real;
    result.imag = (this->imag * a.real - this->real * a.imag) / a.imag * a.imag + a.real * a.real;
    return result;
}

Complex Complex::operator=(const Complex &a)
{
    this->real = a.real;
    this->imag = a.imag;
    return *this;
}

// xet theo Module so phuc
bool Complex::operator==(Complex a)
{
    return (this->Module() == a.Module());
}
bool Complex::operator!=(Complex a)
{
    return !(*this == a);
}
bool Complex::operator>(Complex a)
{
    return (this->Module() > a.Module());
}
bool Complex::operator>=(Complex a)
{
    return (this->Module() >= a.Module());
}
bool Complex::operator<(Complex a)
{
    if (*this >= a) return false;
    return true;
}
bool Complex::operator<=(Complex a)
{
    if (*this > a) return false;
    return true;
}

void Menu(vector<Complex *> list)
{
    while (1)
    {
        system("cls");
        cout << "1. THEM SO PHUC\n";
        cout << "2. XUAT SO PHUC\n";
        cout << "3. TINH TOAN\n";
        cout << "4. SO SANH\n";
        cout << "0. THOAT\n";
        cout << "\nLUA CHON: ";
        char lc;
        cin >> lc;
        cin.ignore();
        system("cls");

        if (lc == '0')
            break;
        else if (lc == '1')
        {
            Complex *temp = new Complex;
            cin >> *temp;
            list.push_back(temp);
        }
        else if (lc == '2')
        {
            for (int i = 0; i < list.size(); i++)
            {
                cout << "SO PHUC " << i + 1 << ": " << *list.at(i) << endl;
            }
        }
        else if (lc == '3')
        {
            if (list.size() >= 2)
            {
                int x, y;
                do
                {
                    cout << "NHAP VI TRI PHAN TU 1: ";
                    cin >> x;
                    cout << "NHAP VI TRI PHAN TU 2: ";
                    cin >> y;
                    if (x == y || x < 0 || x >= list.size() || y < 0 || y >= list.size())
                    {
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

                    if (lc1 == '0')
                        break;
                    else if (lc1 == '1')
                        cout << "KET QUA: " << *list.at(x) + *list.at(y) << endl;
                    else if (lc1 == '2')
                        cout << "KET QUA: " << *list.at(x) - *list.at(y) << endl;
                    else if (lc1 == '3')
                        cout << "KET QUA: " << *list.at(x) * *list.at(y) << endl;
                    else if (lc1 == '4')
                        cout << "KET QUA: " << *list.at(x) / *list.at(y) << endl;
                    else
                        cout << "LUA CHON KHONG HOP LE\n"
                             << endl;
                    system("pause");
                }
            }
            else
                cout << "KHONG CO DU LIEU DE THUC HIEN! VUI LONG NHAP THEM\n";
        }
        else if (lc == '4')
        {
            if (list.size() >= 2)
            {
                int x, y;
                do
                {
                    cout << "NHAP VI TRI PHAN TU 1: ";
                    cin >> x;
                    cout << "NHAP VI TRI PHAN TU 2: ";
                    cin >> y;
                    if (x == y || x < 0 || x >= list.size() || y < 0 || y >= list.size())
                    {
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

                    if (lc1 == '0')
                        break;
                    else if (lc1 == '1')
                    {
                        if (*list.at(x) == *list.at(y))
                        {
                            cout << *list.at(x) << " BANG " << *list.at(y) << endl;
                        }
                        else
                        {
                            cout << *list.at(x) << " KHONG BANG " << *list.at(y) << endl;
                        }
                    }
                    else if (lc1 == '2')
                    {
                        if (*list.at(x) != *list.at(y))
                        {
                            cout << *list.at(x) << " KHAC " << *list.at(y) << endl;
                        }
                        else
                        {
                            cout << *list.at(x) << " BANG " << *list.at(y) << endl;
                        }
                    }
                    else if (lc1 == '3')
                    {
                        if (*list.at(x) > *list.at(y))
                        {
                            cout << *list.at(x) << " LON HON " << *list.at(y) << endl;
                        }
                        else
                        {
                            cout << *list.at(x) << " KHONG LON HON " << *list.at(y) << endl;
                        }
                    }
                    else if (lc1 == '4')
                    {
                        if (*list.at(x) <= *list.at(y))
                        {
                            cout << *list.at(x) << " NHO HON " << *list.at(y) << endl;
                        }
                        else
                        {
                            cout << *list.at(x) << " KHONG NHO HON " << *list.at(y) << endl;
                        }
                    }
                    else
                    {
                        cout << "LUA CHON KHONG HOP LE\n"
                             << endl;
                    }
                    system("pause");
                }
            }
            else
            {
                cout << "KHONG CO DU LIEU DE THUC HIEN! VUI LONG NHAP THEM\n";
            }
        }
        else
        {
            cout << "LUA CHON KHONG HOP LE\n";
        }
        cout << "NHAP PHIM BAT KI DE TIEP TUC\n";
        system("pause");
    }
}

int main()
{
    vector<Complex *> list;
    Menu(list);
    return 0;
}
