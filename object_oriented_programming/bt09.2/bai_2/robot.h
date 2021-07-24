#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib> 
#include <iomanip>
#include <string>
using namespace std;

class Robot
{
protected:
	int *M;
	int *K;
	string type;
public:
	Robot();
	virtual ~Robot();

	virtual float EnergyConsum(float) = 0;
	virtual void Output(float S) {
		cout << setw(12) << left << this->type;
		cout << setw(17) << left << *this->M;
		cout << setw(17) << left << *this->K;
		cout << setw(17) << left << "0";
		cout << setw(17) << left << "0";
		cout << setw(20) << left << this->EnergyConsum(S);
	}
};

