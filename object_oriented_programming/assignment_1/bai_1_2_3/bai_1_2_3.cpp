#include "phan_so.h"

void MENU(PhanSo *a, PhanSo *b)
{
    a = new PhanSo();
    b = new PhanSo();
    while (true)
    {
        system("cls");
        cout << "1. NHAP 2 PHAN SO\n";
        cout << "2. XUAT 2 PHAN SO\n";
        cout << "3. RUT GON 2 PHAN SO\n";
        cout << "4. SO SANH 2 PHAN SO\n";
        cout << "5. TINH TONG\n";
        cout << "6. TINH HIEU\n";
        cout << "7. TINH TICH\n";
        cout << "8. TINH THUONG\n";
        cout << "0. KET THUC\n";
        cout << "\nNHAP VAO LUA CHON CUA BAN: ";

        char luachon;
        cin >> luachon;
        cin.ignore(32767, '\n');

        if (luachon == '0')
        {
            system("cls");
            cout << "CHUONG TRINH KET THUC\n";
            system("pause");
            break;
        }

        switch (luachon)
        {
        case '1':
        {
            system("cls");
            cout << "NHAP VAO PHAN SO THU NHAT\n";
            a->NhapPhanSo();
            system("cls");
            cout << "NHAP VAO PHAN SO THU HAI\n";
            b->NhapPhanSo();
            break;
        }
        case '2':
        {
            system("cls");
            if (!a->KiemTraDaNhap() || !b->KiemTraDaNhap())
            {
                cout << "KHONG TIM THAY DU LIEU CUA HAI PHAN SO!\n";
            }
            else
            {
                cout << "PHAN SO THU NHAT: ";
                a->XuatPhanSo();
                cout << "\n";
                cout << "PHAN SO THU HAI: ";
                b->XuatPhanSo();
                cout << "\n";
            }
            system("pause");
            break;
        }
        case '3':
        {
            system("cls");
            if (!a->KiemTraDaNhap() || !b->KiemTraDaNhap())
            {
                cout << "KHONG TIM THAY DU LIEU CUA HAI PHAN SO!\n";
            }
            else
            {
                cout << "PHAN SO THU NHAT SAU KHI RUT GON: ";
                a->RutGonPhanSo();
                a->XuatPhanSo();
                cout << "\n";
                cout << "PHAN SO THU HAI SAU KHI RUT GON: ";
                b->RutGonPhanSo();
                b->XuatPhanSo();
                cout << "\n";
            }
            system("pause");
            break;
        }
        case '4':
        {
            system("cls");
            if (!a->KiemTraDaNhap() || !b->KiemTraDaNhap())
            {
                cout << "KHONG TIM THAY DU LIEU CUA HAI PHAN SO!";
            }
            else
            {
                cout << "PHAN SO LON HON LA: ";
                if (a->SoSanhPhanSo(b))
                {
                    a->XuatPhanSo();
                }
                else
                {
                    b->XuatPhanSo();
                }
            }
            cout << endl;
            system("pause");
            break;
        }
        case '5':
        {
            system("cls");
            if (!a->KiemTraDaNhap() || !b->KiemTraDaNhap())
            {
                cout << "KHONG TIM THAY DU LIEU CUA HAI PHAN SO";
            }
            else
            {
                PhanSo *kq = new PhanSo();
                *kq = a->TinhTong(*b);
                cout << "KET QUA: ";
                kq->XuatPhanSo();
            }
            cout << "\n";
            system("pause");
            break;
        }
        case '6':
        {
            system("cls");
            if (!a->KiemTraDaNhap() || !b->KiemTraDaNhap())
            {
                cout << "KHONG TIM THAY DU LIEU CUA HAI PHAN SO";
            }
            else
            {
                PhanSo *kq = new PhanSo();
                *kq = a->TinhHieu(*b);
                cout << "KET QUA: ";
                kq->XuatPhanSo();
                delete kq;
            }
            cout << "\n";
            system("pause");
            break;
        }
        case '7':
        {
            system("cls");
            if (!a->KiemTraDaNhap() || !b->KiemTraDaNhap())
            {
                cout << "KHONG TIM THAY DU LIEU CUA HAI PHAN SO";
            }
            else
            {
                if (b->getTuSo() == 0 || a->getTuSo() == 0) {
                    cout << 0;
                }
                else {
                    PhanSo *kq = new PhanSo();
                    *kq = a->TinhTich(*b);
                    cout << "KET QUA: ";
                    kq->XuatPhanSo();
                    delete kq;
                }
            }
            cout << "\n";
            system("pause");
            break;
        }
        case '8':
        {
            system("cls");
            if (!a->KiemTraDaNhap() || !b->KiemTraDaNhap())
            {
                cout << "KHONG TIM THAY DU LIEU CUA HAI PHAN SO";
            }
            else
            {
                if (b->getTuSo() == 0) {
                    cout << "KHONG THE CHIA 2 PHAN SO";
                }
                else {
                    PhanSo *kq = new PhanSo();
                    *kq = a->TinhThuong(*b);
                    cout << "KET QUA: ";
                    kq->XuatPhanSo();
                    delete kq;
                }
                
            }
            cout << "\n";
            system("pause");
            break;
        }
        default:
            {
                system("cls");
                cout << "LUA CHON CUA BAN KHONG HOP LE! VUI LONG THU LAI\n";
                system("pause");
            }
        }
    }
    delete a;
    delete b;
}
int main()
{
    PhanSo *a, *b;
    MENU(a, b);
    return 0;
}