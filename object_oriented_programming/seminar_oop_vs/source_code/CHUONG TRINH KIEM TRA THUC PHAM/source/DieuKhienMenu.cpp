#include "DieuKhienMenu.h"
#include "QuanLiNhapKho.h"

DieuKhienMenu::DieuKhienMenu() {
	
}
DieuKhienMenu::~DieuKhienMenu() {
	
}
void DieuKhienMenu::KhoiTaoDocDuLieu() {
	ifstream nhapFileMenu;
	nhapFileMenu.open("duLieuMenu.txt", ios_base::in);
	int soLuong, mau, x, y;
	string* str, * str2, * str3, * str4, * str5;

	//======= doc x, y
	x = WidthConsole / 7; // chia width thanh 7 phan bang nhau
	y = HeightConsole / 5; // chia height thanh 5 phan bang nhau

	//======= box menu chinh
	nhapFileMenu >> mau;
	nhapFileMenu >> soLuong;
	str = new string[soLuong];
	for (int i = 0; i < soLuong; i++)
	{
		getline(nhapFileMenu, str[i]);
	}
	Menu* t = new Menu(x, y, soLuong, mau, str);
	menu.push_back(t);

	//======== box menu nhap
	nhapFileMenu >> mau;
	nhapFileMenu >> soLuong;
	str2 = new string[soLuong];
	for (int i = 0; i < soLuong; i++)
	{
		getline(nhapFileMenu, str2[i]);
	}

	Menu* q = new Menu(x * 3, y, soLuong, mau, str2);
	menu.push_back(q);

	//========= box menu xuat
	nhapFileMenu >> mau;
	nhapFileMenu >> soLuong;
	str3 = new string[soLuong];
	for (int i = 0; i < soLuong; i++)
	{
		getline(nhapFileMenu, str3[i]);
	}

	Menu* k = new Menu(x * 3, y, soLuong, mau, str3);
	menu.push_back(k);

	//========= box menu yes or no
	nhapFileMenu >> mau;
	nhapFileMenu >> soLuong;
	str4 = new string[soLuong];
	for (int i = 0; i < soLuong; i++)
	{
		getline(nhapFileMenu, str4[i]);
	}

	Menu* r = new Menu(x * 5, y, soLuong, mau, str4);
	menu.push_back(r);

	//========= box menu tinh tien 
	nhapFileMenu >> mau;
	nhapFileMenu >> soLuong;
	str5 = new string[soLuong];
	for (int i = 0; i < soLuong; i++)
	{
		getline(nhapFileMenu, str5[i]);
	}

	Menu* l = new Menu(x * 3, y, soLuong, mau, str5);
	menu.push_back(l);

	nhapFileMenu.close();
}
void DieuKhienMenu::Chay() {
	int Check = -1;
	QuanLiNhapKho a;

	while (true)
	{
		hideCur();
		clrscr();
		// y, tColor, text
		VietBoxCoTieuDeCenTer(HeightConsole - HeightConsole + 2, ColorCode_DarkRed, "CHUONG TRINH KIEM TRA HANG HOA THUC PHAM");
		Check = -1;
		menu[0]->ChayMenu(Check);

		if (Check == 1) {
			Check = -1;
			menu[1]->ChayMenu(Check);
			if (Check == 1) {
				// nhap tay
				clrscr();
				showCur();
				a.NhapHangHoa();
			}
			else if (Check == 2) {
				// nhap tu file
				Check = -1;
				menu[3]->ChayMenu(Check);
				if (Check == 1) {
					a.LuuThongTin();
					a.KhoiTaoTongSoTienBanDuocTrong_1_Ngay();
					a.KhoiTaoSoLanXuatHienCuaCacNgayTrong_1Thang();
					a.KhoiTaoTongSoTienBanDuocTrong_Tung_Thang();
					a.KhoiTaoQuanLiCacThangTrongNam();
				}
				menu[3]->XoaMenu();
			}
			menu[1]->XoaMenu();
		}
		else if (Check == 2) {
			Check = -1;
			menu[2]->ChayMenu(Check);
			if (Check == 1) {
				if (a.TongTienBanDuoc() != 0) {
					clrscr();
					a.XuatThongTinTatCa();
				}
				else {
					clrscr();
					a.XuatTongTienRong();
				}
			}
			else if (Check == 2) {
				if (a.TongTienBanDuoc() != 0) {
					clrscr();
					a.XuatThongTinHangHoaTonKho();
				}
				else {
					clrscr();
					a.XuatTongTienRong();
				}
			}
			else if (Check == 3) {
				if (a.TongTienBanDuoc() != 0) {
					clrscr();
					a.XuatThongTinHangHoaDaBan();
				}
				else {
					clrscr();
					a.XuatTongTienRong();
				}
			}

			else if (Check == 4) {
				if (a.TongTienBanDuoc() != 0) {
					clrscr();
					a.XuatThongTinHangHoaDaHetHan();
				}
				else {
					clrscr();
					a.XuatTongTienRong();
				}
			}
			menu[2]->XoaMenu();
		}
		else if (Check == 3) {
			Check = -1;
			menu[4]->ChayMenu(Check);
			if (Check == 1) {
				// tinh tong tien
				if (a.TongTienBanDuoc() != 0) {
					clrscr();
					a.XuatTongTienBanDuoc();
				}
				else {
					clrscr();
					a.XuatTongTienRong();
				}
			}
			else if (Check == 2) {
				if (a.TongTienBanDuoc() != 0)
					a.XuatTienBanRaTungNgay();
				else {
					clrscr();
					a.XuatTongTienRong();
				}
			}
			else if (Check == 3) {
				// tinh tien theo thang
				if (a.TongTienBanDuoc() != 0)
					a.XuatTienBanRaTungThang();
				else {
					clrscr();
					a.XuatTongTienRong();
				}
				
			}
			menu[4]->XoaMenu();
		}
		else if (Check == 4) {
			// thoat
			clrscr();
			break;
		}
	}
}