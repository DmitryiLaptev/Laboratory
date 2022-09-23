#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	void time(int, int);
	int hourse;
	cout << "Enter the number of hours: ";
	cin >> hourse;
	int minute;
	cout << "Enter the number of minutes: ";
	cin >> minute;
	time(hourse, minute);
	return 0;
}
void time(int hourse, int minute)
{
	cout << "Time " << hourse << ":" << minute << endl;
}