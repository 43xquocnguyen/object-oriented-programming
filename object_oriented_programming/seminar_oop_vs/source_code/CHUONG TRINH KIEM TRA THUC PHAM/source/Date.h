#pragma once
//#include"HangHoa.h"
#include<vector>
#include<fstream>
#include<iostream>
//#include"HangHoaThucPham.h"

using namespace std;

class Date {
public:
	int Ngay;
	int Thang;
	int Nam;
protected:
	unsigned long getTotalDay();
	bool checkNam();
	int getDayofMonth();
	vector<short> dayz{ 31,28,31,30,31,30,31,31,30,31,30,31 };
public:
	Date();
	Date(int, int);
	Date(int, int, int);

	void setterNgay(int Ngay);
	void setterThang(int Thang);
	void setterNam(int Nam);

	int getterNgay();
	int getterThang();
	int getterNam();


	void NhapNgay(int, int);
	void XuatNgay(float, int);
	bool NgayDaHopLe();

	void testxuatngay();
	
	bool SoSanhHaiNgay(Date);
	
	bool HaiNgayBangNhau(Date);
	void NhapFileThongTinNgayThangTrongHangHoa(ifstream&); // Nhập file dữ liệu ngày
	//friend class HangHoa;
	//friend class HangHoaThucPham;

};
