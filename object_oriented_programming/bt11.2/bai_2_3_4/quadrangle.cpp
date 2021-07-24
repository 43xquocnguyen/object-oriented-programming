#include "quadrangle.h"

Quadrangle::Quadrangle() {
	this->n = this->v;
	this->point = new Point[this->n];
	this->tick = 2;
}
Quadrangle::~Quadrangle() {

}
void Quadrangle::Input() {
	Polygon::Input();
}
bool Quadrangle::Check() {
	return Polygon::Check();
}