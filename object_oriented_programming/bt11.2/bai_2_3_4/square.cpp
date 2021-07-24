#include "square.h"

Square::Square() : Quadrangle() {
	this->tick = 3;
}
Square::~Square() {

}
void Square::Input() {
	do
	{
		Polygon::Input();
        if (!this->Check()) cout << "HINH VUONG KHONG TON TAI\n";
	} while (!this->Check());
}
bool Square::Check() {
    Point YAxis(0, 1);
    Point XAxis(1, 0);

    vector<float> Yvalue;
    vector<float> Xvalue;
    Xvalue.resize(0);
    Yvalue.resize(0);

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
                Xvalue.push_back(c[i].Module(c[j]));
            }
            else if ((c[i] - c[j]).MultiCoor(XAxis) == 0)
            {
                Yvalue.push_back(c[i].Module(c[j]));
            }
        }
    }
    if (Xvalue.size() == Yvalue.size() && Xvalue[0] == Yvalue[0])
    {
        return true;
    }
    else
    {
        return false;
    }
}