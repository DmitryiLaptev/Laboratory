#include "pch.h"
#include <iostream>
#include <windows.h>
using namespace std;

double convert(double lu)
{
	return lu * 63240;
}

int main()
{
	double au, ly;
	cout << "Enter the number of light years: ";
	cin >> ly;
	au = convert(ly);
	cout << ly << " " << "light years = " << " " << au << " " << "astonomical units" << endl;
	system("pause");
	return 0;
}