#include "Date.h"
#include <iomanip>
#include <iostream>
#include "Graphics.h"
#include "HoTro.h"
using namespace std;

Date::Date() {

	this->Ngay = 0;
	this->Thang = 0;
	this->Nam = 0;

}

Date::Date(int m, int y) {
	Ngay = 0;
	Thang = m;
	Nam = y;
}

Date::Date(int d, int m, int y) {

	Ngay = d;
	Thang = m;
	Nam = y;
}

int Date::getDayofMonth() {

	if (Thang > dayz.size()) {
		if (Thang > dayz.size() && ((Ngay < 28) && (Ngay > 0)))
			return 1;
		if (!(Thang < dayz.size()) || !((Ngay > 28) || (Ngay < 0))) {
			return 2;
		}
		if (Thang > dayz.size() && ((Ngay > 28) || (Ngay < 0)))
			return 0;
	}
	if (Thang == 2 && ((Nam % 4 == 0) && (Nam % 100 != 0)) || (Nam % 400 == 0)) {
		int x = Thang - 1;
		return dayz[x] + 1;
	}
	int x = Thang - 1;
	return dayz[x];
}

bool Date::checkNam() {

	if (((Nam % 4 == 0) && (Nam % 100 != 0)) || (Nam % 400 == 0))
		return true;
	return false;
}


bool Date::NgayDaHopLe() {

	if (Nam > 0) {
		if (Thang > 0 && Thang < 13) {
			if (Ngay > 0 && Ngay <= getDayofMonth()) {
				return true;
			}
			else
			{
				//cout << "\nNhap ngay sai. Vui long nhap lai.";
				return false;
			}
		}
		else if (getDayofMonth() == 2) {
			//cout << "\nNhap ngay thang sai. Vui long nhap lai.";
			return false;
		}
		else if (getDayofMonth() == 1)
		{
			//cout << "\nNhap thang sai. Vui long nhap lai.";
			return false;
		}
	}
	else if (getDayofMonth() == 2) {
		//cout << "\nNhap ngay thang nam sai.Vui long nhap lai.";
		return false;
	}
	else if (getDayofMonth() == 1) {
		//cout << "\nNhap thang, nam sai. Vui long nhap lai.";
		return false;;
	}
	else if ((Ngay > 0 && Ngay <= getDayofMonth())) {
		//cout << "\nNhap nam sai. Vui long nhap lai.";
		return false;
	}
	return false;
}


unsigned long Date::getTotalDay() {

	unsigned long tmpDay = Ngay;
	for (int i = 1; i < Nam; i++) {
		if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
			tmpDay += 366;
		else
			tmpDay += 365;
	}
	for (int i = 1; i < Thang; i++) {

		if (i == 2 && checkNam()) {
			int x = i - 1;
			tmpDay = tmpDay + dayz[x] + 1;
		}
		else {
			int x = i - 1;
			tmpDay += dayz[x];

		}
	}
	return tmpDay;
}


void Date::NhapNgay(int vitrix, int vitriy) {
	do {
		VietBoxCoTieuDeCenTer(HeightConsole - 7, 10, "VUI LONG NHAP NGAY THANG NAM HOP LE");
		bool check = true;
		do {
			check = true;
			gotoXY(vitrix, vitriy);
			cin >> Ngay;
			VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Back, "                              ");
			if (cin.fail()) {
				gotoXY(vitrix, vitriy );
				cout << "                                  ";
				cin.clear();
				cin.ignore();
				check = false;
				VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Red, "NGAY KHONG HOP LE!");
			}
		} while (check == false);

		gotoXY(vitrix, vitriy );
		if (this->Ngay < 10) {
			cout << "0" << this->Ngay;
		}
		else {
			cout << this->Ngay;
		}
		gotoXY(vitrix + 2, vitriy );
		cout << "/";

		do {
			check = true; 
			gotoXY(vitrix + 3, vitriy );
			cin >> Thang;
			VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Back, "                              ");
			if (cin.fail()) {
				gotoXY(vitrix + 3, vitriy);
				cout << "                               ";
				cin.clear();
				cin.ignore();
				check = false;
				VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Red, "THANG KHONG HOP LE!");
			}
		} while (check == false);


		gotoXY(vitrix + 3, vitriy );
		if (this->Thang < 10) {
			cout << "0" << this->Thang;
		}
		else {
			cout << this->Thang;
		}
		gotoXY(vitrix + 5, vitriy );
		cout << "/";

		do {
			check = true;
			gotoXY(vitrix + 6, vitriy );
			cin >> Nam;
			VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Back, "                              ");
			if (cin.fail()) {
				gotoXY(vitrix + 6, vitriy);
				cout << "                            ";
				cin.clear();
				cin.ignore();
				check = false;
				VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Red, "NAM KHONG HOP LE!");
			}
		} while (check == false);

		if (!this->NgayDaHopLe()) {
			gotoXY(vitrix, vitriy);
			cout << "                             ";
			VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Red, "NGAY THANG NAM KHONG DUNG!");
		}

	} while (!this->NgayDaHopLe());
	cin.ignore();
}


void Date::XuatNgay(float x, int y) {
	gotoXY(x, y);
	if (Ngay < 10) {
		cout << "0" << Ngay;
	}
	else cout << Ngay;

	cout << "/";

	if (Thang < 10) {
		cout << "0" << Thang;
	}
	else cout << Thang;

	cout << "/" << Nam;
}


void  Date::testxuatngay() {
	cout <<"\n"<< Ngay << "-" << Thang << "-" << Nam;
}


bool Date::SoSanhHaiNgay(Date b) {
	if (this->getTotalDay() > b.getTotalDay())
		return true;
	if (this->getTotalDay() < b.getTotalDay())
		return false;

}



bool Date::HaiNgayBangNhau( Date b) {

	if (this->getTotalDay() == b.getTotalDay())
		return true;
	return false;

}

int Date::getterNgay() {
	return this->Ngay;
}

int Date::getterThang() {
	return this->Thang;
}

int Date::getterNam() {
	return this->Nam;
}

void Date::setterNgay(int Ngay) {
	this->Ngay = Ngay;
}


void Date::setterThang(int Thang) {
	this->Thang = Thang;
}

void Date::setterNam(int Nam) {
	this->Nam = Nam;
}


void Date::NhapFileThongTinNgayThangTrongHangHoa(ifstream& nhapfile) {
	nhapfile >> Ngay;
	nhapfile.seekg(1, 1);
	nhapfile >> Thang;
	nhapfile.seekg(1, 1);
	nhapfile >> Nam;
	nhapfile.seekg(1, 1);
}