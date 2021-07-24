#include "triangle.h"

TriAngle::TriAngle() {
	this->n = this->v;
	this->point = new Point[this->n];
	this->tick = 1;
}
TriAngle::~TriAngle() {

}
void TriAngle::Input() {
	do {
		for (int i = 0; i < this->n; i++)
		{
			cout << "NHAP DIEM " << (char)(65 + i) << endl;
			point[i].Input();
		}
		if (!this->Check())  cout << "TAM GIAC KHONG TON TAI\n";
	} while (!this->Check());
}
bool TriAngle::Check() {
	float AB = point[0].Module(point[1]);
	float BC = point[1].Module(point[2]);
	float CA = point[2].Module(point[0]);
	if (AB + BC <= CA || BC + CA <= AB || AB + CA <= BC) {
		return false;
	}
	return true;
}