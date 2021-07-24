#include "ThoiGianThuc.h"

ThoiGianThuc::ThoiGianThuc() {

}

ThoiGianThuc::~ThoiGianThuc() {

}

void ThoiGianThuc::KhoiTao() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	this->thoigianthuc.setterNam(1900 + ltm->tm_year);
	this->thoigianthuc.setterThang(1 + ltm->tm_mon);
	this->thoigianthuc.setterNgay(ltm->tm_mday);

}
/*
void ThoiGianThuc::Xuat() {
	thoigianthuc.XuatNgay();

}*/

Date ThoiGianThuc::getterThoiGianThuc() {
	return this->thoigianthuc;
}