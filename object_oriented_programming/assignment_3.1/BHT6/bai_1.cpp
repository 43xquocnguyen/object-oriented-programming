// #include <iostream>
// #include <cmath>
// using namespace std;

// class Complex
// {
// private:
//     int real, imag;
// public:
//     Complex();
//     Complex(int, int);
//     Complex(const Complex&);
//     ~Complex();

//     ostream &operator<<(ostream &os, const Complex &dt);
// };

// Complex::Complex() {
//     this->real = 0;
//     this->vir = 0;
// }
// Complex::Complex(int hour, int minute, int second) {
//     this->hour = hour;
//     this->minute = minute;
//     this->second = second;
// }
// Complex::~Complex() { }
// void Complex::Input() {
//     do
//     {
//         cout << "NHAP GIO: ";
//         cin >> this->hour;
//         if (this->hour < 0) {
//             cout << "GIO KHONG HOP LE\n";
//         }
//         if (cin.fail()) {
//             cin.clear();
//             cin.ignore(32767, '\n');
//             this->hour = -1;
//         }
//     } while (this->hour < 0);

//     do
//     {
//         cout << "NHAP PHUT: ";
//         cin >> this->minute;
//         if (this->minute < 0 || this->minute >= 60) {
//             cout << "PHUT KHONG HOP LE\n";
//         }
//         if (cin.fail()) {
//             cin.clear();
//             cin.ignore(32767, '\n');
//             this->minute = -1;
//         }
//     } while (this->minute < 0 || this->minute >= 60);

//     do
//     {
//         cout << "NHAP GIAY: ";
//         cin >> this->second;
//         if (this->second < 0 || this->second >= 60) {
//             cout << "GIAY KHONG HOP LE\n";
//         }
//         if (cin.fail()) {
//             cin.clear();
//             cin.ignore(32767, '\n');
//             this->second = -1;
//         }
//     } while (this->second < 0 || this->second >= 60);

//     this->check = true;
// }
// void Complex::Output() {
//     if (this->hour < 10) cout << 0 << this->hour << ":";
//     else cout << this->hour << ":";
//     if (this->minute < 10) cout << 0 << this->minute << ":";
//     else cout << this->minute << ":";
//     if (this->second < 10) cout << 0 << this->second;
//     else cout << this->second;
// }
// Complex Complex::Add2Complex(Complex t) {
//     int a, b, c;
//     a = this->second + t.second;
//     b = this->minute + t.minute;
//     c = this->hour + t.hour;
//     while (a >= 60)
//     {
//         a -= 60;
//         b++;
//     }
//     while (b >= 60)
//     {
//         b -= 60;
//         a++;
//     }
//     return Complex(c, b, a);
// }
// bool Complex::CheckInput() {
//     return this->check  ;
// }

// void MENU(Complex *a) {
//     a = new Complex();
//     while (true)
//     {
//         system("cls");
//         cout << "1. NHAP THOI GIAN\n";
//         cout << "2. XUAT THOI GIAN\n";
//         cout << "3. CONG THOI GIAN\n";
//         cout << "4. KET THUC\n";
//         cout << "\nNHAP VAO LUA CHON CUA BAN: ";
//         char luachon;
//         cin >> luachon;

//         if (luachon == '4') {
//             system("cls");
//             cout << "CHUONG TRINH KET THUC\n";
//             system("pause");
//             break;
//         }

//         else if (luachon == '1') {
//             system("cls");
//             cout << "NHAP THOI GIAN:\n";
//             a->Input();
//         }

//         else if (luachon == '2') {
//             if(a->CheckInput()) {
//                 system("cls");
//                 a->Output();
//                 cout << "\n";
//                 system("pause");
//             }
//             else {
//                 system("cls");
//                 cout << "DU LIEU CHUA DUOC NHAP! VUI LONG KIEM TRA LAI\n";
//                 system("pause");
//             }
//         }

//         else if (luachon == '3') {
//             if(a->CheckInput()) {
//                 system("cls");
//                 Time *b = new Time;
//                 cout << "NHAP THOI GIAN CAN CONG: \n";
//                 b->Input();
//                 Time c = a->Add2Time(*b);
//                 cout << "THOI GIAN CONG LA: ";
//                 c.Output();
//                 system("pause");
//             }
//             else {
//                 system("cls");
//                 cout << "DU LIEU CHUA DUOC NHAP! VUI LONG KIEM TRA LAI\n";
//                 system("pause");
//             }
//         }

//         else {
//             cout << "LUA CHON KHONG HOP LE\n! THU LAI";
//         }
//     }
//     delete a;
// }
// int main() {
//     Time *a;
//     MENU(a);
//     return 0;
// }