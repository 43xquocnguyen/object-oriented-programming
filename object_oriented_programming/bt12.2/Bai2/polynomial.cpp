#include "polynomial.h"

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

