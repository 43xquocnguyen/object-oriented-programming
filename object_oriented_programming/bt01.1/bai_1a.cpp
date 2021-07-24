#include <iostream>
#include <vector>
using namespace std;

class Mang
{
private:
    vector<int> mang;
public:
    Mang();
    ~Mang();
    void ThemPhanTu();
    void SapXep();
    void XuatMang();
};
Mang::Mang()
{
}
Mang::~Mang() {

}

void Mang::ThemPhanTu() {
    int data;
    cout << "NHAP VAO DU LIEU SO NGUYEN: ";
    cin >> data;
    mang.push_back(data);
}
void Mang::SapXep() {
    int size = mang.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j ++) {
            if (mang.at(i) > mang.at(j))
            {
                swap(mang.at(i), mang.at(j));
            }
        }
    }
}
void Mang::XuatMang() {
    int size = mang.size();
    for (int i = 0; i < size; i++) {
        cout << mang.at(i) << "\t";
    }
}

void MENU(Mang *a) {
    a = new Mang;
    while (true)
    {
        system("cls");
        cout << "1. THEM PHAN TU\n";
        cout << "2. XUAT MANG\n";
        cout << "0. KET THUC\n\n";
        cout << "NHAP LUA CHON CUA BAN: ";
        char luachon;
        cin >> luachon;
        cin.ignore();

        if (luachon == '1') {
            system("cls");
            a->ThemPhanTu();
        }
        else if (luachon == '2') {
            system("cls");
            a->SapXep();
            cout << "MANG LA: ";
            a->XuatMang();
            cout << endl;
            system("pause");
        }
        else {
            system("cls");
            cout << "LUA CHON KHONG HOP LE! THU LAI\n";
            system("pause");
        }
    }
    delete a;
}
int main() {
    Mang *a;
    MENU(a);
    return 0;
}