#include "robot.h"

Robot::Robot() {
	this->M = new int;
}
Robot::~Robot() {
	*this->M = 0;
	delete this->M;
}