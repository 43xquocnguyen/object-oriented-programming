#include "pentagon.h"

Pentagon::Pentagon() {
	this->n = this->v;
	this->point = new Point[this->n];
	this->tick = 6;
}
Pentagon::~Pentagon() {

}