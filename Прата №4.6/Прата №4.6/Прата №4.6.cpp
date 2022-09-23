#include "pch.h"
#include <iostream>
using namespace std;
struct CandyBar
{
	char Name[20];
	double netto;
	int ccal;
};
int main()
{
	CandyBar snack[3] = {
	{"Mocha Mach",7.4,345},
	{"Grand",2.43,435},
	{"Love", 3.15 , 656} };

	for (int i = 0; i < 3; i++) {
		cout << snack[i].Name << ", " << snack[i].netto << ", " << snack[i].ccal << endl;
	}
	return 0;
}