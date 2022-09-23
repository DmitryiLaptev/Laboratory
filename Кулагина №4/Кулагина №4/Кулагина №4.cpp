#include "pch.h"
#include <iostream>
#include <cmath>

using namespace std;

double func(const double &x)
{
	return x * exp(x);
}

double metod_lefttriangle(const double &n, const double &a, const double &b)
{
	double sum = 0;
	double step = (b - a) / n;
	for (double i = a; i < b - step; i = i + step) {
		sum += func(i);
	}
	return sum * step;
}

double metod_righttriangle(const double &n, const double &a, const double &b)
{
	double sum = 0;
	double step = (b - a) / n;
	for (double i = a + step; i <= b; i = i + step) {
		sum += func(i);
	}
	return sum * step;
}

double metod_centralrectangle(const double &n, const double &a, const double &b)
{
	double sum = 0;
	double step = (b - a) / n;
	for (double i = a; i <= b - step; i = i + step) {
		sum += func(i + step / 2);
	}
	return sum * step;
}

double metod_trapecii(const double &n, const double &a, const double &b)
{
	double step = (b - a) / n;
	double sum = (func(b) + func(a)) / 2;
	for (double i = a + step; i < b - step; i = i + step) {
		sum += func(i);
	}
	return sum * step;
}

double metod_parabol(const double &n, const double &a, const double &b)
{
	double step = (b - a) / n;
	double nechet = 0;
	double chet = 0;
	double sum = func(a) + func(b);

	for (double i = a + step; i < b; i = i + step * 2) {
		nechet += func(i);
	}
	for (double i = a + 2 * step; i < b - step; i = i + step * 2) {
		chet += func(i);
	}
	return (sum + 4 * nechet + 2 * chet) * (step / 3);
}


int main()
{
	double a = -1, b = 1;
	double n = 20;
	cout << "Metod lefttriangle = " << metod_lefttriangle(n, a, b) << endl;
	cout << "Metod righttriangle = " << metod_righttriangle(n, a, b) << endl;
	cout << "Metod centralrectangle = " << metod_centralrectangle(n, a, b) << endl;
	cout << "Metod trapecii = " << metod_trapecii(n, a, b) << endl;
	cout << "Metod parabol = " << metod_parabol(n, a, b) << endl;
	return 0;
}
