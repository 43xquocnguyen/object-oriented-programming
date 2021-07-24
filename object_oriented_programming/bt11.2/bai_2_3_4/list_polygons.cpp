#include "list_polygons.h"

ListPolygons::ListPolygons() {
	this->size = 0;
}
ListPolygons::~ListPolygons() {
	this->size = 0;
}
void ListPolygons::Input() {
	while (true)
	{
		system("cls");
		cout << "1. TAM GIAC (TRIANGLE)\n";
		cout << "2. TU GIAC (QUADRANGLE)\n";
		cout << "3. NGU GIAC (PENTAGON)\n";
		cout << "0. THOAT\n";
		cout << "\nLUA CHON: ";
		char x;
		cin >> x;
		cin.ignore();
		system("cls");

		Polygon* t;

		if (x == '0') break;
		else if (x == '1') {
			cout << "NHAP TAM GIAC\n";
			t = new TriAngle;
			t->Input();
			this->list.push_back(t);
		}
		else if (x == '2') {
			char xx;
			do
			{
				cout << "1. HINH VUONG (SQUARE)\n";
				cout << "2. HINH CHU NHAT (RECTANGLE)\n";
				cout << "3. HINH BINH HANH (PARALLELOGRAM)\n";
				cout << "0. THOAT\n\n";
				cout << "LUA CHON: ";
				cin >> xx;
				system("cls");
				if (xx != '1' && xx != '2' && xx != '0' && xx != '3') cout << "LC KHONG HOP LE! THU LAI\n";
			} while (xx != '1' && xx != '2' && xx != '0' && xx != '3');

			cin.ignore();

			if (xx == '1') {
				cout << "NHAP HINH VUONG\n";
				Polygon* t = new Square;
				t->Input();
				this->list.push_back(t);
			}
			else if (xx == '2') {
				cout << "NHAP HINH CHU NHAT\n";
				Polygon* t = new Rectangle;
				t->Input();
				this->list.push_back(t);
			}
			else if (xx == '3') {
				cout << "NHAP HINH BINH HANH\n";
				Polygon* t = new Parallelogram;
				t->Input();
				this->list.push_back(t);
			}
		}
		else if (x == '3') {
			cout << "NHAP NGU GIAC\n";
			t = new Pentagon;
			t->Input();
			this->list.push_back(t);
		}
		else cout << "LUA CHON KHONG HOP LE\n";
		system("pause");
	}
	this->size = this->list.size();
}
void ListPolygons::Output() {
	if (this->size) {
		for (int i = 0; i < this->size; i++)
		{
			if (list[i]->Tick() == 0) cout << "DA GIAC: ";
			if (list[i]->Tick() == 1) cout << "TAM GIAC: ";
			if (list[i]->Tick() == 2) cout << "TU GIAC: ";
			if (list[i]->Tick() == 3) cout << "HINH VUONG: ";
			if (list[i]->Tick() == 4) cout << "HINH CHU NHAT: ";
			if (list[i]->Tick() == 5) cout << "HINH BINH HANH: ";
			if (list[i]->Tick() == 6) cout << "NGU GIAC: ";
			list[i]->Output();
			cout << endl;
		}
	}
	else cout << "KHONG CO DU LIEU\n";
}
void ListPolygons::Trans(float a, float b) {
	if (this->size) {
		for (int i = 0; i < this->size; i++)
		{
			this->list[i]->Trans(a, b);
		}
	}
	else cout << "DANH SACH DANG RONG CA DA GIAC\n";
}
void ListPolygons::Relate(float rad) {
	if (this->size) {
		for (int i = 0; i < this->size; i++)
		{
			this->list[i]->Relate(rad);
		}
	}
	else cout << "DANH SACH DANG RONG CA DA GIAC\n";
}
void ListPolygons::ZoomIn_Out(float z) {
	if (this->size) {
		for (int i = 0; i < this->size; i++)
		{
			this->list[i]->Zoom(z);
		}
	}
	else cout << "DANH SACH DANG RONG CA DA GIAC\n";
}