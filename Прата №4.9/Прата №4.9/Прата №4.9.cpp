#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
struct CandyBar
{
	string name;
	double netto;
	int ccal;
};
int main()
{
	CandyBar *bar = new CandyBar[3];
	bar[0].name = "Mocha Much";
	bar[0].netto = 2.3;
	bar[0].ccal = 350;
	bar[1].name = "Grand";
	bar[1].netto = 2.45;
	bar[1].ccal = 325;
	bar[2].name = "Love";
	bar[2].netto = 2.12;
	bar[2].ccal = 656;

	for (int i = 0; i < 3; i++) {
		cout << bar[i].name << ", " << bar[i].netto << ", " << bar[i].ccal << endl;
	}

	delete[] bar;
	system("pause");
	return 0;
}