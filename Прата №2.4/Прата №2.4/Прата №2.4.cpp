#include "pch.h"
#include <iostream>
using namespace std;

double converting(double с)
{
	return (1.8 * с + 32);

}

int main()
{
	double с;
	cout << "Please enter a Celsius value : ";
	cin >> с;
	cout << с << " degrees Celsius is " << converting(с) << " degrees Fahrenheit." << endl;
}