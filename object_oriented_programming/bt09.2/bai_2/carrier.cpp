#include "carrier.h"

Carrier::Carrier() : Robot() {
	*this->M = 30;
	this->E = new float;
	*this->E = rand() % 51 + 50;
}
Carrier::~Carrier() {
	*this->M = 0;
	*this->E = 0;
	delete this->M;
	delete this->E;
}
float Carrier::EnergyConsum(float S) {
	return (*this->M * S + 4 * *this->E * S);
}
void Carrier::Output(float S) {
	cout << setw(12) << left << "Carrier";
	cout << setw(17) << left << *this->M;
	cout << setw(17) << left << "0";
	cout << setw(17) << left << "0";
	cout << setw(17) << left << *this->E;
	cout << setw(20) << left << this->EnergyConsum(S);
}