#include "pch.h"
#include <iostream>
#include <string>
int main()
{
	using namespace std;

	cout << "Enter your name:\n";
	string Name;
	getline(cin, Name);

	cout << "Enter your favorite dessert:\n";
	string Dessert;
	getline(cin, Dessert);

	cout << "I have some delicious " << Dessert;
	cout << " for you, " << Name << ".\n";
	return 0;
}