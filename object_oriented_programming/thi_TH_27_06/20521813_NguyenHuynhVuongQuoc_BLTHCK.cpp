#include <ctime>
#include <stdlib.h>
#include <iostream> 
#include <string>
#include <vector>
using namespace std;

class ChungCu
{
protected:
	string ten;
	int soTang;
	int dienTich;
	string tenQuanLi;
	string soHuu;
	
	int tien1Phong;
	int tienPhong;

public:
	ChungCu();
	~ChungCu();

	string GetterTenSoHuu();

	virtual void NhapThongTinChungCu();
	void GuiThongBao();

	virtual void TinhMotTienPhong() = 0;

	int TinhTienPhongCaChungCu();
};

ChungCu::ChungCu() {
	this->ten = "";
	this->soTang = 0;
	this->dienTich = 0;
	this->tenQuanLi = "";
	this->soHuu = "";
}
ChungCu::~ChungCu() {
	// delete everything
}

string ChungCu::GetterTenSoHuu() {
	return this->soHuu;
}
void ChungCu::NhapThongTinChungCu() {
	cout << "NHAP TEN CHUNG CU: ";
	getline(cin, this->ten);

	bool checkFail;
	do
	{
		checkFail = true;
		cout << "NHAP SO TANG CHUNG CU: ";
		cin >> this->soTang;
		if (cin.fail() || this->soTang <= 0) {
			checkFail = false;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			this->soTang = -1;
			cout << "SO TANG KHONG HOP LE\n";
		}
	} while (checkFail == false);

	do
	{
		checkFail = true;
		cout << "NHAP DIEN TICH CHUNG CU: ";
		cin >> this->dienTich;
		if (cin.fail() || this->dienTich <= 0) {
			checkFail = false;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			this->dienTich = -1;
			cout << "DIEN TICH KHONG HOP LE\n";
		}
	} while (checkFail == false);
	cin.ignore();

	this->TinhMotTienPhong();

	cout << "NHAP TEN QUAN LI: ";
	getline(cin, this->tenQuanLi);
}
void ChungCu::GuiThongBao() {
	cout << this->tenQuanLi << " - ";
	cout << this->ten << " - ";
	cout << this->soHuu;
}
int ChungCu::TinhTienPhongCaChungCu() {
	return this->tien1Phong * this->soTang * 6;
}

class CCBCon : public ChungCu
{
public:
	CCBCon();
	~CCBCon();

	void NhapThongTinChungCu();
	void TinhMotTienPhong();
};
CCBCon::CCBCon() : ChungCu() {

}
CCBCon::~CCBCon() {

}

void CCBCon::NhapThongTinChungCu() {
	ChungCu::NhapThongTinChungCu();
	this->soHuu = "Bcons";
}
void CCBCon::TinhMotTienPhong() {
	if (this->dienTich > 600) {
		// 8 - 12 
		this->tien1Phong = rand() % 5 + 8;
	}
	else {
		// 5 - 8
		this->tien1Phong = rand() % 4 + 5;
	}
}

class CCVinHome : public ChungCu
{
public:
	CCVinHome();
	~CCVinHome();

	void NhapThongTinChungCu();

	void TinhMotTienPhong();
};

CCVinHome::CCVinHome() : ChungCu() {

}
CCVinHome::~CCVinHome() {

}

void CCVinHome::NhapThongTinChungCu() {
	ChungCu::NhapThongTinChungCu();
	this->soHuu = "Vinhomes";
}

void CCVinHome::TinhMotTienPhong() {
	if (this->dienTich > 600) {
		// 10 - 15
		this->tien1Phong = rand() % 6 + 10;
	}
	else {
		// 6 - 10
		this->tien1Phong = rand() % 5 + 6;
	}
}

class QuanLiChungCu
{
private:
	vector<ChungCu*> dsChungCu;
	int soLuongCCBcon;
	int soLuongCCVinHome;

public:
	QuanLiChungCu();
	~QuanLiChungCu();

	void NhapThongTin();
	void NhanThongBao();
	void TinhTienChoThuePhong();
};

QuanLiChungCu::QuanLiChungCu() {
	this->soLuongCCBcon = this->soLuongCCVinHome = 0;
}
QuanLiChungCu::~QuanLiChungCu() {

}

void QuanLiChungCu::NhapThongTin() {
	bool checkFail;
	ChungCu* x;

	do
	{
		checkFail = true;
		cout << "NHAP SO LUONG CHUNG CU VIN HOME: ";
		cin >> this->soLuongCCVinHome;

		if (cin.fail() || this->soLuongCCVinHome <= 0) {
			checkFail = false;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			this->soLuongCCVinHome = -1;
			cout << "SO LUONG KHONG HOP LE\n";
		}

	} while (checkFail == false);

	cin.ignore();

	for (int i = 0; i < this->soLuongCCVinHome; i++)
	{
		system("cls");
		x = new CCVinHome;
		cout << "NHAP CHUNG CU VINHOME THU " << i + 1 << endl << endl;
		x->NhapThongTinChungCu();
		this->dsChungCu.push_back(x);
	}

	system("cls");

	do
	{
		
		checkFail = true;
		cout << "NHAP SO LUONG CHUNG CU BCON: ";
		cin >> this->soLuongCCBcon;

		if (cin.fail() || this->soLuongCCBcon <= 0) {
			checkFail = false;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			this->soLuongCCBcon = -1;
			cout << "SO LUONG KHONG HOP LE\n";
		}

	} while (checkFail == false);

	cin.ignore();

	for (int i = 0; i < this->soLuongCCBcon; i++)
	{
		system("cls");
		x = new CCBCon;
		cout << "NHAP CHUNG CU BCON THU " << i + 1 << endl << endl;
		x->NhapThongTinChungCu();
		this->dsChungCu.push_back(x);
	}
}
void QuanLiChungCu::NhanThongBao() {
	cout << "CO " << this->soLuongCCBcon + this->soLuongCCVinHome << " CHUNG CU: ";
	cout << this->soLuongCCVinHome << " CHUNG CU VINHOMES VA ";
	cout << this->soLuongCCBcon << " CHUNG CU BCONS" << endl;

	int size = this->dsChungCu.size();

	for (int i = 0; i < size; i++)
	{
		this->dsChungCu[i]->GuiThongBao();
		cout << endl;
	}
}
void QuanLiChungCu::TinhTienChoThuePhong() {

	int size = this->dsChungCu.size();
	int tongTien = 0;
	string tenChuSoHuu;

	for (int i = 0; i < size; i++)
	{
		tenChuSoHuu = this->dsChungCu[i]->GetterTenSoHuu();
		cout << "Tien phong cua chung cu " << tenChuSoHuu << " thu ";
		cout << i + 1 << ": ";
		cout << this->dsChungCu[i]->TinhTienPhongCaChungCu() << " TRIEU DONG" << endl;
		tongTien += this->dsChungCu[i]->TinhTienPhongCaChungCu();
	}

	cout << "\nTONG TIEN CHO THUE: " << tongTien << " TRIEU DONG" << endl;
}


void Menu(QuanLiChungCu* langDaiHoc) {
	langDaiHoc = new QuanLiChungCu;

	while (true)
	{
		system("cls");
		cout << "1. NHAP SO LUONG CHUNG CU & NHAP THONG TIN\n";
		cout << "2. NHAN THONG BAO TINH TRANG CHUNG CU (NEU CO)\n";
		cout << "3. TINH TIEN THUE PHONG CUA TAT CA CHUNG CU & TONG\n";
		cout << "0. THOAT\n\n";
		char lc;
		cout << "NHAP LUA CHON CUA BAN: ";
		cin >> lc;

		system("cls");
		if (lc == '0') {
			break;
		}
		else if (lc == '1') {
			langDaiHoc->NhapThongTin();
		}
		else if (lc == '2') {
			langDaiHoc->NhanThongBao();
			system("pause");
		}
		else if (lc == '3') {
			langDaiHoc->TinhTienChoThuePhong();
			system("pause");
		}
	}

	delete langDaiHoc;
}

int main() {
	srand(time(NULL));
	QuanLiChungCu* langDaiHoc = NULL;
	Menu(langDaiHoc);
	return 0;
}