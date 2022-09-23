#include "pch.h"
#include <iostream>
using namespace std;




int main()
{
	setlocale(0, "rus");
	long sec;
	cout << "Enter the number of seconds:";
	cin >> sec;
	int day = sec / 86400;
	sec = sec - day * 86400;
	int hours = sec / 3600;
	sec = sec - hours * 3600;
	int min = sec / 60;
	sec = sec - min * 60;
	cout << day << " " << "days" << "," << hours << " " << "hours" << "," << min << " " << "minutes" << "," << sec << " " << "seconds" << endl;

	system("pause");
	return 0;
}