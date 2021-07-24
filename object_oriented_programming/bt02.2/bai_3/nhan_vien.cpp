#include "nhan_vien.h"

NhanVien::NhanVien() {

}
NhanVien::~NhanVien() {

}

void NhanVien::NhapThongTin() {
	do
	{
		cout << "NHAP MA SO NHAN VIEN: ";
		getline(cin, this->maNhanVien);
		if (this->maNhanVien.length() > 8 || this->maNhanVien.length() < 1) {
			cout << "MA SO NHAN VIEN TOI DA CO 8 KI TU\n";
		}
	} while (this->maNhanVien.length() > 8 || this->maNhanVien.length() < 1);

	do
	{
		cout << "NHAP HO TEN NHAN VIEN: ";
		getline(cin, this->hoTen);
		if (this->hoTen.length() > 20 || this->hoTen.length() < 1) {
			cout << "HO TEN NHAN VIEN TOI DA CO 20 KI TU\n";
		}
	} while (this->hoTen.length() > 20 || this->hoTen.length() < 1);

	do
	{
		cout << "NHAP PHONG BAN NHAN VIEN: ";
		getline(cin, this->phongBan);
		if (this->phongBan.length() > 10 || this->phongBan.length() < 1) {
			cout << "TEN PHONG BAN NHAN VIEN CO TOI DA 10 KI TU\n";
		}
	} while (this->phongBan.length() > 10 || this->phongBan.length() < 1);

	do
	{
		cout << "NHAP LUONG CO BAN: ";
		cin >> this->luongCoBan;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			this->luongCoBan = -1;
		}
		if (this->luongCoBan < 0) {
			cout << "LUONG CO BAN KHONG HOP LE\n";
		}
	} while (this->luongCoBan < 0);

	do
	{
		cout << "NHAP LUONG THUONG: ";
		cin >> this->luongThuong;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			this->luongThuong = -1;
		}
		if (this->luongThuong < 0) {
			cout << "LUONG THUONG KHONG HOP LE\n";
		}
	} while (this->luongThuong < 0);
	
	this->thucLanh = this->luongCoBan + this->luongThuong;
}
void NhanVien::XuatThongTin() {
	cout << setfill(' ');
	cout << setw(15) << left << this->maNhanVien;
	cout << setw(30) << left << this->hoTen;
	cout << setw(15) << left << this->phongBan;
	cout << setw(20) << left << this->luongCoBan;
	cout << setw(20) << left << this->luongThuong;
	cout << setw(20) << left << this->thucLanh;
}
long long NhanVien::TinhTienThucLanh() {
	return this->thucLanh;
}
long NhanVien::GetLuongCoBan() {
	return this->luongCoBan;
}
long NhanVien::GetLuongThuong() {
	return this->luongThuong;
}
string NhanVien::GetMSNV() {
	return this->maNhanVien;
}
string NhanVien::GetPhongBan() {
	return this->phongBan;
}