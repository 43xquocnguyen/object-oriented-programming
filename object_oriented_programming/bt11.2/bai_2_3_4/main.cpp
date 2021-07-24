#include "list_polygons.h"
#include "polygon.h"

void Menu(ListPolygons *UITer) {
	UITer = new ListPolygons;
	while (true)
	{
		system("cls");
		cout << "1. NHAP THEM DA GIAC\n";
		cout << "2. XUAT CAC DA GIAC\n";
		cout << "3. TINH TIEN DA GIAC\n";
		cout << "4. QUAY DA GIAC\n";
		cout << "5. PHONG TO HOAC THU NHO DA GIAC\n";
		cout << "0. THOAT\n";
		cout << "\nLUA CHON: ";
		char x;
		cin >> x;
		cin.ignore();
		system("cls");

		if (x == '0') break;
		else if (x == '1') {
			UITer->Input();
		}
		else if (x == '2') {
			UITer->Output();
		}
		else if (x == '3') {
			int a, b;
			cout << "NHAP VECTOR(a, b) DE TINH TIEN: ";
			cin >> a >> b;
			UITer->Trans(a, b);
			cout << "\t\t\t\tCAC DA GIAC SAU KHI TINH TIEN (" << a << "; " << b << ")" << "\n\n";
			UITer->Output();
		}
		else if (x == '4') {
			int rad;
			cout << "NHAP GOC CAN QUAY (rad): ";
			cin >> rad;
			UITer->Relate(rad);
			cout << "\t\t\t\tCAC DA GIAC SAU KHI QUAY " << rad << " DO (rad)" << "\n\n";
			UITer->Output();
		}
		else if (x == '5') {
			int l;
			cout << "NHAP DO PHONG TO THU NHO (- DE THU NHO; + DE PHONG TO): ";
			cin >> l;
			UITer->ZoomIn_Out(l);
			cout << "\t\t\t\tCAC DA GIAC SAU KHI PHONG " << l << " DO" << "\n\n";
			UITer->Output();
		}
		else cout << "LUA CHON KHONG HOP LE\n";
		system("pause");
	}
	delete UITer;
}

int main() {
	ListPolygons* UITer = NULL;
	Menu(UITer);
	return 0;
}