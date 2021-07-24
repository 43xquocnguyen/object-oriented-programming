#include "cow.h"

Cow::Cow() : Animal() {
	this->tick = 1;
	this->SinhCon();
	this->ChoSua();
}
Cow::~Cow() {

}
void Cow::ChoSua() {
	this->soLitSua = rand() % 6 + (float)rand() / (float)RAND_MAX; // random sua~
	this->soLitSua = roundf(this->soLitSua * 100) / 100; // lam tron` lay' 2 phan` thap. phan^
}
void Cow::PhatTiengKeu() {
	cout << "Cow are talk ... \n";
}