#include "list_robot.h"

void Menu(ListRobot* ChienDau) {
	while (true)
	{
		system("cls");
		cout << "1. MOT HOM, TONG CHI HUY BABILON DIEU DONG 500 AE GOM A PEDION, B ZATTACKER VA C CARRIER. NHAP A, B, C\n";
		cout << "2. XUAT THONG TIN ROBOT\n";
		cout << "3. ROBOT TIEU THU NHIEU NHAT\n";
		cout << "4. TONG NANG LUONG CA DOAN\n";
		cout << "0. THOAT\n\n";
		cout << "LUA CHON: ";
		char x;
		cin >> x;
		cin.ignore();
		system("cls");

		if (x == '1') {
			ChienDau->Input();
		}
		else if (x == '2') {
			if (ChienDau->GetterNum() > 0) {
				float S;
				do
				{
					cout << "NHAP QUANG DUONG (km): ";
					cin >> S;
					if (S <= 0) cout << "QUANG DUONG KHONG HOP HE\n";
				} while (S <= 0);
				cout << "\t\t\t\t\tBANG DANH SACH ROBOT\n\n";
				ChienDau->SetterS(S);
				ChienDau->Output();
			}
			else cout << "KHONG CO DU LIEU\n";
		}
		else if (x == '3') {
			if (ChienDau->GetterNum() > 0) {
				cout << "\t\t\t\t\tROBOT TIEU NHIEU NANG LUONG NHAT\n\n";
				cout << setw(12) << left << "LOAI";
				cout << setw(17) << left << "KHOI LUONG (M)";
				cout << setw(17) << left << "LINH HOAT (F)";
				cout << setw(17) << left << "SUC MANH (P)";
				cout << setw(17) << left << "NANG LUONG (E)";
				cout << setw(20) << left << "TONG TIEU THU ($)" << endl;
				cout << setfill('-') << setw(100) << "-" << endl;
				cout << setfill(' ');
				ChienDau->TheMostEnergy()->Output(ChienDau->GetterS());
				cout << endl;
			}
			else {
				cout << "KHONG CO DU LIEU\n";
			}
		}
		else if (x == '4') {
			if (ChienDau->GetterNum() > 0) {
				cout << "TONG NANG LUONG TIEU THU: " << (size_t)ChienDau->SumEnergy() << " $" << endl;
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
	ListRobot* ChienDau;
	ChienDau = new ListRobot;
	Menu(ChienDau);
	delete ChienDau;
	return 0;
}