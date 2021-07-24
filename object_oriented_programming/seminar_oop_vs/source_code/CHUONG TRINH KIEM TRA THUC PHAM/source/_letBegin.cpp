#pragma comment(lib, "winmm.lib")
#include "_letBegin.h"
#include<windows.h>
#include <iostream>

using namespace std;

_letBegin::_letBegin() {

}

_letBegin::~_letBegin() {

}

void _letBegin::beging() {
	ChuTheoTiengNoi x;
	int i = 50;
	x.ChayChu(i);
	PlaySound(TEXT("LoiNoiDau.wav"), NULL, SND_SYNC);
}