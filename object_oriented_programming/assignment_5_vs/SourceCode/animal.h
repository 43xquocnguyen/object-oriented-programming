#pragma once
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <Windows.h>
#include <cmath>
#pragma comment (lib, "winmm.lib")
using namespace std;

class Animal
{
protected:
	int soCon;
	float soLitSua;
	int tick;
public:
	Animal();
	~Animal();

	int GsoCon() { return this->soCon; }
	float GsoLitSua() { return this->soLitSua; }
	int Gtick() { return this->tick; }

	virtual void SinhCon();
	virtual void ChoSua() = 0;
	virtual void PhatTiengKeu() = 0;
};

