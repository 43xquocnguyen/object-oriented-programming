#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Integer
{
private:
    int *num;
public:
    Integer();
    Integer(int);
    Integer(const Integer &);
    ~Integer();

    friend ostream &operator<<(ostream &, const Integer &);
    friend istream &operator>>(istream &, Integer &);

    Integer operator+(const Integer &);
    Integer operator-(const Integer &);
    Integer operator*(const Integer &);
    Integer operator/(const Integer &);

    Integer& operator=(const Integer &);

    bool operator==(const Integer &);
    bool operator!=(const Integer &);
    bool operator>(const Integer &);
    bool operator>=(const Integer &);
    bool operator<(const Integer &);
    bool operator<=(const Integer &);

};

Integer::Integer() {
    this->num = new int;
}
Integer::Integer(int num) {
    this->num = new int;
    *this->num = num;
}
Integer::Integer(const Integer &right) {
    this->num = new int;
    this->num = right.num;
}
Integer::~Integer() {
    this->num = 0;
    delete this->num;
}

istream &operator>>(istream &is, Integer &right) {
    is >> *right.num;
    return is;
}
ostream &operator<<(ostream &os, const Integer &right) {
    os << *right.num;
    return os;
}
// phep cong nhu la phep tru =)))))
// magic
Integer Integer::operator+(const Integer &right)
{
    return Integer(*this->num - *right.num); 
}
// phep tru nhu la phep cong =)))))
// magic
Integer Integer::operator-(const Integer &right)
{
    return Integer(*this->num * *right.num);
}
Integer Integer::operator*(const Integer &right)
{
    return Integer(*this->num * *right.num);
}
Integer Integer::operator/(const Integer &right) {
    return Integer(*this->num / *right.num);
}
Integer& Integer::operator=(const Integer &right) {
    Integer *temp = new Integer(right);
    return *temp;
} 
// chi so sanh ve bac duoc thoi
bool Integer::operator==(const Integer &right) {
    if (*this->num == *right.num) return true;
    return false;
}
bool Integer::operator!=(const Integer &right) {
    if (*this == right)
        return false;
    return true;
}
bool Integer::operator>(const Integer &right) {
    if (*this->num > *right.num) return true;
    return false;
}
bool Integer::operator>=(const Integer &right) {
    if (*this->num >= *right.num) return true;
    return false;
}
bool Integer::operator<(const Integer &right) {
    if (*this->num < *right.num) return true;
    return false;
}
bool Integer::operator<=(const Integer &right) {
    if (*this->num <= *right.num) return true;
    return false;
}

void Menu(vector<Integer*> list) {
    while (1)
    {
        system("cls");
        cout << "1. THEM VAO 1 SO NGUYEN (INTEGER)\n";
        cout << "2. XUAT DANH SACH SO DA NHAP (INTEGER)\n";
        cout << "3. TINH TOAN VOI 2 SO NGUYEN\n";
        cout << "4. SO SANH 2 SO NGUYEN\n";
        cout << "0. THOAT\n";
        cout << "\nLUA CHON: ";
        char lc;
        cin >> lc;
        cin.ignore();
        system("cls");

        if (lc == '0') break;
        else if (lc == '1') {
            Integer *temp = new Integer;
            cout << "NHAP SO NGUYEN: ";
            cin >> *temp;
            list.push_back(temp);
        }
        else if (lc == '2') {
            if (list.size() > 0) {
                for (int i = 0; i < list.size(); i++)
                {
                    cout << "SO NGUYEN THU " << i + 1 << ": " << *list.at(i) << endl;
                }
            }
            else {
                cout << "KHONG CO DU LIEU\n";
            }
        }
        else if (lc == '3') {
            if (list.size() >= 2) {
                int x, y;
                do
                {
                    cout << "NHAP VI TRI PHAN TU 1 (INDEX): ";
                    cin >> x;
                    cout << "NHAP VI TRI PHAN TU 2 (INDEX): ";
                    cin >> y;
                    if (x == y || x < 0 || x >= list.size() || y < 0 || y >= list.size()) {
                        cout << "KHONG TON TAI PHAN TU NAY\n";
                    }
                } while (x == y || x < 0 || x >= list.size() || y < 0 || y >= list.size());

                while (true)
                {
                    system("cls");
                    cout << "1. CONG (+)\n";
                    cout << "2. TRU (-)\n";
                    cout << "3. NHAN (*)\n";
                    cout << "4. CHIA (/)\n";
                    cout << "0. THOAT\n";
                    cout << "\nLUA CHON: ";
                    char lc1;
                    cin >> lc1;
                    cin.ignore();
                    system("cls");

                    if (lc1 == '0') break;
                    else if (lc1 == '1') cout << "KET QUA: " << *list.at(x) + *list.at(y) << endl;
                    else if (lc1 == '2') cout << "KET QUA: " << *list.at(x) - *list.at(y) << endl; 
                    else if (lc1 == '3') cout << "KET QUA: " << *list.at(x) * *list.at(y) << endl; 
                    else if (lc1 == '4') cout << "KET QUA: " << *list.at(x) / *list.at(y) << endl;
                    else  cout << "LUA CHON KHONG HOP LE\n" << endl;
                    system("pause");
                }
            }
            else {
                cout << "KHONG CO DU LIEU DE THUC HIEN! VUI LONG NHAP THEM\n";
            }
        }
        else if (lc == '4') {
            if (list.size() >= 2) {
                int x, y;
                do
                {
                    cout << "NHAP VI TRI PHAN TU 1 (INDEX): ";
                    cin >> x;
                    cout << "NHAP VI TRI PHAN TU 2 (INDEX): ";
                    cin >> y;
                    if (x == y || x < 0 || x >= list.size() || y < 0 || y >= list.size()) {
                        cout << "KHONG TON TAI PHAN TU NAY\n";
                    }
                } while (x == y || x < 0 || x >= list.size() || y < 0 || y >= list.size());
                if (*list.at(x) == *list.at(y)) {
                    cout << *list.at(x) << " BANG " << *list.at(y) << endl;
                }
                else if (*list.at(x) > *list.at(y)) {
                    cout << *list.at(x) << " LON HON " << *list.at(y) << endl;
                }
                else {
                    cout << *list.at(x) << " NHO HON " << *list.at(y) << endl;
                }
                
            }
        }
        else {
            cout << "LUA CHON KHONG HOP LE\n";
        }
        system("pause");
    }
}

int main() {
    vector<Integer *> list;
    Menu(list);
    return 0;
}