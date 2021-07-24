#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Vector;

class Matrix
{
private:
    double **elements;
    int n, m;

public:
    Matrix();
    Matrix(int, int);
    Matrix(const Matrix &);
    ~Matrix();

    friend ostream &operator<<(ostream &, const Matrix &);
    friend istream &operator>>(istream &, Matrix &);

    Matrix operator+(const Matrix &);
    Matrix operator-(const Matrix &);
    Matrix operator*(const double &);
    Matrix operator*(const Matrix &);

    Matrix operator=(const Matrix &);

    bool operator==(const Matrix &);
    bool operator!=(const Matrix &);

    friend Vector Multiply(const Matrix &a, const Vector &b);
};


