#pragma once
#include "HoTro.h"
#include "HangHoa.h"
#include <vector>
#include <iostream>
#include "HangHoaThucPham.h"

class QuanLiNhapKho {
private:
	vector<HangHoa*> list;
	vector<HangHoa*> list_copy;
	vector<HangHoa*> hangTonKho;
	vector<HangHoa*> daBan;
	vector<HangHoa*> hetHan;
	//vector<HangHoa>hetHan;


	vector <Date> QuanLiNgayThangNhapKhoHangHoa; // Quản lí số ngày xuất kho hàng hóa
	vector<unsigned int > QuanLiTienBanDuocTrongTungNgay; // Quản lí số tiền bán được trong từng ngày
	vector <int > QuanLiSoNgayBanDuocTrongMotThang; // Kiểm tra xem 1 tháng có bao nhiêu ngày bán được hàng
	vector<unsigned int >QuanLiTienBanDuocTrongTungThang; // Quản lí số tiền bán được trong một tháng
	vector<Date>QuanLiCacThangTrongNam; // Quản lí các tháng bán ra

	//vector <Date> QuanLiNgayThangNhapKhoHangHoa;
	//vector<unsigned int > QuanLiTienBanDuocTrongTungNgay;
public:
	QuanLiNhapKho();
	~QuanLiNhapKho();

	void NhapHangHoa();
	void LuuThongTin();
	void XuatThongTin(vector<HangHoa*>, string);

	void XuatThongTinTatCa();
	void XuatThongTinHangHoaTonKho();
	void XuatThongTinHangHoaDaBan();
	void XuatThongTinHangHoaDaHetHan();

	void XuatTongTienBanDuoc(); // Xuất tổng số tiền bán được
	double TongTienBanDuoc(); // Lấy ra giá trị tổng số tiền bán được

	void XuatTongTienRong();
	void SortHangHoa();
	//void LuuThongTinNgayXuat();
	//void XuatThongTinNgayXuat();
	void KhoiTaoTongSoTienBanDuocTrong_1_Ngay();// ok
	void TinhTongSoTienBanDuocTrong_Mot_Ngay();// ok


	//void TinhTongSoTienBanDuocTrong_1_Thang();
	void KhoiTaoSoLanXuatHienCuaCacNgayTrong_1Thang();
	void KhoiTaoTongSoTienBanDuocTrong_Tung_Thang();
	void TinhTongSoTienBanDuocTrong_Tung_Thang();
	void KhoiTaoQuanLiCacThangTrongNam();


	void XuatTienBanRaTungNgay(); //c
	void XuatTienBanRaTungThang();

	void xuattest();
};

