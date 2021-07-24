#include "HoTro.h"
#include "Menu.h"
#include <string>
#include <cmath>


///////////////////////===============================asnl;fasjklf;asfkl;asjl;faskl;fasl;fasjl;f
//////////sdl;kasdjkl;asdl;assaflk;
//////////fasjkl;fasjkl;flaks;fkl;asfkl;asfkl;
///////////////////////===============================asnl;fasjklf;asfkl;asjl;faskl;fasl;fasjl;f
//////////sdl;kasdjkl;asdl;assaflk;
//////////fasjkl;fasjkl;flaks;fkl;asfkl;asfkl;///////////////////////===============================asnl;fasjklf;asfkl;asjl;faskl;fasl;fasjl;f
//////////sdl;kasdjkl;asdl;assaflk;
//////////fasjkl;fasjkl;flaks;fkl;asfkl;asfkl;///////////////////////===============================asnl;fasjklf;asfkl;asjl;faskl;fasl;fasjl;f
//////////sdl;kasdjkl;asdl;assaflk;
//////////fasjkl;fasjkl;flaks;fkl;asfkl;asfkl;
void KeBangXuat() {
	int y = HeightConsole / 6 + 1;
	InChuoiCoMau((float)WidthConsole / (float)52, y, 7, "STT");
	InChuoiCoMau((float)WidthConsole / (float)17, y, 7, "MA HANG HOA");
	InChuoiCoMau((float)WidthConsole / (float)7.53, y, 7, "LOAI HANG");
	InChuoiCoMau((float)WidthConsole / (float)4.58, y, 7, "TEN HANG");
	InChuoiCoMau((float)WidthConsole / (float)2.604, y, 7, "DON VI TINH");
	InChuoiCoMau((float)WidthConsole / (float)2.13, y, 7, "DON GIA (VND)");
	InChuoiCoMau((float)WidthConsole / (float)1.81, y, 7, "MA KHO LUU");
	InChuoiCoMau((float)WidthConsole / (float)1.57, y, 7, "NGAY SAN XUAT");
	InChuoiCoMau((float)WidthConsole / (float)1.3766, y, 7, "NHAY HET HAN");
	InChuoiCoMau((float)WidthConsole / (float)1.2267, y, 7, "NHAY NHAP KHO");
	InChuoiCoMau((float)WidthConsole / (float)1.104, y, 7, "NGAY XUAT KHO");
	gotoXY(WidthConsole / 70 + 1, y + 1);
	int abc = WidthConsole - (WidthConsole / 70 * 2);
	cout << setfill('-') << setw(abc) << "-" << setfill(' ') << endl;
}
void InChuoiCoMau(float x, int y, int tColor, string text) {
	gotoXY(x, y);
	textColor(tColor);
	cout << text;
	textColor(7);
}
void KeKhungXuat(int size) { // size la so luong hang hoa
	Box* vienXuat = new Box;
	vienXuat->Set(WidthConsole / 70, (float)HeightConsole / 6.75, 
		WidthConsole - (2 * (WidthConsole / 70)), 
		6 + size, 74, "");
	// bi mat di 12 pixel chieu ngang nen tru di 12
	vienXuat->VeBox();
	delete vienXuat;
}
void VietBoxCoTieuDeCenTer(int y, int tColor, string text) {
	Box* title = new Box;
	int x = (WidthConsole / 2) - (text.length() / 2);
	title->Set(x, y, text.length() + 1, 2, tColor, text);
	title->VeBox();
	delete title;
}

void XoaBoxCoTieuDeCenTer(int y, int strlen) {
	Box* title = new Box;
	int x = (WidthConsole / 2) - (strlen / 2);
	title->Set(x, y, strlen + 1, 2, 7, "                     ");
	title->VeBox();
	delete title;
}
void InSoTrang(int i, int soLuongInRaMax, int size) {
	int soTrang, trangHienTai;
	textColor(5);
	if (size % soLuongInRaMax == 0) {
		soTrang = size / soLuongInRaMax;
	}
	else {
		soTrang = size / soLuongInRaMax;
		soTrang++;
	}
	trangHienTai = ceil((float)i / (float)soLuongInRaMax);

	string str;
	str.resize(18);
	str[0] = '<'; str[1] = '-'; str[2] = ' '; str[3] = 'T'; str[4] = 'r';
	str[5] = 'a'; str[6] = 'n'; str[7] = 'g'; str[8] = ' ';

	str[9] = trangHienTai / 10 % 10 + 48;
	str[10] = trangHienTai % 10 + 48;
	str[11] = '/'; str[12] = soTrang / 10 % 10 + 48;
	str[13] = soTrang % 10 + 48;
	str[14] = ' '; str[15] = '-'; str[16] = '>';

	gotoXY(WidthConsole / 2 - str.length() / 2, HeightConsole * 9 / 10);
	cout << str;
}
void VeBoxInput() {
	string *ip = new string[5];
	ip[0] = "MA HANG HOA: ";
	ip[1] = "LOAI HANG: ";
	ip[2] = "TEN HANG: ";
	ip[3] = "DON VI TINH: ";
	ip[4] = "DON GIA (VND): ";

	string* ip2 = new string[5];
	ip2[0] = "MA KHO LUU: ";
	ip2[1] = "NGAY SAN XUAT: ";
	ip2[2] = "NGAY HET HAN: ";
	ip2[3] = "NGAY NHAP KHO: ";
	ip2[4] = "NHAY XUAT KHO: ";

	VietBoxCoTieuDeCenTer(2, 41, "NHAP THEM HANG HANG HOA VAO KHO");
	InChuoiCoMau((float)WidthConsole / (float)21, HeightConsole - 7, ColorCode_Blue, "NHAN ESC DE THOAT!");
	InChuoiCoMau((float)WidthConsole / (float)1.17, HeightConsole - 7, ColorCode_Blue, "NHAN ENTER DE NHAP!");
	Menu* input = new Menu((float)WidthConsole / (float)7.53, HeightConsole / 5, 5, 15, ip);
	input->SetWiHe(65, 4);
	Menu* input2 = new Menu((float)WidthConsole / (float)1.57, HeightConsole / 5, 5, 17, ip2);
	input2->SetWiHe(50, 4);
	input->VeMenu();
	input2->VeMenu();
}
void BoxCoChuCenter(int x, int y, int w, int h, int tColor, string text) {
	Box* t = new Box;
	t->Set(x, y, w, h, tColor, text);
	t->VeBoxChuCenter();
	delete t;
}
void KeBangTinhTien(int check) {
	int y = HeightConsole / 7;
	string a[3];
	a[0] = "SO THU TU";
	if (check == 1) {
		a[1] = "TRONG NGAY";
	}
	else if (check == 0) {
		a[1] = "TRONG THANG";
	}
	a[2] = "DOANH THU";

	//BoxCoChuCenter((float)WidthConsole / (float)3.5, y, 20, 2, ColorCode_DarkRed, a[0]);
	//BoxCoChuCenter(WidthConsole / 2 - (WidthConsole / 25), y, 20, 2, ColorCode_DarkRed, a[1]);
	//BoxCoChuCenter((float)WidthConsole / (float)1.6, y, 20, 2, ColorCode_DarkRed, a[2]);
	BoxCoChuCenter((float)WidthConsole / (float)3.45, y, 21, 2, 7, a[0]);
	BoxCoChuCenter(WidthConsole / 2 - (WidthConsole / 16), y, 21, 2, 7, a[1]);
	BoxCoChuCenter((float)WidthConsole / (float)1.7, y, 21, 2, 7, a[2]);
}

void KeTongTien(unsigned int tongTien) {
	string t = "DOANH THU TOAN BO: " + to_string(tongTien) + " VND";
	int tColor = ColorCode_DarkPink;
	int w = 60;
	int h = 6;
	int x = WidthConsole / 2;
	int y = 7;
	x -= (t.length() / 2);
	x -= (w / 2 - t.length() / 2);
	BoxCoChuCenter(x, y, w, h, tColor, t);
}

void KeBangXuatTienRong() {
	string t = "MOI BAN NHAP HANG HOA VAO KHO !!!";
	int tColor = ColorCode_DarkPink;
	int w = 60;
	int h = 6;
	int x = WidthConsole / 2;
	int y = 7;
	x -= (t.length() / 2);
	x -= (w / 2 - t.length() / 2);
	BoxCoChuCenter(x, y, w, h, tColor, t);
}


string DoiDateThanhString(Date a) {
	// cai nay code chay` coi' vl
	string chuoi;
	chuoi.resize(11);
	if (a.getterNgay() < 10) {
		chuoi[0] = '0';
		chuoi[1] = a.getterNgay() + 48;
	}
	else {
		int ngay = a.getterNgay() / 10;
		chuoi[0] = ngay + 48;
		int ngay2 = a.getterNgay() % 10;
		chuoi[1] = ngay2 + 48;
	}
	chuoi[3] = '/';
	if (a.getterThang() < 10) {
		chuoi[4] = '0';
		chuoi[5] = a.getterThang() + 48;
	}
	else {
		int thang = a.getterThang() / 10;
		chuoi[4] = thang + 48;
		int thang2 = a.getterThang() % 10;
		chuoi[5] = thang2 + 48;
	}
	chuoi[6] = '/';
	chuoi[10] = a.getterNam() % 10 + 48;
	chuoi[9] = a.getterNam() / 10 % 10 + 48;
	chuoi[8] = a.getterNam() / 10 / 10 % 10 + 48;
	chuoi[7] = a.getterNam() / 10 / 10 / 10 % 10 + 48;
	return chuoi;
}

string DoiDateThanhStringKhongCoNgay(Date a) {
	// cai nay code chay` coi' vl
	string chuoi;
	chuoi.resize(13);
	if (a.getterNgay() == 0) {
		chuoi[0] = 'T';
		chuoi[1] = 'h';
	}
	chuoi[2] = 'a';
	chuoi[3] = 'n';
	chuoi[4] = 'g';
	chuoi[5] = ' ';
	if (a.getterThang() < 10) {
		chuoi[6] = '0';
		chuoi[7] = a.getterThang() + 48;
	}
	else {
		int thang = a.getterThang() / 10;
		chuoi[6] = thang + 48;
		int thang2 = a.getterThang() % 10;
		chuoi[7] = thang2 + 48;
	}
	chuoi[8] = '/';
	chuoi[12] = a.getterNam() % 10 + 48;
	chuoi[11] = a.getterNam() / 10 % 10 + 48;
	chuoi[10] = a.getterNam() / 10 / 10 % 10 + 48;
	chuoi[9] = a.getterNam() / 10 / 10 / 10 % 10 + 48;
	return chuoi;
}



//////////fasjkl;fasjkl;flaks;fkl;asfkl;asfkl;///////////////////////===============================asnl;fasjklf;asfkl;asjl;faskl;fasl;fasjl;f
//////////sdl;kasdjkl;asdl;assaflk;
//////////fasjkl;fasjkl;flaks;fkl;asfkl;asfkl;//////////fasjkl;fasjkl;flaks;fkl;asfkl;asfkl;///////////////////////===============================asnl;fasjklf;asfkl;asjl;faskl;fasl;fasjl;f
//////////sdl;kasdjkl;asdl;assaflk;
//////////fasjkl;fasjkl;flaks;fkl;asfkl;asfkl;//////////fasjkl;fasjkl;flaks;fkl;asfkl;asfkl;///////////////////////===============================asnl;fasjklf;asfkl;asjl;faskl;fasl;fasjl;f
//////////sdl;kasdjkl;asdl;assaflk;
//////////fasjkl;fasjkl;flaks;fkl;asfkl;asfkl;//////////fasjkl;fasjkl;flaks;fkl;asfkl;asfkl;///////////////////////===============================asnl;fasjklf;asfkl;asjl;faskl;fasl;fasjl;f
//////////sdl;kasdjkl;asdl;assaflk;
//////////fasjkl;fasjkl;flaks;fkl;asfkl;asfkl;//////////fasjkl;fasjkl;flaks;fkl;asfkl;asfkl;///////////////////////===============================asnl;fasjklf;asfkl;asjl;faskl;fasl;fasjl;f
//////////sdl;kasdjkl;asdl;assaflk;
//////////fasjkl;fasjkl;flaks;fkl;asfkl;asfkl;
