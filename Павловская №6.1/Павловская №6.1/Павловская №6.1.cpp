#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int nstr, nstb, n, a, b, i = 0, j = 0; int k = 0; int sum = 0; int min = 0; int max = 0;
	cout << " Enter the number of rows and columns :";
	cin >> nstr >> nstb;
	int **m = new int *[nstr];
	for (int i = 0; i < nstr; i++)
		m[i] = new int[nstb];
	cout << "Enter items:";
	for (i = 0; i < nstr; i++) {
		for (j = 0; j < nstb; j++) {
			cin >> n;
			m[i][j] = n;
		}
	}
	for (i = 0; i < nstr; i++) {
		for (j = 0; j < nstb; j++) {
			if (m[i][j] < 0) {
				for (k = 0; k < nstb; k++) {
					sum += m[i][k];
				}
				break;
			}
		}
	}
	cout << "Sum of elements in rows with negative elements:" << sum << endl;

	int *c = new int[nstb];
	int *d = new int[nstr];
	for (i = 0; i < nstr; i++) {
		for (j = 0; j < nstb; j++) {
			min = m[i][0];
			if (m[i][j] < min)min = m[i][j];
		}
		c[i] = min;
	}
	for (j = 0; j < nstb; j++) {
		max = m[0][j];
		for (i = 0; i < nstr; i++) {
			if (m[i][j] > max) {
				max = m[i][j];
			}
		}
		d[j] = max;
	}
	for (i = 0; i < nstr; i++) {
		for (j = 0; j < nstb; j++) {
			if ((m[i][j] == c[i]) && (m[i][j] == d[j])) {
				cout << "Saddle point:" << m[i][j] << " ";
				cout << "Coordinate:" << i << ";" << j << endl;
			}
		}
	}
	system("pause");
	return 0;
}