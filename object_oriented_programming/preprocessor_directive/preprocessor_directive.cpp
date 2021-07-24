// ------------ Preprocessor directive: Tiền xử lí ------------ //

// Tránh đụng độ thư viện
#pragma once

// ------------------------ //
// Xử lí xung đột khi include file này qua các file khác
// Nếu nó được include & define rồi thì k define & include lại nữa
// Tránh xung đột library
// #ifdef (nếu đã define), #ifndef (nếu chưa define)
// #endif (end)
#ifndef __FileNay__ 
// ------------------------ //

#include <iostream>
using namespace std;

// ------------------------ //
#define DEBUG // điều kiện biên dịch code

// Define macro
// #define identifier replacement-list
// #undef identifier (Xóa đi cái đã define trước đó)
#define String int
#undef String
#define String string

// Define macro có tham số
#define clear (system("cls"))
#define Min(a, b) (((a) < (b)) ? a : b)
#define Loop(n) (for (int i = 0; i < n; i++))
#define QTM(x) #x // thay thế (x) = ("x")
// ------------------------ //

// #if, #elif, #else (Điều kiện biên dịch)

int main()
{
    int i, j;
    i = 35;
    j = 16;

    cout << QTM(Lap trinh C++) << endl; // = cout << "Lap trinh C++" << endl;

#ifdef DEBUG
    cerr << "Trace: Ben trong ham main!" << endl;
#endif

#if 0
    /* Day la phan comment */
    cout << Lap trinh C++ << endl;
#endif

    cout << "Gia tri nho nhat la " << Min(i, j) << endl;

#ifdef DEBUG
    cerr << "Trace: Ben ngoai ham main!" << endl;
#endif

	cout << "Gia tri cua __LINE__ la: " << __LINE__ << endl; // số line định nghĩa
	cout << "Gia tri cua __FILE__ la: " << __FILE__ << endl; // tên file biên dịch
	cout << "Gia tri cua __DATE__ la: " << __DATE__ << endl; // ngày source code được biên dịch
	cout << "Gia tri cua __TIME__ la: " << __TIME__ << endl; // thời gian chương trình biên dịch
    // cout << "Gia tri cua __STDC__ la: " << __STDC__ << endl; // được định nghĩa là 1 khi bộ biên dịch biên dịch với chuẩn ANSI

    return 0;
}


#endif // (end) #ifndef __FileNay__ 