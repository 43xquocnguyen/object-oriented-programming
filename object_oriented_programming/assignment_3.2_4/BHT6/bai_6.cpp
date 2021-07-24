#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 1000

class String
{
private:
    char *s;
    int len;
    
public:
    String();
    String(int);
    String(char*);
    String(const String &);
    ~String();
    int Length();

    friend ostream &operator<<(ostream &, const String &);
    friend istream &operator>>(istream &, String &);

    String operator+(const String &);
    String operator+=(const String &);
    String operator=(const String &);

    bool operator==(const String &);
    bool operator!=(const String &);
    bool operator>(const String &);
    bool operator>=(const String &);
    bool operator<(const String &);
    bool operator<=(const String &);

};

String::String() {
    this->s = NULL;
    this->len = 0;
}
String::String(int len) {
    this->len = len;
    this->s = new char[this->len];
}
String::String(char *s) {
    int i = 0;
    while (s[i] != '\0') i++;
    this->len = i;
    this->s = new char[this->len];
    for (int j = 0; j < len; j++)
    {
        this->s[j] = s[j];
    }
}
String::String(const String &right) {
    this->len = right.len;
    this->s = new char[this->len];
    for (int i = 0; i < this->len; i++)
    {
        this->s[i] = right.s[i];
    }
}
String::~String() {
    this->len = 0;
    delete[] this->s;
}

int String::Length() { return this->len; }

ostream &operator<<(ostream &os, const String &right) {
    os << right.s;
    return os;
}
istream &operator>>(istream &is, String &right) {
    char temp[MAX];
    is.getline(temp, MAX);
    right.s = new char[strlen(temp)];
    strcpy(right.s, temp);
    right.len = strlen(right.s);
    return is;
}

String String::operator+(const String &right)
{
    String temp;
    temp.len = this->len + right.len;
    temp.s = new char[this->len + right.len];
    strcpy(temp.s, this->s);
    strcat(temp.s, right.s);
    /*
    String temp(this->len + right.len);
    temp.s = new char[this->len + right.len];
    temp.len = this->len + right.len;
    int i = 0;

    for (; i < this->len; i++)
    {
        temp.s[i] = this->s[i];
    }
    int j = 0;
    for (; i < this->len + right.len; i++)
    {
        temp.s[i] = right.s[j++];
    }
    temp.s[i] = '\0';
    */
    return temp;
}
String String::operator=(const String &right) {
    String temp;
    temp.len = right.len;
    strcpy(temp.s, right.s);
    return temp;
}
String String::operator+=(const String &right)
{
    strcat(this->s, right.s);
    this->len += right.len;
    return *this;
}
bool String::operator==(const String &right) {
    int max = this->len > right.len ? this->len : right.len;
    for (int i = 0; i < max; i++)
    {
        if (this->s[i] != right.s[i]) return false;
    }
    return true;
}
bool String::operator!=(const String &right) {
    if (*this == right)
        return false;
    return true;
}
bool String::operator>(const String &right) {
    int max = this->len > right.len ? this->len : right.len;
    for (int i = 0; i < max; i++)
    {
        if (this->s[i] <= right.s[i]) return false;
    }
    return true;
}
bool String::operator>=(const String &right) {
    if (*this > right) return false;
    return true;
}
bool String::operator<(const String &right) {
    if (*this >= right) return false;
    return true;
}
bool String::operator<=(const String &right) {
    if (*this > right) return false;
    return true;
}

void Menu(vector<String*> list) {
    while (1)
    {
        system("cls");
        cout << "1. THEM VAO 1 CHUOI (STRING)\n";
        cout << "2. XUAT RA DANH SACH CHUOI DA NHAP (STRING)\n";
        cout << "3. NOI 2 CHUOI\n";
        cout << "4. SO SANH 2 CHUOI\n";
        cout << "0. THOAT\n";
        cout << "\nLUA CHON: ";
        char lc;
        cin >> lc;
        cin.ignore();
        system("cls");

        if (lc == '0') break;
        else if (lc == '1') {
            cout << "NHAP CHUOI: ";
            String *temp = new String;
            cin >> *temp;
            list.push_back(temp);
        }
        else if (lc == '2') {
            if (list.size() > 0) {
                for (int i = 0; i < list.size(); i++)
                {
                    cout << "CHUOI THU " << i + 1 << ": " << *list.at(i) << endl;
                }
            }
            else {
                cout << "KHONG CO DU LIEU\n";
            }
        }
        else if (lc == '3') {
            if (list.size() > 1) {
                int vt1, vt2;
                do
                {
                    cout << "NHAP VI TRI PHAN TU DAU(INDEX): ";
                    cin >> vt1;
                    cout << "NHAP VI TRI PHAN TU CUOI(INDEX): ";
                    cin >> vt2;
                    if (vt1 < 0 || vt1 >= list.size() || vt2 < 0 || vt2 >= list.size()) {
                        cout << "KHONG TON TAI! VUI LONG KIEM TRA LAI\n";
                    }
                } while (vt1 < 0 || vt1 >= list.size() || vt2 < 0 || vt2 >= list.size());
                String result = *list.at(vt1) + *list.at(vt2);
                cout << "\nKET QUA SAU KHI NOI: " << result << endl;
            }
            else {
                cout << "KHONG CO DU LIEU\n";
            }
        }
        else if (lc == '4') {
            if (list.size() >= 2) {
                int x, y;
                do
                {
                    cout << "NHAP VI TRI PHAN TU 1: ";
                    cin >> x;
                    cout << "NHAP VI TRI PHAN TU 2: ";
                    cin >> y;
                    if (x == y || x < 0 || x >= list.size() || y < 0 || y >= list.size()) {
                        cout << "KHONG TON TAI PHAN TU NAY\n";
                    }
                } while (x == y || x < 0 || x >= list.size() || y < 0 || y >= list.size());
                if (*list.at(x) == *list.at(y)) cout << "HAI CHUOI NAY BANG NHAU" << endl;
                else if (*list.at(x) > *list.at(y)) 
                    cout << *list.at(x) << " LON HON " << *list.at(y) << endl;
                else cout << *list.at(x) << " NHO HON " << *list.at(y) << endl;
            }
            else {
                cout << "KHONG CO DU LIEU\n";
            }
        }
        else {
            cout << "LUA CHON KHONG HOP LE\n";
        }
        system("pause");
    }
}

int main() {
    //vector<String *> list;
    //Menu(list);
    String a, b;
    cin >> a;
    cin >> b;
    a += b;
    cout << a;
    return 0;
}