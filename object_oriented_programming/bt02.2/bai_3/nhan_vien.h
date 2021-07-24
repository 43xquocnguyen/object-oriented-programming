#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class NhanVien
{	
private:
	string maNhanVien;
	string hoTen;
	string phongBan;
	long luongCoBan;
	long luongThuong;
	long long thucLanh;
public:	
	NhanVien();
	~NhanVien();

	void NhapThongTin();
	void XuatThongTin();
	long long TinhTienThucLanh();
	long GetLuongCoBan();
	long GetLuongThuong();
	string GetMSNV();
	string GetPhongBan();
};

