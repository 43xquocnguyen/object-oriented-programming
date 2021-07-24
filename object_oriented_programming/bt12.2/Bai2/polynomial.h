#pragma once
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
