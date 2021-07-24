#pragma once
#include "nguoi.h"

class CaSi : public Nguoi
{
private:
	string dongNhac;
	int soShow, soAlbum;
public:
	CaSi();
	~CaSi();

	void Input();
	void Output();
};

