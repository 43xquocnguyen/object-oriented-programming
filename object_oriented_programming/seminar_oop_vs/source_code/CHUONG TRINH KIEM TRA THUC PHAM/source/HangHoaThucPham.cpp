#include "HangHoaThucPham.h"
#include <fstream>
#include <string>
#include "Graphics.h"
#include "HoTro.h"
#include"ThoiGianThuc.h"


HangHoaThucPham::HangHoaThucPham() {

}

HangHoaThucPham::~HangHoaThucPham() {

}

bool HangHoaThucPham::TonKho() {
	//if (this->MaHangHoa == "S001")
	return true;
	return false;
}

bool HangHoaThucPham::KiemTraTonKho() {
	ThoiGianThuc x;
	x.KhoiTao();
	if (this->NgayXuatKho.SoSanhHaiNgay(x.getterThoiGianThuc()))
		return true;
	return false;
}




bool HangHoaThucPham::KiemTraHetHan() {
	ThoiGianThuc x;
	x.KhoiTao();
	if (x.getterThoiGianThuc().SoSanhHaiNgay(this->NgayHetHan))
		return true;
	return false;
}




void HangHoaThucPham::NhapThongTin() { 
	int y = HeightConsole / 5;
	do
	{
		VietBoxCoTieuDeCenTer(HeightConsole - 7, 10, "MA HANG HOA GOM TOI DA 10 KI TU (SO HOAC CHU)");
		gotoXY((float)WidthConsole / (float)7.53 + 14, y + 2);
		getline(cin, this->MaHangHoa);
		// xoa du lieu cu
		VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Back, "                                       ");
		if (this->MaHangHoa.length() > 10 || this->MaHangHoa.length() < 1) {
			gotoXY((float)WidthConsole / (float)7.53 + 14, y + 2);
			cout << "                                                        ";
			if (this->MaHangHoa.length() > 10) {
				VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Red, "MA HANG HOA QUA DAI!");
			}
			else {
				VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Red, "MA HANG HOA TOI THIEU 1 KI TU!");
			}
		}
	} while (this->MaHangHoa.length() > 10 || this->MaHangHoa.length() < 1);

	VietBoxCoTieuDeCenTer(HeightConsole - 7, ColorCode_Back, "                                                        ");

	do
	{
		VietBoxCoTieuDeCenTer(HeightConsole - 7, 10, "LOAI HANG HOA GOM TOI DA 10 KI TU!");
		gotoXY((float)WidthConsole / (float)7.53 + 12, y + 7);
		getline(cin, this->LoaiHang);
		// xoa du lieu cu
		VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Back, "                              ");
		if (this->LoaiHang.length() > 10 || this->LoaiHang.length() < 1) {
			gotoXY((float)WidthConsole / (float)7.53 + 12, y + 7);
			cout << "                                                          ";
			if (this->LoaiHang.length() > 10) {
				VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Red, "LOAI HANG QUA DAI!");
			}
			else {
				VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Red, "LOAI HANG TOI THIEU 1 KI TU!");
			}
		}
	} while (this->LoaiHang.length() > 10 || this->LoaiHang.length() < 1);

	VietBoxCoTieuDeCenTer(HeightConsole - 7, ColorCode_Back, "                                                        ");

	do
	{
		VietBoxCoTieuDeCenTer(HeightConsole - 7, 10, "TEN HANG HOA LA TEN MO TA SAN PHAM GOM TOI DA 40 KI TU");
		gotoXY((float)WidthConsole / (float)7.53 + 11, y + 12);
		getline(cin, this->TenHangHoa);
		VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Back, "                              ");
		if (this->TenHangHoa.length() > 40 || this->TenHangHoa.length() < 1) {
			gotoXY((float)WidthConsole / (float)7.53 + 11, y + 12);
			cout << "                                                           ";
			if (this->TenHangHoa.length() > 40) {
				VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Red, "TEN HANG HOA QUA DAI!");
			}
			else {
				VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Red, "TEN HANG TOI THIEU 1 KI TU!");
			}
		}
	} while (this->TenHangHoa.length() > 40 || this->TenHangHoa.length() < 1);

	VietBoxCoTieuDeCenTer(HeightConsole - 7, ColorCode_Back, "                                                        ");

	do
	{
		VietBoxCoTieuDeCenTer(HeightConsole - 7, 10, "DON VI TINH CUA HANG HOA GOM TOI DA 13 KI TU");
		gotoXY((float)WidthConsole / (float)7.53 + 14, y + 17);
		getline(cin, this->DonViTinh);
		VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Back, "                              ");
		if (this->DonViTinh.length() > 13 || this->DonViTinh.length() < 1) {
			gotoXY((float)WidthConsole / (float)7.53 + 14, y + 17);
			cout << "                                                        ";
			if (this->DonViTinh.length() > 13) {
				VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Red, "DON VI TINH QUA DAI!");
			}
			else {
				VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Red, "DON VI TINH TOI THIEU 1 KI TU!");
			}
		}
	} while (this->DonViTinh.length() > 13 || this->DonViTinh.length() < 1);

	VietBoxCoTieuDeCenTer(HeightConsole - 7, ColorCode_Back, "                                                        ");


	do
	{
		VietBoxCoTieuDeCenTer(HeightConsole - 7, 10, "DON GIA HOP LE VA TREN 1000 (VND)");
		gotoXY((float)WidthConsole / (float)7.53 + 16, y + 22);
		cin >> DonGia;
		VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Back, "                             ");
		if (this->DonGia < 1000 || cin.fail()) {
			gotoXY((float)WidthConsole / (float)7.53 + 16, y + 22);
			cout << "                                                      ";
			if (cin.fail()) {
				this->DonGia = INT_MAX;
				cin.clear();
				cin.ignore();
			}
			else if (this->DonGia < 1000) {
				VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Red, "DON GIA TOI THIEU 1000 VND!");
			}
		}
	} while (this->DonGia < 1000 || cin.fail());

	VietBoxCoTieuDeCenTer(HeightConsole - 7, ColorCode_Back, "                                                        ");

	cin.ignore();

	do
	{
		VietBoxCoTieuDeCenTer(HeightConsole - 7, 10, "MA KHO LUU HANG GOM TOI DA 13 KI TU");
		gotoXY((float)WidthConsole / (float)1.57 + 13, y + 2);
		getline(cin, this->MaKhoLuuHang);
		VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Back, "                              ");
		if (this->MaKhoLuuHang.length() > 13 || this->MaKhoLuuHang.length() < 1) {
			gotoXY((float)WidthConsole / (float)1.57 + 13, y + 2);
			cout << "                                     ";
			if (this->MaKhoLuuHang.length() > 13) {
				VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Red, "MA KHO LUU QUA DAI!");
			}
			else {
				VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Red, "MA KHO LUU TOI THIEU 1 KI TU!");
			}
		}
	} while (this->MaKhoLuuHang.length() > 13 || this->MaKhoLuuHang.length() < 1);


	NgaySanXuat.NhapNgay((float)WidthConsole / (float)1.57 + 16, y + 7);
	NgayHetHan.NhapNgay((float)WidthConsole / (float)1.57 + 16, y + 12);
	NgayNhapKho.NhapNgay((float)WidthConsole / (float)1.57 + 16, y + 17);
	NgayXuatKho.NhapNgay((float)WidthConsole / (float)1.57 + 16, y + 22);
}


void HangHoaThucPham::NhapFileThongTinHangHoa(ifstream& nhapfile) {
	getline(nhapfile, this->MaHangHoa, ',');
	nhapfile.seekg(1, 1);
	getline(nhapfile, this->LoaiHang, ',');
	nhapfile.seekg(1, 1);
	getline(nhapfile, this->TenHangHoa, ',');
	nhapfile.seekg(1, 1);
	getline(nhapfile, this->DonViTinh, ',');
	nhapfile.seekg(1, 1);
	nhapfile >> DonGia;
	nhapfile.seekg(2, 1);
	getline(nhapfile, this->MaKhoLuuHang, ',');
	nhapfile.seekg(1, 1);

	NgaySanXuat.NhapFileThongTinNgayThangTrongHangHoa(nhapfile);
	nhapfile.seekg(1, 1);
	NgayHetHan.NhapFileThongTinNgayThangTrongHangHoa(nhapfile);
	nhapfile.seekg(1, 1);
	NgayNhapKho.NhapFileThongTinNgayThangTrongHangHoa(nhapfile);
	nhapfile.seekg(1, 1);
	NgayXuatKho.NhapFileThongTinNgayThangTrongHangHoa(nhapfile);
	nhapfile.seekg(1, 1);
}

void HangHoaThucPham::XuatThongTinHangHoa(int y) {
	InChuoiCoMau((float)WidthConsole / (float)17, y, 7, this->MaHangHoa);
	InChuoiCoMau((float)WidthConsole / (float)7.53, y, 7, LoaiHang);
	InChuoiCoMau((float)WidthConsole / (float)4.58, y, 7, TenHangHoa);
	InChuoiCoMau((float)WidthConsole / (float)2.604, y, 7, DonViTinh);
	InChuoiCoMau((float)WidthConsole / (float)2.13, y, 7, to_string(DonGia));
	InChuoiCoMau((float)WidthConsole / (float)1.81, y, 7, MaKhoLuuHang);

	NgaySanXuat.XuatNgay((float)WidthConsole / (float)1.57, y); // 20
	NgayHetHan.XuatNgay((float)WidthConsole / (float)1.3766, y); // 20
	NgayNhapKho.XuatNgay((float)WidthConsole / (float)1.2267, y); // 20
	NgayXuatKho.XuatNgay((float)WidthConsole / (float)1.104, y); // 20

}

double HangHoaThucPham::_res_SuaThongTin_DonGia() {
	return this->DonGia;
}

string HangHoaThucPham::_res_SuaThongTin_LoaiHangHoa() {
	return this->LoaiHang;
}

string HangHoaThucPham::_res_SuaThongTin_MaKhoLuuHang() {
	return this->MaKhoLuuHang;
}

string HangHoaThucPham::_res_SuaThongTin_TenHangHoa() {
	return this->TenHangHoa;
}

string HangHoaThucPham::_res_SuaThongTin_DonViTinh() {
	return this->DonViTinh;
}


Date HangHoaThucPham::_res_SuaThongTin_NgayNhapKho() {
	return this->NgayNhapKho;
}


Date HangHoaThucPham::_res_SuaThongTin_NgaySanXuat() {
	return this->NgaySanXuat;
}

Date HangHoaThucPham::_res_SuaThongTin_NgayHetHan() {
	return this->NgayHetHan;
}

Date HangHoaThucPham::_res_SuaThongTin_NgayXuatKho() {
	return this->NgayXuatKho;
}

void HangHoaThucPham::SuaThongTin_DonGia(double DonGia) {
	this->DonGia = DonGia;
}

void HangHoaThucPham::SuaThongTin_LoaiHangHoa(string LoaiHang) {
	this->LoaiHang = LoaiHang;
}

void HangHoaThucPham::SuaThongTin_TenHangHoa(string TenHangHoa) {
	this->TenHangHoa = TenHangHoa;
}

void HangHoaThucPham::SuaThongTin_MaKhoLuuHang(string MaKhoLuuHang) {
	this->MaKhoLuuHang = MaKhoLuuHang;
}

void HangHoaThucPham::SuaThongTin_NgayHetHan(Date NgayHetHan) {
	this->NgayHetHan = NgayHetHan;
}

void HangHoaThucPham::SuaThongTin_NgayNhapKho(Date NgayNhapKho) {
	this->NgayNhapKho = NgayNhapKho;
}

void HangHoaThucPham::SuaThongTin_NgaySanXuat(Date NgaySanXuat) {
	this->NgaySanXuat = NgaySanXuat;
}

void HangHoaThucPham::SuaThongTin_NgayXuatKho(Date NgayXuatKho) {
	this->NgayXuatKho = NgayXuatKho;
}

void HangHoaThucPham::SuaThongTin_DonViTinh(string DonViTinh) {
	this->DonViTinh = DonViTinh;
}



bool HangHoaThucPham::KiemTraHangHoaHethanSuDung() {
	Date x;

	if (this->NgayHetHan.SoSanhHaiNgay((this->NgaySanXuat)) == false)
		return true;
	return false;
}

double HangHoaThucPham::getterDonGia() {
	return this->DonGia;
}

string HangHoaThucPham::getterMaHangHoa() {
	return this->MaHangHoa;
}

int HangHoaThucPham::_res_LayThongTin_ThangXuatKho() {
	return this->NgayXuatKho.getterThang();
}

int HangHoaThucPham::_res_LayThongTin_NamXuatKho() {
	return this->NgayXuatKho.getterNam();
}