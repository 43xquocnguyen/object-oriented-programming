#include "vector.h"

Vector::Vector()
{
    this->n = 0;
    this->coords = NULL;
}
Vector::Vector(int n, double coord)
{
    this->n = n;
    this->coords = new double[this->n];
    for (int i = 0; i < this->n; i++)
    {
        this->coords[i] = coord;
    }
}
Vector::Vector(const Vector &right)
{
    this->n = right.n;
    this->coords = new double[this->n];
    for (int i = 0; i < this->n; i++)
    {
        this->coords[i] = right.coords[i];
    }
}
Vector::~Vector()
{
    this->n = 0;
    if (this->coords != NULL)
        delete[] this->coords;
}

istream &operator>>(istream &is, Vector &right)
{
    do
    {
        cout << "NHAP SO CHIEU VECTOR: ";
        cin >> right.n;
        if (right.n <= 0) {
            cout << "SO CHIEU KHONG HOP LE\n";
        }
    } while (right.n <= 0);

    right.coords = new double[right.n];

    for (int i = 0; i < right.n; i++)
    {
        cout << "NHAP " << (char)(97 + i) << ": ";
        is >> right.coords[i];
    }
    return is;
}
ostream &operator<<(ostream &os, const Vector &right)
{
    os << "(" << right.coords[0];
    for (int i = 1; i < right.n; i++)
    {
        os << ";" << right.coords[i];
    }
    os << ")";
    return os;
}

double Vector::Module()
{
    double sum = 0;
    for (int i = 0; i < this->n; i++)
    {
        sum += (this->coords[i] * this->coords[i]);
    }
    return sqrt(sum);
}
double Vector::DotProduct(const Vector &right)
{
    if (this->n != right.n) return 0;
    double res = 0;
    for (int i = 0; i < this->n; i++)
    {
        res += this->coords[i] + right.coords[i];
    }
    return res;
}

Vector Vector::operator+(const Vector &right)
{
    if (this->n != right.n)
        return Vector(0, 0);
    for (int i = 0; i < this->n; i++)
    {
        right.coords[i] += this->coords[i];
    }
    return right;
}
Vector Vector::operator-(const Vector &right)
{
    if (this->n != right.n)
        return Vector(0, 0);
    for (int i = 0; i < this->n; i++)
    {
        right.coords[i] -= this->coords[i];
        right.coords[i] *= -1;
    }
    return right;
}
Vector Vector::operator*(const double &k)
{
    for (int i = 0; i < this->n; i++)
    {
        this->coords[i] *= k;
    }
    return *this;
}
Vector Vector::operator*(const Vector &right)
{
    if (this->n != 3 || right.n != 3)
        return Vector(3, 0);
    Vector *temp = new Vector;
    temp->n = 3;
    temp->coords = new double[3];
    temp->coords[0] = this->coords[1] * right.coords[2] - right.coords[1] * this->coords[2];
    temp->coords[1] = this->coords[0] * right.coords[2] - right.coords[0] * this->coords[2];
    temp->coords[2] = this->coords[0] * right.coords[1] - right.coords[0] * this->coords[1];
    return *temp;
}

Vector &Vector::operator=(const Vector &right)
{
    Vector temp(right);
    return temp;
}

bool Vector::operator==(const Vector &right)
{
    if (this->n != right.n)
        return false;
    for (int i = 0; i < this->n; i++)
    {
        if (this->coords[i] != right.coords[i])
            return false;
    }
    return true;
}
bool Vector::operator!=(const Vector &right)
{
    if (*this == right)
        return false;
    return true;
}

// xet module vector
bool Vector::operator>(Vector &right)
{
    if (this->Module() > right.Module())
        return true;
    return false;
}
bool Vector::operator>=(Vector &right)
{
    if (*this == right || *this > right)
        return true;
    return false;
}
bool Vector::operator<(Vector &right)
{
    if (*this >= right)
        return false;
    return true;
}
bool Vector::operator<=(Vector &right)
{
    if (*this > right)
        return false;
    return true;
}

Vector Multiply(const Matrix &a, const Vector &b)
{
    if (a.m != b.n)
    {
        cout << "KHONG NHAN DUOC!\n";
        return Vector(0, 0);
    }

    Vector res(a.n, 0);
    res.n = a.n;
    for (int i = 0; i < a.n; i++)
    {
        res.coords[i] = 0;
        for (int j = 0; j < b.n; j++)
            res.coords[i] = res.coords[i] + b.coords[j] * a.elements[i][j];
    }
    return res;
}