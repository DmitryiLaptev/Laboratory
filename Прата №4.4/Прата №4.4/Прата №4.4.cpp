#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "Enter your first name: ";
	string OneName;
	getline(cin, OneName);
	cout << "Enter your last name: ";
	string TwoName;
	getline(cin, TwoName);
	string Itog = OneName + ", " + TwoName;
	cout << "Here's the information in a single string: " << Itog << endl;
	return 0;
}