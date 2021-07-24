#pragma once
#include <iostream>
#include <string>
#include "date.h"
#include <iomanip>
using namespace std;

class NhanVien
{
protected:
	string hoTen;
	Date *ngaySinh;
	long luong;
public:
	int check;
	NhanVien();
	NhanVien(string, Date*);
	~NhanVien();
	long getLuong();

	virtual void Input();
	virtual void Output();
};

