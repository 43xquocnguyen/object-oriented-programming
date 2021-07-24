#include "matrix.h"

Matrix::Matrix()
{
    this->n = this->m = 0;
    this->elements = NULL;
}
Matrix::Matrix(int n, int m)
{
    this->n = n;
    this->m = m;
    this->elements = new double *[this->n];
    for (int i = 0; i < this->n; i++)
    {
        this->elements[i] = new double[m];
    }
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->m; j++)
        {
            this->elements[i][j] = 0;
        }
    }
}
Matrix::Matrix(const Matrix &right)
{
    this->n = right.n;
    this->m = right.m;
    this->elements = new double *[this->n];
    for (int i = 0; i < this->n; i++)
    {
        this->elements[i] = new double[m];
    }

    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->m; j++)
        {
            this->elements[i][j] = right.elements[i][j];
        }
    }
}
Matrix::~Matrix()
{
    for (int i = 0; i < this->n; i++)
    {
        delete[] this->elements[i];
    }
    delete[] this->elements;
}

ostream &operator<<(ostream &os, const Matrix &right)
{
    for (int i = 0; i < right.n; i++)
    {
        for (int j = 0; j < right.m; j++)
        {
            os << right.elements[i][j] << "\t";
        }
        cout << "\n";
    }
    return os;
}
istream &operator>>(istream &is, Matrix &right)
{
    do
    {
        cout << "NHAP SO HANG MA TRAN: ";
        cin >> right.n;
        cout << "NHAP SO COT MA TRAN: ";
        cin >> right.m;
        if (right.n <= 0 || right.m <= 0) {
            cout << "MA TRAN KHONG HOP LE\n";
        }
    } while (right.n <= 0  || right.m <= 0);

    right.elements = new double*[right.n];
    for (int i = 0; i < right.n; i++)
    {
        right.elements[i] = new double[right.m];
    }
    
    for (int i = 0; i < right.n; i++)
    {
        for (int j = 0; j < right.m; j++)
        {
            cout << "NHAP PHAN TU [" << i << "][" << j << "]: ";
            is >> right.elements[i][j];
        }
    }
    return is;
}

Matrix Matrix::operator+(const Matrix &right)
{
    if (this->n != right.n || this->m != right.m)
        return Matrix(this->n, this->m);
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->m; j++)
        {
            right.elements[i][j] += this->elements[i][j];
        }
    }
    return right;
}
Matrix Matrix::operator-(const Matrix &right)
{
    if (this->n != right.n || this->m != right.m)
        return Matrix(this->n, this->m);
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->m; j++)
        {
            right.elements[i][j] += this->elements[i][j];
            right.elements[i][j] *= -1;
        }
    }
    return right;
}
Matrix Matrix::operator*(const double &k)
{
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->m; j++)
        {
            this->elements[i][j] *= k;
        }
    }
    return *this;
}
Matrix Matrix::operator*(const Matrix &right)
{
    if (this->m != right.n)
        return Matrix(this->n, this->m);
    Matrix *temp = new Matrix(this->n, right.m);
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->m; j++)
        {
            temp->elements[i][j] = 0;
            for (int k = 0; k < this->m; k++)
                temp->elements[i][j] += this->elements[i][k] * right.elements[k][j];
        }
    }
    return *temp;
}

Matrix Matrix::operator=(const Matrix &right)
{
    Matrix *temp = new Matrix(right);
    return *temp;
}

bool Matrix::operator==(const Matrix &right)
{
    if (this->n != right.n || this->m != right.m)
        return false;
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->m; j++)
        {
            if (this->elements[i][j] != right.elements[i][j])
                return false;
        }
    }
    return true;
}
bool Matrix::operator!=(const Matrix &right)
{
    return !(*this == right);
}
