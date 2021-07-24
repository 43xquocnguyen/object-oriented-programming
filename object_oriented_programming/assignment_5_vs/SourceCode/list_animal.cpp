#include "list_animal.h"

ListAnimal::ListAnimal() {
	this->ten.resize(3);
	this->ten[0] = "BO";
	this->ten[1] = "DE";
	this->ten[2] = "CUU";

	this->soLitSua = new float[3];
	this->soConDe = new int[3];
	this->soLuong = new int[3];

	for (int i = 0; i < 3; i++)
	{
		this->soConDe[i] = 0;
		this->soLitSua[i] = 0;
		this->soLuong[i] = 0;
	}
}
ListAnimal::~ListAnimal() {
	delete[] this->soConDe;
	delete[] this->soLuong;
	delete[] this->soLitSua;
}

void ListAnimal::Input() {
	int a, b, c;
	do
	{
		cout << "NHAP SO LUONG BO: ";
		cin >> a;
		cout << "NHAP SO LUONG DE: ";
		cin >> b;
		cout << "NHAP SO LUONG CUU: ";
		cin >> c;
		if (a < 0 || b < 0 || c < 0) 
			cout << "SO LUONG KHONG HOP LE\n";
	} while (a < 0 || b < 0 || c < 0);

	this->soLuong[0] += a;
	this->soLuong[1] += b;
	this->soLuong[2] += c;

	Animal* t;
	int i = 0;
	for (; i < a; i++)
	{
		t = new Cow;
		this->list.push_back(t);
	}
	for (i = 0; i < b; i++)
	{
		t = new Goat;
		this->list.push_back(t);
	}
	for (i = 0; i < c; i++)
	{
		t = new Sheep;
		this->list.push_back(t);
	}
}
void ListAnimal::DiVang() {
	int size = this->list.size();
	if (size) {
		for (int i = 0; i < size; i++)
		{
			list[i]->PhatTiengKeu();
		}
		if (this->soLuong[0] && this->soLuong[1] && this->soLuong[2]) {
			PlaySound(L"cow_goat_sheep.wav", NULL, SND_SYNC);
		}
		else {
			if (this->soLuong[0]) { // co bo
				PlaySound(L"cow.wav", NULL, SND_SYNC);

			}
			if (this->soLuong[1]) { // co de
				PlaySound(L"goat.wav", NULL, SND_SYNC);
			}
			if (this->soLuong[2]) { // co cuu
				PlaySound(L"sheep.wav", NULL, SND_SYNC);
			}
		}
	}
	else { // rong
		cout << "TRANG TRAI CUA BAN KHONG CO GIA SUC\n";
		PlaySound(L"empty.wav", NULL, SND_SYNC); 
	}
	cout << "\n\nNHAN PHIM BAT KI DE TIEP TUC\n";
}
void ListAnimal::ThongKe() { 
	cout << "\t\t\tBANG THONG KE TRANG TRAI CUA BAN\n\n";
	cout << setw(15) << left << "GIA SUC";
	cout << setw(20) << left << "SO LUONG (CON)";
	cout << setw(20) << left << "SO CON DE (CON)";
	cout << setw(20) << left << "SO LIT SUA (LIT)" << endl;
	cout << setfill('-') << setw(70) << "-" << endl;
	cout << setfill(' ');

	int size = this->list.size();

	for (int i = 0; i < size; i++)
	{
		if (this->list[i]->Gtick() == 1) {
			this->soConDe[0] += this->list[i]->GsoCon();
			this->soLitSua[0] += this->list[i]->GsoLitSua();
		}
		else if (this->list[i]->Gtick() == 2) {
			this->soConDe[1] += this->list[i]->GsoCon();
			this->soLitSua[1] += this->list[i]->GsoLitSua();
		}
		else if (this->list[i]->Gtick() == 3) {
			this->soConDe[2] += this->list[i]->GsoCon();
			this->soLitSua[2] += this->list[i]->GsoLitSua();
		}
	}
	
	
	for (int i = 0; i < 3; i++)
	{
		cout << setw(15) << left << this->ten[i];
		cout << setw(20) << left << this->soLuong[i];
		cout << setw(20) << left << this->soConDe[i];
		cout << setw(20) << left << this->soLitSua[i] << endl;
	}

	cout << setw(15) << left << "TONG SO";
	cout << setw(20) << left << this->soLuong[0] + this->soLuong[1] + this->soLuong[2];
	cout << setw(20) << left << this->soConDe[0] + this->soConDe[1] + this->soConDe[2];
	cout << setw(20) << left << this->soLitSua[0] + this->soLitSua[1] + this->soLitSua[2] << "\n\n\n\n";
}