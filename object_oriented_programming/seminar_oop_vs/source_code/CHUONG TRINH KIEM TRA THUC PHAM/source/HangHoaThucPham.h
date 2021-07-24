#pragma once
#include<iostream>
#include<iomanip>
#include"HangHoa.h"
#include"Date.h"
//#include"ThoiGianThuc.h"

class HangHoaThucPham:public HangHoa {
private:
	string LoaiHang;
	string MaKhoLuuHang;
	Date NgaySanXuat;
	Date NgayHetHan;
	Date NgayNhapKho;
	Date NgayXuatKho;

public:

	HangHoaThucPham();
	~HangHoaThucPham();
	
	void SuaThongTin_TenHangHoa(string TenHangHoa);
	void SuaThongTin_DonGia(double DonGia);
	void SuaThongTin_LoaiHangHoa(string LoaiHang);
	void SuaThongTin_MaKhoLuuHang(string MaKhoLuuHang);
	void SuaThongTin_NgaySanXuat(Date NgaySanXuat);
	void SuaThongTin_NgayHetHan(Date NgayHetHan);
	void SuaThongTin_NgayNhapKho(Date NgayNhapKho);
	void SuaThongTin_NgayXuatKho(Date NgayXuatKho);
	void SuaThongTin_DonViTinh(string DonViTinh);

	string _res_SuaThongTin_TenHangHoa();
	double _res_SuaThongTin_DonGia();
	string _res_SuaThongTin_LoaiHangHoa();
	string _res_SuaThongTin_MaKhoLuuHang();
	Date _res_SuaThongTin_NgaySanXuat();
	Date _res_SuaThongTin_NgayHetHan();
	Date _res_SuaThongTin_NgayNhapKho();
	Date _res_SuaThongTin_NgayXuatKho();
	string _res_SuaThongTin_DonViTinh();

	bool KiemTraHangHoaHethanSuDung();

	bool TonKho();
	void NhapThongTin();
	virtual void NhapFileThongTinHangHoa(ifstream &); // Nhập file thông tin hàng hóa
	void XuatThongTinHangHoa(int); // Hiển thị hàng đã nhập 



	bool KiemTraHetHan();
	bool KiemTraTonKho();

	double getterDonGia();
	string getterMaHangHoa();

	int _res_LayThongTin_ThangXuatKho();
	int _res_LayThongTin_NamXuatKho();
};

