#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
struct Pizza
{
	string name;
	double netto;
	int ccal;
};
int main()
{
	Pizza *piz = new Pizza;
	cout << "Enter diametr:";
	cin >> (*piz).netto;
	cout << "Enter Name:";
	cin >> (*piz).name;
	cout << "Enter ves:";
	cin >> (*piz).ccal;
	cout << "Pizza: " << (*piz).name << endl;
	cout << "Diametr: " << (*piz).netto << endl;
	cout << "Ves: " << (*piz).ccal << endl;
	system("pause");
	delete piz;
	return 0;
}