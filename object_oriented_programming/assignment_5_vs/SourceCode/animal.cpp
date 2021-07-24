#include "animal.h"

Animal::Animal() {
	this->soCon = this->soLitSua = 0;
	this->tick = 0;
}
Animal::~Animal() {

}
void Animal::SinhCon() {
	this->soCon = rand() % 6;
}