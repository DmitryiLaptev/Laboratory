#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	double a, b, c, Xn, Xk, dX, F; double x = 0;
	cout << "Enter a:";
	cin >> a;
	cout << "Enter b:";
	cin >> b;
	cout << "Enter c:";
	cin >> c;
	cout << "Enter Xn:";
	cin >> Xn;
	cout << "Enter Xk:";
	cin >> Xk;
	cout << "Enter dX:";
	cin >> dX;
	int ac = a; int bc = b; int cc = c;
	cout << "X" << "|" << "F" << endl;
	for (x = Xn; x <= Xk; x += dX)
	{
		if ((c < 0) && (b != 0))F = a * x*x + b * b*x;
		else if ((c > 0) && (b == 0))F = (x + a) / (x + c);
		else F = x / c;
		if ((ac&bc) | (ac&cc) != 0)
			cout << x << "|" << F << endl;
		else cout << x << "|" << int(F) << endl;
	}
	system("pause");
	return 0;
}
