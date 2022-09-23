#include "pch.h"
#include <iostream>
using namespace std;




int main()
{
	setlocale(0, "rus");
	double sec, min, degrees;
	const int n = 60; const int k = 3600;
	cout << "Enter a latitude in degress,minutes, and seconds:" << endl << "First,enter the degrees:";
	cin >> degrees;
	cout << "Next, enter the minutes of arc:";
	cin >> min;
	cout << "Finally, enter the seconds of arc:";
	cin >> sec;
	double degrees2 = degrees + min / n + sec / k;
	cout << degrees2;
	system("pause");
	return 0;
}