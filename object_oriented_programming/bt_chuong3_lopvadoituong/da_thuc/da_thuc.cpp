#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Polynomial
{
private:
    double *coeffic;
    int deg;
public:
    Polynomial();
    Polynomial(int);
    Polynomial(const Polynomial &);
    ~Polynomial();

    friend ostream &operator<<(ostream &, const Polynomial &);
    friend istream &operator>>(istream &, Polynomial &);

    Polynomial& operator++();
    Polynomial operator++(int);
    Polynomial& operator--();
    Polynomial operator--(int);

    double Evalue(double x);
    Polynomial operator+(const Polynomial &);
    Polynomial operator-(const Polynomial &);
    Polynomial operator*(const Polynomial &);
    Polynomial operator/(const Polynomial &);

    Polynomial& operator=(const Polynomial &);
    double operator[](const int&);

    bool operator==(const Polynomial &);
    bool operator!=(const Polynomial &);
    bool operator>(const Polynomial &);
    bool operator>=(const Polynomial &);
    bool operator<(const Polynomial &);
    bool operator<=(const Polynomial &);

};

Polynomial::Polynomial() {
    this->deg = 0;
    this->coeffic = NULL;
}
Polynomial::Polynomial(int deg) {
    this->deg = deg;
    this->coeffic = new double[this->deg + 1];
    for (int i = 0; i <= this->deg; i++)
    {
        this->coeffic[i] = 0;
    }
}
Polynomial::Polynomial(const Polynomial &right) {
    this->deg = right.deg;
    this->coeffic = new double[this->deg + 1];
    for (int i = 0; i <= this->deg; i++)
    {
        this->coeffic[i] = right.coeffic[i];
    }
}
Polynomial::~Polynomial() {
    this->deg = 0;
    delete[] this->coeffic;
}

istream &operator>>(istream &is, Polynomial &right) {
    for (int i = right.deg; i >= 0; i--)
    {
        cout << "NHAP HE SO (x) BAC " << i << ": ";
        is >> right.coeffic[i];
    }
    return is;
}
ostream &operator<<(ostream &os, const Polynomial &right) {
    for (int i = right.deg; i >= 0 ; i--)
    {
        if (i == 0) {
            cout << right.coeffic[i];
        }
        else if (i == 1) {
            cout << right.coeffic[i] << "x + ";
        }
        else {
            cout << right.coeffic[i] << "x^" << i << " + ";
        }
    }
    return os;
}

Polynomial& Polynomial::operator++() {
    for (int i = 0; i <= this->deg; i++)
    {
        this->coeffic[i] += 1;
    }
    return *this;
}
Polynomial Polynomial::operator++(int a) {
    Polynomial temp = *this;
    ++*this;
    return temp;
}
Polynomial& Polynomial::operator--() {
    for (int i = 0; i <= this->deg; i++)
    {
        this->coeffic[i] -= 1;
    }
    return *this;
}
Polynomial Polynomial::operator--(int a) {
    Polynomial temp = *this;
    --*this;
    return temp;
}
double Polynomial::Evalue(double x) {
    int sum = this->coeffic[0];
    for (int i = 1; i <= this->deg; i++)
    {
        sum += (this->coeffic[i] * pow(x, i));
    }
    return sum;
}

Polynomial Polynomial::operator+(const Polynomial &right)
{
    Polynomial temp = *this > right ? *this : right;
    int min = this->deg < right.deg ? this->deg : right.deg;
    for (int i = 0; i <= min; i++)
    {
        temp.coeffic[i] = this->coeffic[i] + right.coeffic[i];
    }
    return temp;
}
Polynomial Polynomial::operator-(const Polynomial &right)
{
    /* ==== cua thay
    int tempDeg = (deg > right.deg) ? deg : right.deg;
    Polynomial d(tempDeg);
    for (int i = 0; i <= tempDeg; i++)
    {
        if (deg >= i && right.deg >= i) d.coeffic[i] = coeffic[i] - right.coeffic[i];
        else if (right.deg < i) d.coeffic[i] = coeffic[i];
        else if (deg < i) d.coeffic[i] = right.coeffic[i];
    }*/

    Polynomial temp = *this > right ? *this : right;
    int min = this->deg < right.deg ? this->deg : right.deg;
    for (int i = 0; i <= min; i++)
    {
        temp.coeffic[i] = this->coeffic[i] - right.coeffic[i];
    }
    if (*this < right) {
        min++;
        for (int i = min; i <= temp.deg; i++)
        {
            temp.coeffic[i] *= -1;
        }
    }
    Polynomial temp2 = temp;
    return temp2;
}
Polynomial Polynomial::operator*(const Polynomial &right)
{
    Polynomial *result = new Polynomial(this->deg + right.deg);
    /*
	for (int i = 0; i <= result->deg; ++i)
	{
		result->coeffic[i] = 0;
		for (int j = 0; j <= (int)i / 2; ++j)
		{
			if (this->deg >= i && right.deg >= i)
			{
				if (i != 0)
				{
					result->coeffic[i] += (this->coeffic[j] * right.coeffic[i - j]) + (right.coeffic[j] * this->coeffic[i - j]);
				}
				else
				{
					result->coeffic[i] += (this->coeffic[j] * right.coeffic[i - j]);
				}
				continue;
			}
			if (right.deg >= i - j)
			{
				result->coeffic[i] += (this->coeffic[j] * right.coeffic[i - j]);
				continue;
			}
			if (this->deg >= i - j)
			{
				result->coeffic[i] += right.coeffic[j] * this->coeffic[i - j];
				continue;
			}
		}
	}*/
    /*
    for (int i = 0; i <= this->deg + right.deg; i++)
	{
		result->coeffic[i] = 0;
		for (int j = 0; j <= i; j++)
			result->coeffic[i] += this->coeffic[j] * right.coeffic[i - j];
	}*/
    fill(result->coeffic, result->coeffic + deg + 1, 0.0);
    
    for (int i = 0; i <= this->deg; i++) {
        for (int j = 0; j <= right.deg; j++) {
            result->coeffic[i + j] += this->coeffic[i] * right.coeffic[j];
        }
    }
	return *result;
}
Polynomial Polynomial::operator/(const Polynomial &right)
{
    if (this->deg < right.deg) {
        cout << "BAC CUA SO CHIA NHO HON SO BI CHIA\n";
        return Polynomial(0);
    }
    Polynomial *left = new Polynomial(*this); // sao chep *this
    Polynomial *result = new Polynomial(this->deg - right.deg);
    Polynomial *res = new Polynomial; // phan du
    int i = result->deg;
    for (int i = this->deg; i >= right.deg; i--, result->deg--)
    {
        result->coeffic[i - right.deg] = left->coeffic[i] / right.coeffic[right.deg];
        if (i - 1 >= right.deg)
        {
            for (int j = i - 1, k = right.deg - 1; k >= 0; j--, k--)
                left->coeffic[j] -= result->coeffic[i - right.deg] * right.coeffic[k];
        }
    }
    return *result;
}

Polynomial& Polynomial::operator=(const Polynomial &right) {
    if (this == &right) return *this;
    for (int i = right.deg; i >= 0; i--)
    {
        if (right.coeffic[i] != 0) {
            this->deg = i;
            break;
        }
    }
    this->coeffic = new double[this->deg + 1];
    for (int i = 0; i <= this->deg; i++)
    {
        this->coeffic[i] = right.coeffic[i];
    }
    return *this;
}
double Polynomial::operator[](const int &right) {
    return this->coeffic[right];
}

// chi so sanh ve bac duoc thoi
bool Polynomial::operator==(const Polynomial &right) {
    if (this->deg != right.deg) return false;
    for (int i = 0; i < this->deg; i++)
    {
        if (this->coeffic[i] != right.coeffic[i]) return false;
    }
    return true;
}
bool Polynomial::operator!=(const Polynomial &right) {
    if (*this == right)
        return false;
    return true;
}
bool Polynomial::operator>(const Polynomial &right) {
    if (this->deg > right.deg) return true;
    return false;
}
bool Polynomial::operator>=(const Polynomial &right) {
    if (this->deg > right.deg || *this == right) return true;
    return false;
}
bool Polynomial::operator<(const Polynomial &right) {
    if (this->deg < right.deg) return true;
    return false;
}
bool Polynomial::operator<=(const Polynomial &right) {
    if (this->deg < right.deg || *this == right) return true;
    return false;
}

void Menu(vector<Polynomial*> list) {
    while (1)
    {
        system("cls");
        cout << "1. THEM VAO 1 DA THUC (Polynomial)\n";
        cout << "2. XUAT RA DANH SACH DA THUC DA NHAP (Polynomial)\n";
        cout << "3. TINH TOAN VOI 2 DA THUC\n";
        cout << "4. SO SANH 2 DA THUC\n";
        cout << "0. THOAT\n";
        cout << "\nLUA CHON: ";
        char lc;
        cin >> lc;
        cin.ignore();
        system("cls");

        if (lc == '0') break;
        else if (lc == '1') {
            int x;
            do
            {
                cout << "NHAP BAC DA THUC: ";
                cin >> x;
                if (x <= 0) cout << "BAC CUA DA THUC KHONG HOP LE\n";
            } while (x <= 0);
            Polynomial *temp = new Polynomial(x);
            cin >> *temp;
            list.push_back(temp);
        }
        else if (lc == '2') {
            if (list.size() > 0) {
                for (int i = 0; i < list.size(); i++)
                {
                    cout << "DA THUC THU " << i + 1 << ": " << *list[i] << endl;
                }
            }
            else {
                cout << "KHONG CO DU LIEU\n";
            }
        }
        else if (lc == '3') {
            int x, y;
            do
            {
                cout << "NHAP VI TRI PHAN TU 1 (INDEX): ";
                cin >> x;
                cout << "NHAP VI TRI PHAN TU 2 (INDEX): ";
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
                cout << "5. TANG (++) VA GIAM (--)\n";
                cout << "6. TAI GIA GIA x\n";
                cout << "0. THOAT\n";
                cout << "\nLUA CHON: ";
                char lc1;
                cin >> lc1;
                cin.ignore();
                system("cls");

                if (lc1 == '0') break;
                else if (lc1 == '1') {
                    if (list.size() >= 2) {
                        cout << "KET QUA: " << *list[x] + *list[y] << endl;
                    }
                    else cout << "KHONG CO DU DU LIEU\n";
                }
                else if (lc1 == '2') {
                    if (list.size() >= 2) {
                        cout << "KET QUA: " << *list[x] - *list[y] << endl;
                    }
                    else cout << "KHONG CO DU DU LIEU\n";
                } 
                else if (lc1 == '3') {
                    if (list.size() >= 2) {
                        cout << "KET QUA: " << *list[x] * *list[y] << endl;
                    }
                    else cout << "KHONG CO DU DU LIEU\n";
                } 
                else if (lc1 == '4') {
                    if (list.size() >= 2) {
                        cout << "KET QUA: " << *list[x] / *list[y] << endl;
                    }
                    else cout << "KHONG CO DU DU LIEU\n";
                }
                else if (lc1 == '5') {
                    ++*list[x];
                    --*list[y];
                    cout << "TANG (++) DA THUC 1: " << *list.at(x) << endl;
                    cout << "GIAM (--) DA THUC 2: " << *list.at(y) << endl;
                }
                else if (lc1 == '6') {
                    double x;
                    cout << "NHAP GIA TRI x: ";
                    cin >> x;
                    for (int i = 0; i < list.size(); i++)
                    {
                        cout << "DA THUC " << i + 1 << " TAI x = " << x << ": " << list.at(i)->Evalue(x) << endl;
                    }
                    
                }
                else  cout << "LUA CHON KHONG HOP LE\n" << endl;
                system("pause");
        }
        }
        else if (lc == '4') {
            if (list.size() >= 2) {
                int x, y;
                do
                {
                    cout << "NHAP VI TRI PHAN TU 1 (INDEX): ";
                    cin >> x;
                    cout << "NHAP VI TRI PHAN TU 2 (INDEX): ";
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
                    cout << "3. LON HON XET BAC (>)\n";
                    cout << "4. NHO HON XET BAC (<)\n";
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
        }
        else {
            cout << "LUA CHON KHONG HOP LE\n";
        }
        system("pause");
    }
}

int main() {
    vector<Polynomial *> list;
    Menu(list);
    return 0;
}