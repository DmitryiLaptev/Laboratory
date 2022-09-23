#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	int n, konets, temp; int i = 0; int nachalo = -1; int sum = 0; int j = 0;
	cout << "Enter the number of items:";
	cin >> n;
	double *m = new double[n];
	cout << "Enter the elements of the array:" << endl;
	for (i = 0; i < n; i++) {
		cin >> m[i];
	}
	int min = m[0];
	for (i = 0; i < n; i++) {
		if (m[i] > 0) {
			if (nachalo == -1) {
				nachalo = i;
			}
			konets = i;
		}
	}
	for (i = nachalo + 1; i < konets; i++)sum += m[i];
	for (i = 0; i < n; i++) {
		if (m[i] < min)min = m[i];
	}
	for (i = 0; i < n; i++)
		if (m[i] == 0)
		{
			temp = m[j]; m[j++] = m[i]; m[i] = temp;
		}
	cout << "Minimum value:" << min << endl;
	cout << "Sum of elements:" << sum << endl;
	cout << "The resulting array:";
	for (i = 0; i < n; i++)cout << m[i] << " ";
	system("pause");
	return 0;
}
