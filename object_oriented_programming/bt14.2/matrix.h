#include <iostream>
using namespace std;

class Matrix
{
private:
    int **data;
    int row, col;

public:
    Matrix();
    Matrix(int, int);
    Matrix(const Matrix &);
    ~Matrix();

    // input, output
    friend istream &operator>>(istream &, Matrix &);
    friend ostream &operator<<(ostream &, Matrix &);

    // calculator
    friend Matrix operator+(const Matrix &, const Matrix &);
    friend Matrix operator-(const Matrix &, const Matrix &);
    friend Matrix operator*(const Matrix &, const Matrix &);

    // assign
    Matrix& operator=(const Matrix&);

    // access
    int &operator[](int);

    // setter
    void setAt(int, int, int);
    void resize(int, int);

    // getter
    int getAt(int, int);
};
