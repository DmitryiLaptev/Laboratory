#include "pch.h"
#include <iostream>
using namespace std;




int main()
{
	setlocale(0, "rus");
	cout << "Введите кол-во пройденных миль(киллометров):";
	double S;
	cin >> S;
	cout << "Введите кол-во потраченных галонов(литров):";
	int oil;
	cin >> oil;
	double a = S / oil;
	double b = oil / S;
	cout << "За один галлон вы прошли" << " " << a << " " << "миль" << endl;
	cout << "На один киллометр вы потратили" << " " << b << " " << "литров" << endl;
	system("pause");
	return 0;
}