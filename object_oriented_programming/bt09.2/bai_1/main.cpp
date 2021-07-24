#include "truong.h"

void Menu(Truong *UIT) {
	while (true)
	{
		system("cls");
		cout << "1. NHAP SINH VIEN\n";
		cout << "2. XUAT DS SINH VIEN\n";
		cout << "3. SO SV DU DIEU KIEN TOT NGHIEP\n";
		cout << "4. SINH VIEN DH VA CD CO DIEM TB CAO NHAT\n";
		cout << "0. THOAT\n";
		cout << "\nLUA CHON: ";
		char lc;
		cin >> lc;
		cin.ignore();
		system("cls");

		if (lc == '0') break;
		else if (lc == '1') {
			int n;
			do
			{
				cout << "NHAP SO LUONG: ";
				cin >> n;
				if (n <= 0) cout << "SO LUONG KHONG HOP LE\n";
			} while (n <= 0);
			UIT->Input(n);
		}
		else if (lc == '2') {
			UIT->Output();
		}
		else if (lc == '3') {
			cout << "SO SINH VIEN DU DIEU KIEN TOT NGHIEP: " << UIT->SoLuongDauTN() << endl;
		}
		else if (lc == '4') {
			if (UIT->DHGioiNhat()) {
				cout << "\t\t\t\t\tSINH VIEN DAI HOC GIOI NHAT\n\n";
				UIT->BangDH();
				UIT->DHGioiNhat()->Xuat();
				cout << endl;
			}
			else {
				cout << "\t\t\t\t\tKHONG CO SV DAI HOC NAO\n\n";
			}
			if (UIT->CDGioiNhat()) {
				cout << "\t\t\t\t\tSINH VIEN CAO DANG GIOI NHAT\n\n";
				UIT->BangCD();
				UIT->CDGioiNhat()->Xuat();
				cout << endl;
			}
			else {
				cout << "\t\t\t\t\tKHONG CO SV CAO DANG NAO\n";
			}
		}
		else {
			cout << "LUA CHON KHONG HOP LE\n";
		}
		system("pause");
	}

}

int main() {
	Truong *UIT = new Truong;
	Menu(UIT);
	delete UIT;
	return 0;
}