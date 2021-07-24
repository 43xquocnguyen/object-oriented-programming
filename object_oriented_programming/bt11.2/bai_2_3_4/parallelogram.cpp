#include "parallelogram.h"

Parallelogram::Parallelogram() : Quadrangle() {
	this->tick = 5;
}
Parallelogram::~Parallelogram() {

}
void Parallelogram::Input() {
	do
	{
		Polygon::Input();
	} while (!this->Check());
}
bool Parallelogram::Check() {
    Point YAxis(0, 1);

    vector<float> value;
    value.resize(0);

    Point* c = new Point[4];

    for (int i = 0; i < 4; i++)
    {
        c[i] = this->point[i];
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if ((c[i] - c[j]).MultiCoor(YAxis) == 0)
            {
                value.push_back(c[i].Module(c[j]));
            }
        }
    }
    if (value.size() == 2 && value[1] == value[0])
    {
        return true;
    }
    else
    {
        return false;
    }
}