#include "pch.h"
#include <iostream>
using namespace std;

void func1(int nstr, int nstb, int **m) {
	int n, i = 0, j = 0; int k = 0; int sum = 0;

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
}

void func2(int nstr, int nstb, int **m) {
	int n, i = 0, j = 0; int min = 0; int max = 0;
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
}

int main() {
	int a, b, i = 0, j = 0, n;
	cout << " Enter the number of rows and columns :";
	cin >> a >> b;
	int **m = new int *[a];
	for (int i = 0; i < a; i++)
		m[i] = new int[b];
	cout << "Enter items:";
	for (i = 0; i < a; i++) {
		for (j = 0; j < b; j++) {
			cin >> n;
			m[i][j] = n;
		}
	}
	func1(a, b, m);
	func2(a, b, m);
	system("pause");
	return 0;
}