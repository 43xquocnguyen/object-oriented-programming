#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Diem
{
private:
    float hoanhDo, tungDo;
public:
    Diem();
    Diem(float, float);
    ~Diem();

    void Nhap();
    void Xuat();
    float getHoanhDo();
    float getTungDo();
    void setHoanhDo(float hoanhDo);
    void setTungDo(float tungDo);
    void TinhTien(float, float);
};

Diem::Diem()
{
    this->hoanhDo = 0;
    this->tungDo = 0;
}
Diem::Diem(float hoanhDo, float tungDo)
{
    this->hoanhDo = hoanhDo;
    this->tungDo = tungDo;
}
Diem::~Diem()
{
}

void Diem::Nhap() {
    do
    {
        cout << "NHAP HOANH DO: ";
        cin >> this->hoanhDo;
        if (cin.fail()) {
            cout << "HOANH DO KHONG HOP LE\n";
        }
    } while (cin.fail());

    do
    {
        cout << "NHAP TUNG DO: ";
        cin >> this->tungDo;
        if (cin.fail()) {
            cout << "TUNG DO KHONG HOP LE\n";
        }
    } while (cin.fail());
    
}
void Diem::Xuat() {
    cout << "(" << this->hoanhDo << ";" << this->tungDo << ")";
}
float Diem::getHoanhDo() { return this->hoanhDo; }
float Diem::getTungDo() { return this->tungDo; }
void Diem::setHoanhDo(float hoanhDo) {
    this->hoanhDo = hoanhDo;
}
void Diem::setTungDo(float tungDo) {
    this->tungDo = tungDo;
}
void Diem::TinhTien(float a, float b) {
    this->hoanhDo += a;
    this->tungDo += b;
}

void Program(vector<Diem*> *list)
{
    list = new vector<Diem*>;
    while (true)
    {
        system("cls");
        cout << "1. NHAP MOT DIEM\n";
        cout << "2. XUAT CAC DIEM\n";
        cout << "3. THAY DOI THANH PHAN DU LIEU\n";
        cout << "4. XEM THANH PHAN DU LIEU\n";
        cout << "5. TINH TIEN MOT DIEM\n";
        cout << "0. KET THUC\n";
        cout << "\nNHAP VAO LUA CHON CUA BAN: ";
        char lc;
        cin >> lc;
        cin.ignore();

        if (lc == '0') {
            system("cls");
            cout << "CHUONG TRINH KET THUC\n";
            break;
            system("pause");
        }
        else if (lc == '1') {
            system("cls");
            Diem *a = new Diem;
            a->Nhap();
            list->push_back(a);
            cout << "THEM 1 DIEM THANH CONG\n";
            system("pause");
        }
        else if (lc == '2') {
            system("cls");
            int size = list->size();
            for (int i = 0; i < size; i++)
            {
                cout << (char)(i + 65);
                list->at(i)->Xuat();
                cout << endl;
            }
            system("pause");
        }
        else if (lc == '3') {
            system("cls");
            int i;
            int max = list->size();
            do
            {
                cout << "NHAP VI TRI DIEM: ";
                cin >> i;
                if (i <= 0 || i > max)
                {
                    cout << "VI TRI KHONG HOP LE!\n";
                }
                
            } while (i <= 0 || i > max);
            i--;
            int data;
            cout << "NHAP GIA TRI: ";
            cin >> data;
            while (true)
            {
                system("cls");
                cout << "1. THAY DOI HOANH DO\n";
                cout << "2. THAY DOI TUNG DO\n";
                cout << "0. THOAT\n";
                cout << "\nNHAP VAO LUA CHON CUA BAN: ";
                char lc2;
                cin >> lc2;
                cin.ignore();

                if (lc2 == '0') {
                    break;
                }
                else if (lc2 == '1') {
                    system("cls");
                    list->at(i)->setHoanhDo(data);
                    cout << "DA THAY DOI THANH CONG\n";
                    system("pause");
                }
                else if (lc2 == '2') {
                    system("cls");
                    list->at(i)->setTungDo(data);
                    cout << "DA THAY DOI THANH CONG\n";
                    system("pause");
                }
                else {
                    system("cls");
                    cout << "LUA CHON KHONG HOP LE\n";
                    system("pause");
                }
            }
        }
        else if (lc == '4') {
            system("cls");
            int i;
            int max = list->size();
            do
            {
                cout << "NHAP VI TRI DIEM: ";
                cin >> i;
                if (i <= 0 || i > max)
                {
                    cout << "VI TRI KHONG HOP LE!\n";
                }
                
            } while (i <= 0 || i > max);
            i--;
            while (true)
            {
                system("cls");
                cout << "1. HOANH DO\n";
                cout << "2. TUNG DO\n";
                cout << "0. THOAT\n";
                cout << "\nNHAP VAO LUA CHON CUA BAN: ";
                char lc2;
                cin >> lc2;
                cin.ignore();

                if (lc2 == '0') {
                    break;
                }
                else if (lc2 == '1') {
                    system("cls");
                    cout << "HOANH DO: " << list->at(i)->getHoanhDo();
                    system("pause");
                }
                else if (lc2 == '2') {
                    system("cls");
                    cout << "TUNG DO: " << list->at(i)->getTungDo();
                    system("pause");
                }
                else {
                    system("cls");
                    cout << "LUA CHON KHONG HOP LE\n";
                    system("pause");
                }
            }
        }
        else if (lc == '5') {
            system("cls");
            float x, y;
            cout << "NHAP VECTOR(a, b) CAN TINH TIEN\n";
            cout << "NHAP a: ";
            cin >> x;
            cout << "NHAP b: ";
            cin >> y;
            int n = list->size();
            for (int i = 0; i < n; i++)
            {
                list->at(i)->TinhTien(x, y);
            }
            system("cls");
            cout << "CAC DIEM SAU KHI TINH TIEN LA\n";
            for (int i = 0; i < n; i++)
            {
                cout << (char)(i + 65);
                list->at(i)->Xuat();
                cout << endl;
            }
            cout << endl;
            system("pause");
        }
        else {
            system("cls");
            cout << "LUA CHON KHONG HOP LE\nKIEM TRA LAI\n";
            system("pause");
        }
    }
}

int main()
{
    vector<Diem*> *list;
    Program(list);
    return 0;
}