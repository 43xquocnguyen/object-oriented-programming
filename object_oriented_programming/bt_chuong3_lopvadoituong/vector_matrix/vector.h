#pragma once
#include "matrix.h"

class Vector
{
private:
    double *coords;
    int n;

public:
    Vector();
    Vector(int, double);
    Vector(const Vector &);
    ~Vector();

    friend ostream &operator<<(ostream &, const Vector &);
    friend istream &operator>>(istream &, Vector &);

    double Module();
    double DotProduct(const Vector &); // tich vo huong

    Vector operator+(const Vector &);
    Vector operator-(const Vector &);
    Vector operator*(const double &); // nhan voi so k
    Vector operator*(const Vector &); // tich co huong
    Vector operator/(const Vector &);

    Vector &operator=(const Vector &);

    bool operator==(const Vector &);
    bool operator!=(const Vector &);
    bool operator>(Vector &);
    bool operator>=(Vector &);
    bool operator<(Vector &);
    bool operator<=(Vector &);

    friend Vector Multiply(const Matrix &a, const Vector &b);
};
