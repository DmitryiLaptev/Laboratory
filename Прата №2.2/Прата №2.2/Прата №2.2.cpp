#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int farlong;
	cout << "Enter the distance in the furlongs:";
	cin >> farlong;
	int yard = farlong * 220;
	cout << "Distance in yards:" << yard << endl;
	system("pause");
	return 0;
}