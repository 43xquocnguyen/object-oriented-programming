#include "zattacker.h"

Zattacker::Zattacker() : Robot() {
	*this->M = 50;
	this->P = new float;
	*this->P = rand() % 11 + 20;
}
Zattacker::~Zattacker() {
	*this->M = 0;
	*this->P = 0;
	delete this->M;
	delete this->P;
}
float Zattacker::EnergyConsum(float S) {
	return (*this->M * S + *this->P * *this->P * S);
}
void Zattacker::Output(float S) {
	cout << setw(12) << left << "Zattacker";
	cout << setw(17) << left << *this->M;
	cout << setw(17) << left << "0";
	cout << setw(17) << left << *this->P;
	cout << setw(17) << left << "0";
	cout << setw(20) << left << this->EnergyConsum(S);
}