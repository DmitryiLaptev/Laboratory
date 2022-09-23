#include "pch.h"
#include <iostream>
using namespace std;




int main()
{
	setlocale(0, "rus");
	cout << "Введите рост в дюймах:";
	const int k = 12;
	int n;
	cin >> n;
	int l = n / k;
	int m = n - l * k;
	cout << l << " " << "Фут." << endl;
	cout << m << " " << "Дюйм." << endl;
	system("pause");
	return 0;
}