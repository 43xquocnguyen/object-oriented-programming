#include <iostream>
using namespace std;

class Vector
{
private:
    double *coords;
    int n;
public:
    Vector();
    Vector(int N, double x); // tạo vector có N chiều, mỗi ô có giá trị x
    Vector(const Vector &a);
    ~Vector();
    void Nhap();
    void Xuat();
    int Cong(const Vector &a); // return 1 nếu cộng được
    void NhanK(const double &k);
    int Tru(Vector a); // return 1 nếu trừ được
    double TichVoHuong(const Vector &a);
    friend Vector multiply(const Matrix &a, const Vector &b);
};
Vector::Vector()
{
    coords = NULL;
}
Vector::Vector(int N, double x)
{
    n = N;
    coords = new double[n];
    for (int i = 0; i < n; i++)
        coords[i] = x;
}
Vector::Vector(const Vector & a)
{
    n = a.n;
    coords = new double[n];
    for (int i = 0; i < n; i++)
        coords[i] = a.coords[i];
}
Vector::~Vector()
{
    if (coords != NULL)
        delete[] coords;
}

void Vector::Nhap()
{
    cin >> n;
    coords = new double[n];
    for (int i = 0; i < n; i++)
        cin >> coords[i];
}
void Vector::Xuat()
{
    for (int i = 0; i < n; i++)
        cout << roundf(coords[i] * 100) / 100 << " ";
    cout << endl;
}
 
int Vector::Cong(const Vector & a)
{
    if (n != a.n)
        return 0;
    for (int i = 0; i < n; i++)
        coords[i] += a.coords[i];
    return 1;
}
void Vector::NhanK(const double & k)
{
    for (int i = 0; i < n; i++)
        coords[i] *= k;
}
int Vector::Tru(Vector a)
{
    if (n != a.n)
        return 0;
    a.NhanK(-1);
    Cong(a);
    return 1;
}

double Vector::TichVoHuong(const Vector &a)
{
    double res = 0;
    for (int i = 0; i < n; i++)
        res += coords[i] * a.coords[i];
    return res;
}

class Matrix
{
private:
    int m; // dòng
    int n; // cột
    double **elements; 
public:
    Matrix();
    ~Matrix();
    Matrix(const Matrix & a);
    void Nhap();
    void Xuat();
    int Cong(const Matrix & a); // return 1 nếu cộng được
    void Nhan(const double & k);// Nhân với 1 số K
    int Nhan(const Matrix & a);// Nhân với 1 CMatrix, return 1 nếu nhân được
    friend Vector multiply(const Matrix &a, const Vector &b);
};

Matrix::Matrix()
{
    m = 0;
    n = 0;
    elements = NULL;    
}
Matrix::~Matrix()
{
    if (elements == NULL)
        return;
    for (int i = 0; i < m; i++)
    {
        delete[] elements[i];
        elements[i] = NULL;
    }
    delete[] elements;
    elements = NULL;
}
Matrix::Matrix(const Matrix & a)
{
    m = a.m;
    n = a.n;
    elements = new double *[m]; // cấp phát m dòng
    for (int i = 0; i<m; i++)
        elements[i] = new double[n]; // cấp phát n cột
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            elements[i][j] = a.elements[i][j];
}
 
void Matrix::Nhap()
{
    cin >> m >> n;
    elements = new double * [m]; // cấp phát m dòng
    for (int i=0; i<m; i++)
        elements[i] = new double [n]; // cấp phát n cột
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> elements[i][j];
}
void Matrix::Xuat()
{
    cout << "Matrix: \n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << elements[i][j] << " ";
        cout << endl;
    }
}

int Matrix::Cong(const Matrix & a)
{
    if (!(n == a.n && m == a.m))
        return 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            elements[i][j] += a.elements[i][j];
    return 1;
}
void Matrix::Nhan(const double & k)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            elements[i][j] *= k;
}
 
int Matrix::Nhan(const Matrix & a)
{
    if (n != a.m)
        return 0;
 
    double ** elementsNew = new double *[m]; // tạo vùng nhớ chứa ma trận mới
    for (int i = 0; i < m; i++)
        elementsNew[i] = new double[a.n];
 
    for (int i = 0; i < m; i++) // nhân
    {
        for (int j = 0; j < a.n; j++)
        {
            elementsNew[i][j] = 0;
            for (int k = 0; k < n; k++)
                elementsNew[i][j] = elementsNew[i][j] + elements[i][k] * a.elements[k][j];            
        }
    }
    // xóa vùng nhớ cũ
    for (int i = 0; i < m; i++)
        delete[] elements[i];
    delete[] elements;
    // cập nhật lại kích thước ma trận
    m = m;
    n = a.n;
    elements = elementsNew; // gán lại vùng nhớ mới.
    return 1;
}

Vector multiply(const Matrix &a, const Vector &b)
{
    if (a.n != b.n)
    {
        cout << "Ko nhan duoc!\n";
        return Vector(0, 0);
    }
    Vector res(a.m, 0);
    res.n = a.m;
    for (int i = 0; i < a.m; i++)
    {
        res.coords[i] = 0;
        for (int j = 0; j < b.n; j++)
            res.coords[i] = res.coords[i] + b.coords[j] * a.elements[i][j];
    }
    return res;
}
 
 
int main()
{
    Matrix C;
    C.nhap();
 
    Vector D;
    D.nhap();
 
    Vector RES = multiply(C, D);
 
    RES.xuat();
 
    system("pause");
    return 0;
}