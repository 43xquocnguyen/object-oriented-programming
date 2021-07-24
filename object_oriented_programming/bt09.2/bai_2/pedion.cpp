#include "pedion.h"

Pedion::Pedion() : Robot() {
	*this->M = 20;
	this->F = new float;
	*this->F = rand() % 5 + 1;
}
Pedion::~Pedion() {
	*this->M = 0;
	*this->F = 0;
	delete this->M;
	delete this->F;
}
float Pedion::EnergyConsum(float S) {
	return (*this->M * S + (*this->F + 1) * S / 2);
}
void Pedion::Output(float S) {
	cout << setw(12) << left << "Pedion";
	cout << setw(17) << left << *this->M;
	cout << setw(17) << left << *this->F;
	cout << setw(17) << left << "0";
	cout << setw(17) << left << "0";
	cout << setw(20) << left << this->EnergyConsum(S);
}