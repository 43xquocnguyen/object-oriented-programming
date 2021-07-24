#pragma once
#include "nhan_vien.h"
#include <vector>

class CongTy
{
private:
	vector<NhanVien> ds_nv;
	void Header_Table() {
		cout << setfill(' ');
		cout << setw(12) << left << "STT";
		cout << setw(15) << left << "MSNV";
		cout << setw(30) << left << "HO TEN";
		cout << setw(15) << left << "PHONG BAN";
		cout << setw(20) << left << "LUONG CO BAN";
		cout << setw(20) << left << "LUONG THUONG";
		cout << setw(20) << left << "THUC LANH" << endl;
		cout << setfill('-') << setw(150) << "-" << endl;
	}
public:
	CongTy();
	~CongTy();

	void ThemThongTin();
	void XuatDanhSach();
	bool KiemTraDaCoDuLieu();
	long long TinhTongTienThucLanh();
	long TimMucLuongCoBanThapNhat();
	void XuatDanhSachNhanVienCoMucLuongCBThapNhat();
	int DemSoLuongNVCoMucThuongTren_1200000();
	bool KiemTraTrungPhongBan();
	void SapXepTheoPhongBanHoacMSNV();
};

