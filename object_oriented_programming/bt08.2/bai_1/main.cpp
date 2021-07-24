#include "nhan_vien.h"
#include "nv_san_xuat.h"
#include "nv_van_phong.h"
#include <vector>

void NhapNNhanVien(int n, vector<NhanVien*> *list) {

    do
    {
        cout << "NHAP SO LUONG NHAN VIEN: ";
        cin >> n;
        if (n <= 0) cout << "SO LUONG NHAN VIEN KHONG HOP LE\n";
    } while (n <= 0);
    for (int i = 0; i < n; i++)
    {
        system("cls");
        cout << "NHAP THONG TIN NHAN VIEN THU " << i + 1 << endl;
        while (true)
        {
            system("cls");
            cout << "1. NHAN VIEN VAN PHONG\n";
            cout << "2. NHAN VIEN SAN XUAT\n";
            cout << "\nLOAI NHAN VIEN: ";
            char lc;
            cin.ignore();
            cin >> lc;

            if (lc == '1') {
                system("cls");
                NhanVien* temp = new NVVanPhong;
                temp->Input();
                list->push_back(temp);
                break;
            }
            if (lc == '2') {
                system("cls");
                NhanVien* temp = new NVSanXuat;
                temp->Input();
                list->push_back(temp);
                break;
            }
            else {
                system("cls");
                cout << "KHONG HOP LE\n";
                system("pause");
            }
        }
    }
}
void XuatNVVP(vector<NhanVien*>* list) {
    cout << "\t\t\t\t\tBANG NHAN VIEN VAN PHONG\n\n";
    int size = list->size();
    cout << setw(25) << left << "HO VA TEN";
    cout << setw(25) << left << "NGAY THANG NAM SINH";
    cout << setw(15) << left << "SO NGAY LAM";
    cout << setw(25) << left << "LUONG" << endl;
    cout << setfill('-') << setw(105) << "-" << endl;
    cout << setfill(' ');
    for (int i = 0; i < size; i++)
    {
        if (!list->at(i)->check) {
            list->at(i)->Output();
            cout << endl;
        }
    }
}
void XuatNVSX(vector<NhanVien*>* list) {
    cout << "\n\n\n\t\t\t\t\tBANG NHAN VIEN SAN XUAT\n\n";
    int size = list->size();
    cout << setw(25) << left << "HO VA TEN";
    cout << setw(25) << left << "NGAY THANG NAM SINH";
    cout << setw(25) << left << "LUONG CAN BAN";
    cout << setw(25) << left << "SO SAN PHAM";
    cout << setw(25) << left << "LUONG" << endl;
    cout << setfill('-') << setw(105) << "-" << endl;
    cout << setfill(' ');
    for (int i = 0; i < size; i++)
    {
        if (list->at(i)->check) {
            list->at(i)->Output();
            cout << endl;
        }
    }
}
void XuatLuongCaoNhatVaThapNhat(vector<NhanVien*>* list) {
    int size = list->size();
    long max = list->at(0)->getLuong();
    long min = list->at(0)->getLuong();
    int vtmax = 0, vtmin = 0;
    for (int i = 1; i < size; i++)
    {
        if (max < list->at(i)->getLuong()) {
            max = list->at(i)->getLuong();
            vtmax = i;
        }
        if (min > list->at(i)->getLuong()) {
            min = list->at(i)->getLuong();
            vtmin = i;
        }
    }
    vector<NhanVien*>* list_temp = new vector<NhanVien*>;
    list_temp->push_back(list->at(vtmax));
    list_temp->push_back(list->at(vtmin));
    cout << "\n\n\n\nLUONG 2 NHAN VIEN THAP NHAT VA CAO NHAT LA:\n";
    XuatNVSX(list_temp);
    XuatNVVP(list_temp);
}

int main()
{
    vector<NhanVien*> *list;
    list = new vector<NhanVien*>;
    int n = 0;
    NhapNNhanVien(n, list);
    system("cls");
    XuatNVVP(list);
    XuatNVSX(list);
    XuatLuongCaoNhatVaThapNhat(list);
    return 0;
}