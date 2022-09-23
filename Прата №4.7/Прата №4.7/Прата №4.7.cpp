#include "pch.h"
#include <iostream>

#include <string>

using namespace std;


struct pizza {

	string comp;

	int d;

	float w;

};


int main() {

	pizza pizza;


	cout << "Enter company name: ";

	getline(cin, pizza.comp);

	cout << "Enter diameter: ";

	cin >> pizza.d;

	cout << "Enter weight: ";

	cin >> pizza.w;


	cout << pizza.comp << "  " << pizza.d << "  " << pizza.w << endl;

	system("pause");

	return 0;

}