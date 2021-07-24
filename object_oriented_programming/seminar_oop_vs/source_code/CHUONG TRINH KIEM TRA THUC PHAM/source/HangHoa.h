#pragma once
#include<iostream>
#include"Date.h"
//#include"Menu.h"

using namespace std;

class HangHoa {
protected:
	Date x;
	string MaHangHoa = "Khong co";
	string TenHangHoa;
	unsigned int DonGia;
	string DonViTinh; // Thêm thuộc tính đơn vị tính 

public:
	HangHoa();
	~HangHoa();
	virtual bool TonKho() = 0;
	virtual void NhapFileThongTinHangHoa(ifstream&) = 0; 
	virtual void NhapThongTin() = 0;
	virtual void XuatThongTinHangHoa(int) = 0;

	virtual bool KiemTraHetHan() = 0;
	virtual bool KiemTraTonKho() = 0;

	virtual double getterDonGia() = 0;
	virtual string getterMaHangHoa() = 0;
//	virtual Date getterNgayXuatKho() = 0;

	virtual Date _res_SuaThongTin_NgayXuatKho() = 0;
	virtual int _res_LayThongTin_ThangXuatKho() = 0;
	virtual int _res_LayThongTin_NamXuatKho() = 0;
};



