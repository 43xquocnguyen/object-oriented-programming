#include "cong_ty.h"

CongTy::CongTy(){}
CongTy::~CongTy() {}


void CongTy::ThemThongTin() {
	NhanVien a;
	a.NhapThongTin();
	ds_nv.push_back(a);
}
void CongTy::XuatDanhSach() {
	Header_Table();
	int n = ds_nv.size();
	for (int i = 0; i < n; i++) {
		cout << setfill(' ');
		cout << setw(12) << left << i + 1;
		ds_nv[i].XuatThongTin();
		cout << endl;
	}
}
bool CongTy::KiemTraDaCoDuLieu() {
	return ds_nv.size();
}
long long  CongTy::TinhTongTienThucLanh() {
	int n = ds_nv.size();
	long long tong = 0;
	for (int i = 0; i < n; i++) {
		tong += ds_nv[i].TinhTienThucLanh();
	}
	return tong;
}
long CongTy::TimMucLuongCoBanThapNhat() {
	int min = ds_nv[0].GetLuongCoBan();
	int size = ds_nv.size();
	for (int i = 0; i < size; i++) {
		if (min > ds_nv[i].GetLuongCoBan()) {
			min = ds_nv[i].GetLuongCoBan();
		}
	}
	return min;
}
void CongTy::XuatDanhSachNhanVienCoMucLuongCBThapNhat() {
	int size = ds_nv.size();
	Header_Table();
	int j = 1;
	for (int i = 0; i < size; i++) {
		if (ds_nv[i].GetLuongCoBan() == TimMucLuongCoBanThapNhat()) {
			cout << setfill(' ');
			cout << setw(12) << left << j;
			ds_nv[i].XuatThongTin();
			cout << endl;
			j++;
		}
	}
}
int CongTy::DemSoLuongNVCoMucThuongTren_1200000() {
	int soNV = 0, size = ds_nv.size();
	for (int i = 0; i < size; i++) {
		if (ds_nv[i].GetLuongThuong() > 12000000) {
			soNV++;
		}
	}
	return soNV;
}
bool CongTy::KiemTraTrungPhongBan() {
	int size = ds_nv.size();
	for (int i = 0; i < size - 1; i++) 
		for (int j = i + 1; j < size; j++) 
			if (ds_nv[i].GetPhongBan().compare(ds_nv[j].GetPhongBan()))
				return false;
	return true;
}
void CongTy::SapXepTheoPhongBanHoacMSNV() {
	int size = ds_nv.size();
	for (int i = 0; i < size; i++) {
		if (KiemTraTrungPhongBan()) {
			for (int j = 0; j < size - 1; j++) {
				for (int k = j + 1; k < size; k++) {
					if (ds_nv[j].GetPhongBan()[0] > ds_nv[k].GetPhongBan()[0])
						swap(ds_nv[j], ds_nv[k]);
				}
			}
		}
		else {
			for (int j = 0; j < size - 1; j++) {
				for (int k = j + 1; k < size; k++) {
					if (ds_nv[j].GetMSNV()[0] < ds_nv[k].GetMSNV()[0])
						swap(ds_nv[j], ds_nv[k]);
				}
			}
		}
	}
}
