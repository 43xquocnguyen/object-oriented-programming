#pragma once
#include <iomanip>
#include "Date.h"
#include <string>
#include "Graphics.h"
#include "Box.h"
using namespace std;


void KeBangXuat(); // bảng xuất sản phẩm
void InChuoiCoMau(float, int, int, string);
void KeKhungXuat(int size);
void VietBoxCoTieuDeCenTer(int, int, string);
void XoaBoxCoTieuDeCenTer(int, int);
void InSoTrang(int, int, int);

void BoxCoChuCenter(int, int, int, int, int, string);
void VeBoxInput();
void KeBangTinhTien(int);
void KeTongTien(unsigned int);
void KeBangXuatTienRong();
string DoiDateThanhString(Date);
string DoiDateThanhStringKhongCoNgay(Date);
