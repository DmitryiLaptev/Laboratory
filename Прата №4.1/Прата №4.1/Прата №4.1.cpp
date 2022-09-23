#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "What is your first name?";
	string OneName;
	getline(cin, OneName);
	cout << "What is your last name?";
	string TwoName;
	getline(cin, TwoName);
	cout << "What letter grade do you deserve?";
	char a;
	cin >> a;
	a = ++a;
	cout << "What is your age?";
	int Age;
	cin >> Age;
	cout << "Name:" << TwoName << "," << OneName << endl;
	cout << "Grade:" << a << endl;
	cout << "Age:" << Age;
	return 0;
}