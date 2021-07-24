#include "list_animal.h"

void Menu(ListAnimal* a) {
	a = new ListAnimal;
	while (6)
	{
		system("cls");
		cout << "1. NHAP SO LUONG GIA SUC\n";
		cout << "2. MOT HOM, NGUOI CHU DI VANG. NGHE NHUNG TIENG DONG VAT KEU DOI~~\n";
		cout << "3. THONG KE SO CON VA SO LIT SUA\n";
		cout << "0. THOAT\n\n";
		cout << "LUA CHON: ";
		char choose;
		cin >> choose;
		cin.ignore();
		system("cls");
		
		if (choose == '0') break;
		else if (choose == '1') {
			a->Input();
		}
		else if (choose == '2') {
			a->DiVang();
		}
		else if (choose == '3') {
			a->ThongKe();
		}
		else cout << "LUA CHON KHONG HOP LE\n";
		system("pause");
 	}
	delete a;
}

int main() {
	srand(time(NULL));
	ListAnimal* a = NULL;
	Menu(a);
	return 0;
}