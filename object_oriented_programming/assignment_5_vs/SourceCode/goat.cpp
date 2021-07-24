#include "goat.h"

Goat::Goat() : Animal() {
	this->tick = 2;
	this->SinhCon();
	this->ChoSua();
}
Goat::~Goat() {

}
void Goat::ChoSua() {
	this->soLitSua = rand() % 11 + (float)rand() / (float)RAND_MAX;
	this->soLitSua = roundf(this->soLitSua * 100) / 100;
}
void Goat::PhatTiengKeu() {
	cout << "Goat are talk ... \n";
}