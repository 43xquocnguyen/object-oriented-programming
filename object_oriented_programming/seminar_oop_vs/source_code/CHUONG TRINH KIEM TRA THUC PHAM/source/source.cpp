#include "HangHoaThucPham.h"
#include "DieuKhienMenu.h"
#include "QuanLiNhapKho.h"
#include"_letBegin.h"

int main() {
	fullScreen(); // Chỉnh toàn bộ màn hình
	removeScrollBar(); // xóa thanh cuộn
	getWHConsole(); // lấy ra biến toàn cục của width và height của màn hình hiện tại
	
	hideCur(); // ẩn trỏ chuột
	_letBegin x;
	x.beging(); // Lời mở đầu...
	
	DieuKhienMenu *a = new DieuKhienMenu;
	a->KhoiTaoDocDuLieu();
	a->Chay();
	delete a;
	return 0;
}