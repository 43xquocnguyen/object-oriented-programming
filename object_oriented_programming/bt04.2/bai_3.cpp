#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Time
{
private:
	int day, month, year;
	bool LeapYear() {
		if (year % 400 == 0)
			return true;
		if (year % 4 == 0 && year % 100 != 0)
			return true;
		return false;
	}
public:
    Time();
    ~Time();
    void Nhap();
	void Xuat();
};


Time::Time()
{
    this->day = 0;
    this->month = 0;
    this->year = 0;
}
Time::~Time()
{
}
void Time::Nhap() {
	do { // year 
		cout << "Nhap nam: ";
		cin >> this->year;

		if (this->year <= 1970 || this->year >= 2022) {
			cout << "Vui long nhap nam hop le\n";
		}

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			this->year = -1;
		}
	} while (this->year <= 1970 || this->year >= 2022);

	do { // month
		cout << "Nhap thang: ";
		cin >> this->month;

		if (this->month <= 0 || this->month > 12) {
			cout << "Vui long nhap thang hop le\n";
		}

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			this->month = -1;
		}
	} while (this->month <= 0 || this->month > 12);

	switch (month) {
	case 1:case 3:case 5: case 7: case 8: case 10:case 12: {
		do {
			cout << "Nhap ngay: ";
			cin >> this->day;

			if (this->day <= 0 || this->day >= 32) {
				cout << "Ngay khong hop le\n";
			}
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				this->day = -1;
			}

		} while (this->day <= 0 || this->day >= 32);
		break;
	}
	case 4:case 6:case 9: case 11: {
		do {
			cout << "Nhap ngay: ";
			cin >> this->day;

			if (this->day <= 0 || this->day >= 31) {
				cout << "Ngay khong hop le\n";
			}
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				this->day = -1;
			}

		} while (this->day <= 0 || this->day >= 31);
		break;
	}
	case 2: {
		if (this->LeapYear()) {
			do {
				cout << "Nhap ngay: ";
				cin >> this->day;

				if (this->day <= 0 || this->day >= 30) {
					cout << "Ngay khong hop le\n";
				}
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					this->day = -1;
				}

			} while (this->day <= 0 || this->day >= 30);
		}
		else {
			do {
				cout << "Nhap ngay: ";
				cin >> this->day;

				if (this->day <= 0 || this->day >= 29) {
					cout << "Ngay khong hop le\n";
				}
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					this->day = -1;
				}

			} while (this->day <= 0 || this->day >= 29);
		}
		break;
	}
	}
}
void Time::Xuat() {
    cout << setw(15) << left << this->day;
    cout << setw(15) << left << this->month;
    cout << setw(15) << left << this->year;
}

class Candidate
{
private:
    string maSo;
    string hoTen;
    Time *ngayThangNamSinh;
    float diemToan, diemVan, diemAnh;
public:
    Candidate();
    ~Candidate();

    void Nhap();
    void Xuat();
    float TinhDiemTrungBinh();
};
Candidate::Candidate()
{
    this->maSo = "";
    this->hoTen = "";
    this->ngayThangNamSinh = NULL;
    this->diemToan = 0;
    this->diemAnh = 0;
    this->diemVan = 0;
}
Candidate::~Candidate()
{
    delete ngayThangNamSinh;
}
void Candidate::Nhap() {
    do
    {
        cout << "NHAP MA SO SINH VIEN: ";
        getline(cin, this->maSo);
        if (this->maSo.length() < 1) {
            cout << "MA SO KHONG HOP LE\n";
        }
    } while (this->maSo.length() < 1);
    
    do
    {
        cout << "NHAP HO TEN SINH VIEN: ";
        getline(cin, this->hoTen);
        if (this->hoTen.length() < 1) {
            cout << "HO VA TEN KHONG HOP LE\n";
        }
    } while (this->hoTen.length() < 1);

    this->ngayThangNamSinh = new Time;
    this->ngayThangNamSinh->Nhap();

    do
    {
        cout << "NHAP DIEM TOAN: ";
        cin >> this->diemToan;
        if (this->diemToan < 0 || this->diemToan > 10) {
            cout << "DIEM TOAN KHONG HOP LE, THU LAI\n";
        }
        if (cin.fail()) {
            cin.clear();
            cin.ignore('\n', 32767);
            this->diemToan = -1;
        }
    } while (this->diemToan < 0 || this->diemToan > 10);

    do
    {
        cout << "NHAP DIEM VAN: ";
        cin >> this->diemVan;
        if (this->diemVan < 0 || this->diemVan > 10) {
            cout << "DIEM VAN KHONG HOP LE, THU LAI\n";
        }
        if (cin.fail()) {
            cin.clear();
            cin.ignore('\n', 32767);
            this->diemVan = -1;
        }
    } while (this->diemVan < 0 || this->diemVan > 10);
    
    do
    {
        cout << "NHAP DIEM ANH: ";
        cin >> this->diemAnh;
        if (this->diemAnh < 0 || this->diemAnh > 10) {
            cout << "DIEM ANH KHONG HOP LE, THU LAI\n";
        }
        if (cin.fail()) {
            cin.clear();
            cin.ignore('\n', 32767);
            this->diemAnh = -1;
        }
    } while (this->diemAnh < 0 || this->diemAnh > 10);
}
void Candidate::Xuat() {
    cout << setw(20) << left << this->maSo;
    cout << setw(25) << left << this->hoTen;
    this->ngayThangNamSinh->Xuat();
    cout << setw(15) << left << this->diemToan;
    cout << setw(15) << left << this->diemVan;
    cout << setw(15) << left << this->diemAnh;
}
float Candidate::TinhDiemTrungBinh() {
    return (this->diemAnh + this->diemToan + this->diemVan);
}

void NhapDanhSach(Candidate *&list_cadidate, int &n) {
    do
    {
        cout << "NHAP SO LUONG SINH VIEN: ";
        cin >> n;
        if (n < 0) {
            cout << "SO LUONG SINH VIEN KHONG HOP LE\n";
        }
    } while (n < 0);

    cin.ignore();

    list_cadidate = new Candidate[n];

    for (int i = 0; i < n; i++)
    {
        system("cls");
        cout << "NHAP THONG TIN THI SINH THU " << i + 1 << endl;
        list_cadidate[i].Nhap();
        cin.ignore();
    }
}
bool CoThiSinhTren15(Candidate *list, int n) {
    for (int i = 0; i < n; i++) {
        if (list[i].TinhDiemTrungBinh() > 15) {
            return true;
        }
    }
    return false;
}
void XuatDanhSachTren15(Candidate *list_cadidate, int n) {
    if (!CoThiSinhTren15(list_cadidate, n)) {
        system("cls");
        cout << "KHONG CO THI SINH NAO CO TONG DIEM TREN 15\n";
        return;
    }
    cout << setfill(' ');
    cout << setw(8) << left << "STT";
    cout << setw(20) << left << "MA SO";
    cout << setw(25) << left << "HO TEN";
    cout << setw(15) << left << "NGAY SINH";
    cout << setw(15) << left << "THANG SINH";
    cout << setw(15) << left << "NAM SINH";
    cout << setw(15) << left << "DIEM TOAN";
    cout << setw(15) << left << "DIEM VAN";
    cout << setw(15) << left << "DIEM ANH" << endl;
    cout << setfill('-');
    cout << setw(150) << "-" << endl;
    int j = 1;
    for (int i = 0; i < n; i++)
    {
        if (list_cadidate[i].TinhDiemTrungBinh() > 15)
        {
            cout << setfill(' ');
            cout << setw(8) << left << j++;
            list_cadidate[i].Xuat();
            cout << endl;
        }
    }
}

int main() {
    system("cls");
    Candidate *list_cadidate;
    int n = 0;
    NhapDanhSach(list_cadidate, n);
    XuatDanhSachTren15(list_cadidate, n);
    system("pause");
    delete list_cadidate;
    return 0;
}