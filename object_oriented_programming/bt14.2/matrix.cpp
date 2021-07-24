#include "matrix.h"

// constructor
Matrix::Matrix() {
    this->col = this->row = 0;
    this->data = NULL;
}
Matrix::Matrix(int row, int col) {
    this->row = row;
    this->col = col;

    // allowcation
    this->data = new int*[this->row];
    for (int i = 0; i < this->row; i++)
    {
        this->data[i] = new int[this->col];
    }

    // fill = 0
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
            this->data[i][j] = 0;
        }
        
    }
}
Matrix::Matrix(const Matrix &right) {
    this->row = right.row;
    this->col = right.col;

    // allowcation
    this->data = new int *[this->row];
    for (int i = 0; i < this->row; i++)
    {
        this->data[i] = new int[this->col];
    }

    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
            this->data[i][j] = right.data[i][j];
        }
        
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < this->row; i++)
    {
        delete this->data[i];
    }
    delete[] this->data;
}

// input, output
istream &operator>>(istream &is, Matrix &right) {
    bool checkFail;

    // row, col
    do
    {
        checkFail = false;
        cout << "Enter rows: ";
        is >> right.row;
        if (is.fail() || right.row <= 0) {
            checkFail = true;
            is.clear();
            is.ignore(INT_MAX, '\n');
            right.row = -1;
            cout << "Rows input ivalid\n";
        }
    } while (checkFail);
    do
    {
        checkFail = false;
        cout << "Enter collums: ";
        is >> right.col;
        if (is.fail() || right.col <= 0) {
            checkFail = true;
            is.clear();
            is.ignore(INT_MAX, '\n');
            right.col = -1;
            cout << "Collums input ivalid\n";
        }
    } while (checkFail);

    // allowcation
    right.data = new int*[right.row];
    for (int i = 0; i < right.row; i++)
    {
        right.data[i] = new int[right.col];
    }

    // input data
    for (int i = 0; i < right.row; i++)
    {
        for (int j = 0; j < right.col; j++)
        {
            cout << "Enter A[" << i + 1 << "][" << j + 1 << "]: ";
            is >> right.data[i][j];
        }
    }

    return is;
}
ostream &operator<<(ostream &os, Matrix &right) {
    // input data
    for (int i = 0; i < right.row; i++)
    {
        for (int j = 0; j < right.col; j++)
        {
            os << right.data[i][j] << "\t";
        }
        os << endl;
    }

    return os;
}

// calculator
Matrix operator+(const Matrix &A, const Matrix &B) {
    int row = A.row;
    int col = A.col;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            A.data[i][j] += B.data[i][j];
        }
    }

    return A;
}
Matrix operator-(const Matrix &A, const Matrix &B) {
    int row = A.row;
    int col = A.col;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            A.data[i][j] -= B.data[i][j];
        }
    }

    return A;   
}
Matrix operator*(const Matrix &A, const Matrix &B) {
    int Arow = A.row;
    int Acol = A.col;
    int Bcol = B.col;
    Matrix temp(Arow, Bcol);

    for (int i = 0; i < Arow; i++)
    {
        for (int j = 0; j < Acol; j++)
        {
            temp.data[i][j] = 0;
            for (int k = 0; k < Acol; k++)
                temp.data[i][j] += A.data[i][k] * B.data[k][j];
        }
    }
    return temp;
}

// assign
Matrix& Matrix::operator=(const Matrix &right) {
    this->row = right.row;
    this->col = right.col;

    // allowcation
    this->data = new int*[this->row];
    for (int i = 0; i < this->row; i++)
    {
        this->data[i] = new int[this->col];
    }

    // fill = 0
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
            this->data[i][j] = right.data[i][j];
        }
        
    }
    return *this;
}

// access
int& Matrix::operator[](int i) {
    return this->data[i][0];
}

// setter
void Matrix::setAt(int i, int j, int data) {
    this->data[i][j] = data;
}
void Matrix::resize(int row, int col) {
    this->row = row;
    this->col = col;
}

// getter
int Matrix::getAt(int i, int j) {
    return this->data[i][j];
}