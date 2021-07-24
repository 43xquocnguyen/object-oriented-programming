#include "list_robot.h"

ListRobot::ListRobot() {
	this->S = 0;
	this->num = 0;
}
ListRobot::~ListRobot() {

}
void ListRobot::SetterS(float S) {
	if (S >= 0) {
		this->S = S;
	}
}
float ListRobot::GetterS() {
	return this->S;
}
unsigned int ListRobot::GetterNum() { return this->num; }
void ListRobot::Input() {
	int a, b, c;
	do
	{
		cout << "NHAP A SO LUONG PEDION: ";
		cin >> a;
		if (a < 0) cout << "SO LUONG ROBOT KHONG HOP LE\n";
	} while (a < 0);
	do
	{
		cout << "NHAP A SO LUONG ZATTACKER: ";
		cin >> b;
		if (b < 0) cout << "SO LUONG ROBOT KHONG HOP LE\n";
	} while (b < 0);
	do
	{
		cout << "NHAP A SO LUONG CARRIER: ";
		cin >> c;
		if (c < 0) cout << "SO LUONG ROBOT KHONG HOP LE\n";
	} while (c < 0);

	
	for (int i = 0; i < a; i++)
	{
		Robot* t = new Pedion;
		this->list.push_back(t);
		this->num++;
	}
	for (int i = 0; i < b; i++)
	{
		Robot* t = new Zattacker;
		this->list.push_back(t);
		this->num++;
	}
	for (int i = 0; i < c; i++)
	{
		Robot* t = new Carrier;
		this->list.push_back(t);
		this->num++;
	}
}
void ListRobot::Output() {
	cout << setw(5) << left << "STT";
	cout << setw(12) << left << "LOAI";
	cout << setw(17) << left << "KHOI LUONG (M)";
	cout << setw(17) << left << "LINH HOAT (F)";
	cout << setw(17) << left << "SUC MANH (P)";
	cout << setw(17) << left << "NANG LUONG (E)";
	cout << setw(20) << left << "TONG TIEU THU ($)" << endl;
	cout << setfill('-') << setw(100) << "-" << endl;
	cout << setfill(' ');

	int size = list.size();
	for (int i = 0; i < size; i++)
	{
		cout << setw(5) << left << i + 1;
		list[i]->Output(this->S);
		cout << endl;
	}
}
Robot* ListRobot::TheMostEnergy() {
	float max = INT_MIN;
	int index;
	int size = this->list.size();

	for (int i = 0; i < size; i++)
	{
		if (this->list[i]->EnergyConsum(this->S) > max) {
			max = this->list[i]->EnergyConsum(this->S);
			index = i;
		}
	}
	return this->list[index];
}
float ListRobot::SumEnergy() {
	float sum = 0;
	int size = this->list.size();
	for (int i = 0; i < size; i++)
	{
		sum += this->list[i]->EnergyConsum(this->S);
	}
	return sum;
}