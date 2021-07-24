#include "cong_ty.h"

void MENU() {
	CongTy *congty = new CongTy;
	while (9696969696969)
	{
		system("cls");
		cout << "1. THEM THONG TIN 1 NHAN VIEN\n";
		cout << "2. XUAT DANH SACH THONG TIN NHAN VIEN\n";
		cout << "3. TINH TONG TIEN THUC LANH CUA CA CONG TY\n";
		cout << "4. XUAT DANH SACH NHAN CO MUC LUONG CO BAN THAP NHAT\n";
		cout << "5. DEM SO LUONG NHAN VIEN CO MUC THUONG TREN 1200000\n";
		cout << "6. SAP XEP DANH SACH NHAN VIEN THEO PHONG BAN HOAC MSNV\n";
		cout << "0. KET THUC\n\n";
		cout << "NHAP VAO LUA CHON CUA BAN: ";
		char luachon;
		cin >> luachon;
		cin.ignore();
		
		if (luachon == '0') {
			system("cls");
			cout << "CHUONG TRINH KET THUC\n";
			break;
		}

		switch (luachon)
		{
		case '1': {
			system("cls");
			cout << "NHAP VAO CAC THONG TIN NHAN VIEN\n";
			congty->ThemThongTin();
			break;
		}
		case '2': {
			system("cls");
			if (congty->KiemTraDaCoDuLieu()) {
				cout << "\t\t\t\t\t\t BANG THONG TIN NHAN VIEN\n\n";
				congty->XuatDanhSach();
			}
			else {
				cout << "CHUA CO DU LIEU CUA CA CONG TY! VUI LONG KIEM TRA LAI\n";
			}
			system("pause");
			break;
		}
		case '3': {
			system("cls");
			if (congty->KiemTraDaCoDuLieu()) {
				cout << "TONG TIEN THUC LANH CUA CA CONG TY LA: ";
				cout << congty->TinhTongTienThucLanh() << endl;
			}
			else {
				cout << "CHUA CO DU LIEU CUA CA CONG TY! VUI LONG KIEM TRA LAI\n";
			}
			system("pause");
			break;
		}
		case '4': {
			system("cls");
			if (congty->KiemTraDaCoDuLieu()) {
				cout << "\t\t\t\t\tBANG THONG TIN NHAN VIEN CO MUC LUONG CB THAP NHAT\n\n";
				congty->XuatDanhSachNhanVienCoMucLuongCBThapNhat();
			}
			else {
				cout << "CHUA CO DU LIEU CUA CA CONG TY! VUI LONG KIEM TRA LAI\n";
			}
			system("pause");
			break;
		}
		case '5': {
			system("cls");
			if (congty->KiemTraDaCoDuLieu()) {
				cout << "SO LUONG NHAN VIEN CO MUC LUONG THUONG >= 1200000: ";
				cout << congty->DemSoLuongNVCoMucThuongTren_1200000() << " nhan vien" << endl;
			}
			else {
				cout << "CHUA CO DU LIEU CUA CA CONG TY! VUI LONG KIEM TRA LAI\n";
			}
			system("pause");
			break;
		}
		case '6': {
			system("cls");
			if (congty->KiemTraDaCoDuLieu()) {
				cout << "\t\t\t\t\t BANG THONG TIN NHAN VIEN SAU KHI SAP XEP\n\n";
				congty->SapXepTheoPhongBanHoacMSNV();
				congty->XuatDanhSach();
			}
			else {
				cout << "CHUA CO DU LIEU CUA CA CONG TY! VUI LONG KIEM TRA LAI\n";
			}
			system("pause");
			break;
		}
		default: {
			system("cls");
			cout << "LUA CHON KHONG HOP LE! NHAN 1 PHIM BAT KI DE THU LAI\n";
			system("pause");
		}
		}
	}
	delete congty;
}
int main() {
	MENU();
	return 0;
}