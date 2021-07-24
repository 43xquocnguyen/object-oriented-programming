#include "student.h"

void Student::Nhap() {
    system("cls");
    cout << "Nhap ten sinh vien: ";
    getline(cin, this->hoTen);

	do {
		cout << "Nhap diem Toan: ";
		cin >> this->diemToan;

		if (this->diemToan < 0 || this->diemToan > 10) {
			cout << "Diem Toan khong hop le\n";
		}
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			this->diemToan = -1;
		}
	} while (this->diemToan < 0 || this->diemToan > 10);

	cin.ignore();

	do {
		cout << "Nhap diem Van: ";
		cin >> this->diemVan;

		if (this->diemVan < 0 || this->diemVan > 10) {
			cout << "Diem Van khong hop le\n";
		}
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			this->diemVan = -1;
		}
	} while (this->diemVan < 0 || this->diemVan > 10);

	cin.ignore();
}


void Student::Xuat() {
    this->Bang();
    cout << setfill(' ');
    cout << setw(35) << left << this->hoTen;
    cout << setw(15) << left << this->diemToan;
    cout << setw(15) << left << this->diemVan;
	cout << setw(15) << left << this->TinhDiemTrungBinh();
}

float Student::TinhDiemTrungBinh() {
	return (this->diemToan + this->diemVan) / 2;
}
