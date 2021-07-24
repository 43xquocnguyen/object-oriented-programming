#include "sheep.h"

Sheep::Sheep() : Animal() {
	this->tick = 3; 
	this->SinhCon();
	this->ChoSua();
}
Sheep::~Sheep() {

}
void Sheep::ChoSua() {
	this->soLitSua = rand() % 21 + (float)rand() / (float)RAND_MAX;
	this->soLitSua = roundf(this->soLitSua * 100) / 100;
}
void Sheep::PhatTiengKeu() {
	cout << "Sheep are talk ... \n";
}