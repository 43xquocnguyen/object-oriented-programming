#include "QuanLiNhapKho.h"


QuanLiNhapKho::QuanLiNhapKho() {
	this->list.resize(0);
	this->daBan.resize(0);
	this->hetHan.resize(0);
	this->hangTonKho.resize(0);
}
QuanLiNhapKho::~QuanLiNhapKho() {

}

void QuanLiNhapKho::NhapHangHoa() {
	// code nhap hang hoa tu ban phim
	VeBoxInput();
	HangHoa* t = new HangHoaThucPham;
	t->NhapThongTin(); // nhap o vi tri
	this->list.push_back(t);
}
void QuanLiNhapKho::LuuThongTin() {
	// doc file
	ifstream nhapfile;
	nhapfile.open("ThongTinHangHoa.TXT", ios_base::in);
	HangHoa* t;
	for (int i = 0; i < 66; i++) {
		t = new HangHoaThucPham;
		t->NhapFileThongTinHangHoa(nhapfile);
		//if (t->TonKho()) {
			this->list.push_back(t);
	//	}
	}
	nhapfile.close();

#if 0
	for (int i = 0; i < list.size(); i++) {
		list_copy.push_back(list[i]);
	}

	for (int i = 0; i < this->list.size(); i++)
	{
		if (this->list[i]->KiemTraTonKho()) {
			this->hangTonKho.push_back(this->list[i]);
		}
		else if (!this->list[i]->KiemTraTonKho()) {
			this->daBan.push_back(this->list[i]);
		}
		//else if (this->list[i]->KiemTraHetHan()) {
		//	this->hetHan.push_back(this->list[i]);
		//}
	}

	for (int i = 0; i < this->list_copy.size(); i++) {
		if (this->list[i]->KiemTraHetHan()) {
			this->hetHan.push_back(this->list[i]);
		}
	}
#endif
#if 1 
		
			for (int i = 0; i < this->list.size(); i++)
	{
		if (this->list[i]->KiemTraTonKho()) {
			if (this->list[i]->KiemTraHetHan()) {
				HangHoa* t = new HangHoaThucPham;
				t = this->list[i];
				this->hetHan.push_back(t);
			}
			this->hangTonKho.push_back(this->list[i]);
		}
		else if (!this->list[i]->KiemTraTonKho()) {
			if (this->list[i]->KiemTraHetHan()) {
				HangHoa* t = new HangHoaThucPham;
				t = this->list[i];
				this->hetHan.push_back(t);
			}
			this->daBan.push_back(this->list[i]);
		}
	}
		
#endif
}
void QuanLiNhapKho::XuatThongTin(vector<HangHoa*> that, string text) {
	int soLuongInRa, i, phanTuDauTrangKeTiep = 0;
	int soLuongInRaMax = (HeightConsole * 8 / 10) - (HeightConsole / 6 + 3) + 1;
	bool isTrangCuoi = false;
	do {
		clrscr();
		soLuongInRa = 0;
		i = phanTuDauTrangKeTiep;
		for (; i < that.size(); i++) {
			if (whereY() != HeightConsole * 8 / 10) {
				InChuoiCoMau(WidthConsole / 52, HeightConsole / 6 + 3 + soLuongInRa, 7, to_string((i + 1)));
				that[i]->XuatThongTinHangHoa(HeightConsole / 6 + 3 + soLuongInRa);
				soLuongInRa++;
			}
			else {
				InSoTrang(i, soLuongInRaMax, this->list.size());
				break;
			}
		}
		if (that.size() <= soLuongInRaMax || isTrangCuoi) {
			// co duy nhat 1 trang hoac dang o trang cuoi
			InSoTrang(that.size(), soLuongInRaMax, that.size());
		}
		InChuoiCoMau((float)WidthConsole / (float)27, HeightConsole * 9 / 10, ColorCode_DarkWhite, "NHAN <- VA -> DE CHUYEN TRANG!");
		InChuoiCoMau((float)WidthConsole / (float)1.2, HeightConsole * 9 / 10, ColorCode_DarkWhite, "NHAN ESC DE THOAT!");
		KeBangXuat();
		VietBoxCoTieuDeCenTer(HeightConsole - HeightConsole + 3, 78, text);
		KeKhungXuat(soLuongInRa);
		char press = _getch();
		if (press == -32) {
			press = _getch();
			if (press == 75) {
				if (phanTuDauTrangKeTiep - soLuongInRa >= 0) {
					phanTuDauTrangKeTiep -= soLuongInRaMax;
					isTrangCuoi = false;
				}
			}
			else if (press == 77) {
				if (phanTuDauTrangKeTiep + soLuongInRa < that.size()) {

					phanTuDauTrangKeTiep += soLuongInRaMax;

					if (phanTuDauTrangKeTiep + soLuongInRaMax >= that.size()) {
						isTrangCuoi = true;
					}
				}
			}
			else {
				VietBoxCoTieuDeCenTer(HeightConsole - 4, ColorCode_Red, "PHIM KHONG HOP LE!");
			}
		}
		else if (press == 27) {
			break;
		}
		else {
			VietBoxCoTieuDeCenTer(HeightConsole - 4, ColorCode_Red, "PHIM KHONG HOP LE!");
		}
	} while (true);
}


void QuanLiNhapKho::XuatTongTienBanDuoc() {
	KeTongTien(TongTienBanDuoc()); 
	InChuoiCoMau((float)WidthConsole / (float)1.3, HeightConsole * 9 / 10, ColorCode_DarkRed, "NHAN PHIM BAT KI DE THOAT!");
	cin.get();
}

void QuanLiNhapKho::XuatTongTienRong() {
	KeBangXuatTienRong();
	InChuoiCoMau((float)WidthConsole / (float)1.3, HeightConsole * 9 / 10, ColorCode_DarkRed, "NHAN PHIM BAT KI DE THOAT!");
	cin.get();
}

void QuanLiNhapKho::XuatThongTinTatCa() {
	this->XuatThongTin(this->list, "TOAN BO THONG TIN HANG HANG HOA");
}
void QuanLiNhapKho::XuatThongTinHangHoaTonKho() {
	this->XuatThongTin(this->hangTonKho, "THONG TIN HANG HANG HOA TON KHO");
}
void QuanLiNhapKho::XuatThongTinHangHoaDaBan() {
	this->XuatThongTin(this->daBan, "THONG TIN HANG HANG HOA DA BAN");
} 
void QuanLiNhapKho::XuatThongTinHangHoaDaHetHan() {
	this->XuatThongTin(this->hetHan, "THONG TIN HANG HANG HOA DA HET HAN");
}

double QuanLiNhapKho::TongTienBanDuoc() {
	
	double res = 0;
	for (int i = 0; i < list.size(); i++) {
		res += list[i]->getterDonGia();
	}

	
	return res;
}
void QuanLiNhapKho::SortHangHoa() {
	for (int i = 0; i < list.size() - 1; i++) {
		for (int j = i + 1; j < list.size(); j++) {
			if (list[i]->_res_SuaThongTin_NgayXuatKho().SoSanhHaiNgay(list[j]->_res_SuaThongTin_NgayXuatKho())) {
				HangHoa* t = new HangHoaThucPham;
				t = list[i];
				list[i] = list[j];
				list[j] = t;
			}
		}
	}
}


void QuanLiNhapKho::KhoiTaoTongSoTienBanDuocTrong_1_Ngay() {
	SortHangHoa();
	//XuatThongTin();
	QuanLiTienBanDuocTrongTungNgay.push_back(list[0]->getterDonGia());
	QuanLiNgayThangNhapKhoHangHoa.push_back(list[0]->_res_SuaThongTin_NgayXuatKho());
	int j = 1;
	int tral = 0;
	for (int i = 1; i < list.size(); i++) {
		if (list[i]->_res_SuaThongTin_NgayXuatKho().HaiNgayBangNhau(QuanLiNgayThangNhapKhoHangHoa[tral]) == false) {
			QuanLiNgayThangNhapKhoHangHoa.push_back(list[i]->_res_SuaThongTin_NgayXuatKho());
			QuanLiTienBanDuocTrongTungNgay.push_back(list[i]->getterDonGia());
			j++;
			tral++;
		}

		else {
			QuanLiTienBanDuocTrongTungNgay[tral] += list[i]->getterDonGia();
		}
	}
}
void QuanLiNhapKho::TinhTongSoTienBanDuocTrong_Mot_Ngay() {
	//KhoiTaoTongSoTienBanDuocTrong_1_Ngay();
	for (int i = 0; i < QuanLiNgayThangNhapKhoHangHoa.size(); i++) {
		QuanLiNgayThangNhapKhoHangHoa[i].testxuatngay();
		cout << " " << QuanLiTienBanDuocTrongTungNgay[i] << " \t ";
	}
	cout << "\n";

	for (int i = 0; i < QuanLiTienBanDuocTrongTungNgay.size(); i++) {
		//cout << QuanLiTienBanDuocTrongTungNgay[i] << " \t ";
	}



}

void QuanLiNhapKho::XuatTienBanRaTungNgay() {
	//this->KhoiTaoTongSoTienBanDuocTrong_1_Ngay();

	int y = HeightConsole / 7;
	int size = QuanLiNgayThangNhapKhoHangHoa.size();
	int soLuongInRa, i, PhanTuKe = 0;
	float soLuongInRaMax = ((float)HeightConsole / (float)1.1739 - y) / 3;
	bool isTrangCuoi = false;

	do {
		clrscr();
		VietBoxCoTieuDeCenTer(3, ColorCode_Blue, "SO TIEN BAN RA THEO NGAY");
		soLuongInRa = 0;
		i = PhanTuKe;
		for (; i < size; i++)
		{
			if (whereY() < HeightConsole * 8 / 10) {
				++soLuongInRa;
				BoxCoChuCenter((float)WidthConsole / (float)3.45, y + 3 * soLuongInRa, 21, 2, ColorCode_DarkBlue, to_string(i + 1));
				unsigned int x = this->QuanLiTienBanDuocTrongTungNgay[i];
				BoxCoChuCenter(WidthConsole / 2 - (WidthConsole / 16), y + 3 * soLuongInRa, 21, 2, ColorCode_DarkBlue, DoiDateThanhString(QuanLiNgayThangNhapKhoHangHoa[i]));
				BoxCoChuCenter((float)WidthConsole / (float)1.7, y + 3 * soLuongInRa, 21, 2, ColorCode_DarkBlue, to_string(x) + " VND");
				//BoxCoChuCenter((float)WidthConsole / (float)3.5, y + 3 * soLuongInRa, 20, 2, ColorCode_Blue, to_string(i + 1));
				//unsigned int x = this->QuanLiTienBanDuocTrongTungNgay[i];
				//BoxCoChuCenter(WidthConsole / 2 - (WidthConsole / 25), y + 3 * soLuongInRa, 20, 2, ColorCode_Blue, DoiDateThanhString(QuanLiNgayThangNhapKhoHangHoa[i]));
				//BoxCoChuCenter((float)WidthConsole / (float)1.6, y + 3 * soLuongInRa, 20, 2, ColorCode_Blue, to_string(x) + " VND");
			}
			else {
				InSoTrang(i, soLuongInRaMax, size);
				break;
			}
		}
		InChuoiCoMau((float)WidthConsole / (float)27, HeightConsole * 9 / 10, ColorCode_DarkPink, "NHAN <- VA -> DE CHUYEN TRANG!");
		InChuoiCoMau((float)WidthConsole / (float)1.2, HeightConsole * 9 / 10, ColorCode_DarkPink, "NHAN ESC DE THOAT!");
		KeBangTinhTien(1);
		if (size <= soLuongInRaMax || isTrangCuoi) {
			// co duy nhat 1 trang hoac dang o trang cuoi
			InSoTrang(size, soLuongInRaMax, size);
		}
		char press = _getch();
		if (press == -32) {
			press = _getch();
			if (press == 75) {
				if (PhanTuKe - soLuongInRa >= 0) {
					clrscr();
					PhanTuKe -= soLuongInRaMax;
					isTrangCuoi = false;
				}
			}
			else if (press == 77) {
				if (PhanTuKe + soLuongInRa < size) {
					clrscr();
					PhanTuKe += soLuongInRaMax;
					if (PhanTuKe + soLuongInRaMax >= size) {
						isTrangCuoi = true;
					}
				}
			}
			else {
				VietBoxCoTieuDeCenTer(HeightConsole - 4, ColorCode_Red, "PHIM KHONG HOP LE!");
			}
		}
		else if (press == 27) {
			break;
		}
		else {
			VietBoxCoTieuDeCenTer(HeightConsole - 4, ColorCode_Red, "PHIM KHONG HOP LE!");
		}
 	} while (true);
}


void QuanLiNhapKho::XuatTienBanRaTungThang() {

	int y = HeightConsole / 7;
	int size = QuanLiSoNgayBanDuocTrongMotThang.size();
	int soLuongInRa, i, PhanTuKe = 0;
	float soLuongInRaMax = ((float)HeightConsole / (float)1.1739 - y) / 3;
	bool isTrangCuoi = false;

	do {
		clrscr();
		VietBoxCoTieuDeCenTer(3, ColorCode_DarkCyan, "SO TIEN BAN RA THEO THANG");
		soLuongInRa = 0;
		i = PhanTuKe;
		int t = 0;
		int k = 0;
		int fell = 0;
		unsigned int arr[100];
		//arr[0] = 0;
	//	for (int f = 1; f < size; f++) {
	//		arr[f] = this->QuanLiTienBanDuocTrongTungThang[QuanLiSoNgayBanDuocTrongMotThang[f] - 1 + fell - 1];
	//		fell = fell + QuanLiSoNgayBanDuocTrongMotThang[f];
	//	}
		
		unsigned int temp = 0;
		for (; i < size; i++)
		{
			if (whereY() < HeightConsole * 8 / 10) {
				++soLuongInRa;
				
				BoxCoChuCenter((float)WidthConsole / (float)3.45, y + 3 * soLuongInRa, 21, 2, ColorCode_Blue, to_string(i + 1));
				unsigned int x = this->QuanLiTienBanDuocTrongTungThang[QuanLiSoNgayBanDuocTrongMotThang[i] - 1 + t] - temp;
				temp = this->QuanLiTienBanDuocTrongTungThang[QuanLiSoNgayBanDuocTrongMotThang[i] - 1 + t];
				t = t + QuanLiSoNgayBanDuocTrongMotThang[i];
				
				BoxCoChuCenter(WidthConsole / 2 - (WidthConsole / 16), y + 3 * soLuongInRa, 21, 2, ColorCode_Blue, DoiDateThanhStringKhongCoNgay(QuanLiCacThangTrongNam[i]));
				BoxCoChuCenter((float)WidthConsole / (float)1.7, y + 3 * soLuongInRa, 21, 2, ColorCode_Blue, to_string(x) + " VND");
			
			}
			else {
				InSoTrang(i, soLuongInRaMax, size);
				break;
			}
		}
		InChuoiCoMau((float)WidthConsole / (float)27, HeightConsole * 9 / 10, ColorCode_DarkPink, "NHAN <- VA -> DE CHUYEN TRANG!");
		InChuoiCoMau((float)WidthConsole / (float)1.2, HeightConsole * 9 / 10, ColorCode_DarkPink, "NHAN ESC DE THOAT!");
		KeBangTinhTien(0);
		if (size <= soLuongInRaMax || isTrangCuoi) {
			// co duy nhat 1 trang hoac dang o trang cuoi
			InSoTrang(size, soLuongInRaMax, size);
		}
		char press = _getch();
		if (press == -32) {
			press = _getch();
			if (press == 75) {
				if (PhanTuKe - soLuongInRa >= 0) {
					clrscr();
					PhanTuKe -= soLuongInRaMax;
					isTrangCuoi = false;
				}
			}
			else if (press == 77) {
				if (PhanTuKe + soLuongInRa < size) {
					clrscr();
					PhanTuKe += soLuongInRaMax;
					if (PhanTuKe + soLuongInRaMax >= size) {
						isTrangCuoi = true;
					}
				}
			}
			else {
				VietBoxCoTieuDeCenTer(HeightConsole - 4, ColorCode_Red, "PHIM KHONG HOP LE!");
			}
		}
		else if (press == 27) {
			break;
		}
		else {
			VietBoxCoTieuDeCenTer(HeightConsole - 4, ColorCode_Red, "PHIM KHONG HOP LE!");
		}
	} while (true);
}

void QuanLiNhapKho::TinhTongSoTienBanDuocTrong_Tung_Thang() {
	//KhoiTaoTongSoTienBanDuocTrong_Tung_Thang();

	for (int i = 0; i < QuanLiTienBanDuocTrongTungThang.size(); i++) {
		cout << "\n" << QuanLiTienBanDuocTrongTungThang[i] << "\n";

	}
	int t = 0;
	for (int i = 0; i < QuanLiSoNgayBanDuocTrongMotThang.size(); i++) {
		cout << QuanLiTienBanDuocTrongTungThang[QuanLiSoNgayBanDuocTrongMotThang[i] - 1 + t] << " ";
		t = t + QuanLiSoNgayBanDuocTrongMotThang[i];
	}
}


void QuanLiNhapKho::KhoiTaoQuanLiCacThangTrongNam() {
	int thang = QuanLiNgayThangNhapKhoHangHoa[0].getterThang();
	int nam = QuanLiNgayThangNhapKhoHangHoa[0].getterNam();
	Date x = Date(thang, nam);
	QuanLiCacThangTrongNam.push_back(x);
	int dem = 1;
	for (int i = 1; i < QuanLiNgayThangNhapKhoHangHoa.size(); i++) {
		if (QuanLiNgayThangNhapKhoHangHoa[i].getterThang() == QuanLiNgayThangNhapKhoHangHoa[i - 1].getterThang() && QuanLiNgayThangNhapKhoHangHoa[i].getterNam() == QuanLiNgayThangNhapKhoHangHoa[i - 1].getterNam()) {
			++dem;
		}

		else {
			Date y = Date(QuanLiNgayThangNhapKhoHangHoa[i].getterThang(), QuanLiNgayThangNhapKhoHangHoa[i].getterNam());
			QuanLiCacThangTrongNam.push_back(y);
			dem = 1;
		}
	}

	for (int i = 0; i < QuanLiCacThangTrongNam.size(); i++) {
		QuanLiCacThangTrongNam[i].testxuatngay();
	}
}



void QuanLiNhapKho::KhoiTaoTongSoTienBanDuocTrong_Tung_Thang() {
	//KhoiTaoSoLanXuatHienCuaCacNgayTrong_1Thang();
	unsigned int ketqua = 0;
	for (int i = 0; i < QuanLiNgayThangNhapKhoHangHoa.size(); i++) {
		ketqua += QuanLiTienBanDuocTrongTungNgay[i];
		QuanLiTienBanDuocTrongTungThang.push_back(ketqua);
	}

}

void QuanLiNhapKho::KhoiTaoSoLanXuatHienCuaCacNgayTrong_1Thang() {
	//KhoiTaoTongSoTienBanDuocTrong_1_Ngay();
	int dem = 1;
	for (int i = 1; i < QuanLiNgayThangNhapKhoHangHoa.size(); i++) {
		if (QuanLiNgayThangNhapKhoHangHoa[i].getterThang() == QuanLiNgayThangNhapKhoHangHoa[i - 1].getterThang() && QuanLiNgayThangNhapKhoHangHoa[i].getterNam() == QuanLiNgayThangNhapKhoHangHoa[i - 1].getterNam()) {
			++dem;
		}

		else {
			QuanLiSoNgayBanDuocTrongMotThang.push_back(dem);
			dem = 1;
		}
	}
	QuanLiSoNgayBanDuocTrongMotThang.push_back(dem);

	for (int i = 0; i < QuanLiSoNgayBanDuocTrongMotThang.size(); i++) {
		cout << "\n  " << QuanLiSoNgayBanDuocTrongMotThang[i] << " ";
	}

}


void QuanLiNhapKho::xuattest() {

	cout << daBan[0];
}