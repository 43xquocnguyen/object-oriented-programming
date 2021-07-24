#include "bai_1_point.cpp"
#include <cmath>

class TriAngle
{
private:
	Point *point;
public:
	TriAngle();
	~TriAngle();

	void Input();
	void Output();

	void Trans(float, float);
	void Retale(float);
	void Zoom(float);

	Point Point_Center();
	void Paint();
};

TriAngle::TriAngle() {
	point = new Point[3];
}
TriAngle::~TriAngle() {
	delete[] point;
}

void TriAngle::Input() {
	bool check = false;
	do
	{
		cout << "NHAP DIEM A\n";
		this->point[0].Input();
		cout << "NHAP DIEM B\n";
		this->point[1].Input();
		cout << "NHAP DIEM C\n";
		this->point[2].Input();

		float AB = point[0].CalcLenght(point[1]);
		float BC = point[1].CalcLenght(point[2]);
		float CA = point[2].CalcLenght(point[0]);

		if (AB + BC <= CA || BC + CA <= AB || AB + CA <= BC) {
			check = true;
			cout << "TAM GIAC KHONG TON TAI\n";
		}
	} while (check);
}
void TriAngle::Output() {
	for (int i = 0; i < 3; i++)
	{
		cout << (char)(65 + i);
		point[i].Output();
		cout << "\t";
	}
}
void TriAngle::Trans(float a, float b) {
	for (int i = 0; i < 3; i++) {
		point[i].Trans(a, b);
	}
}
void TriAngle::Retale(float rad) {
	point[0].Retale(rad);
	point[1].Retale(rad);
	point[2].Retale(rad);
}
void TriAngle::Zoom(float l) {
	point[0].SetterX(point[0].GetterX() * l);
	point[0].SetterY(point[0].GetterY() * l);

	point[1].SetterX(point[1].GetterX() * l);
	point[2].SetterY(point[1].GetterY() * l);

	point[2].SetterX(point[2].GetterX() * l);
	point[2].SetterY(point[2].GetterY() * l);
}
Point TriAngle::Point_Center() {
	return Point((point[0].GetterX() + point[1].GetterX() + point[2].GetterX()) / 3
		, (point[0].GetterY() + point[1].GetterY() + point[2].GetterY()) / 3);
}
