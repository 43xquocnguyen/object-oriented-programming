#include "bai_1_point.cpp"

class Polygon
{
private:
	Point* point;
	int n;
public:
	Polygon();
	~Polygon();

	void Input();
	void Output();

	void Trans(float, float);
	void Relate(float);
	void Zoom(float);

	Point Center_Point();
};

Polygon::Polygon() {
	do
	{
		cout << "NHAP SO DIEM CUA DA GIAC: ";
		cin >> this->n;
		if (this->n <= 0) {
			cout << "SO LUONG DIEM CUA DA GIAC KHONG HOP LE\n";
		}
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX);
			this->n = -1;
		}
	} while (this->n <= 0);

	point = new Point[n];
}
Polygon::~Polygon() {
	delete[] point;
}
void Polygon::Input() {
	for (int i = 0; i < this->n; i++)
	{
		cout << "NHAP DIEM " << (char)(65 + i) << endl;
		point[i].Input();
	}
}
void Polygon::Output() {
	for (int i = 0; i < n; i++)
	{
		cout << (char)(65 + i);
		point[i].Input();
		if (i < this->n - 1)
		{
			cout << " - ";
		}
	}
}
void Polygon::Trans(float a, float b) {
	for (int i = 0; i < this->n; i++)
	{
		point[i].Trans(a, b);
	}
}
void Polygon::Relate(float rad) {
	for (int i = 0; i < this->n; i++)
	{
		point[i].Retale(rad);
	}
}
void Polygon::Zoom(float l) {
	for (int i = 0; i < this->n; i++)
	{
		point[i].SetterX(point[i].GetterX() * l);
		point[i].SetterY(point[i].GetterY() * l);
	}
}
Point Polygon::Center_Point() {
	float x = 0, y = 0;
	for (int i = 0; i < this->n; i++)
	{
		x += this->point[i].GetterX();
		y += this->point[i].GetterY();
	}
	return Point(x / this->n, y / this->n);
}