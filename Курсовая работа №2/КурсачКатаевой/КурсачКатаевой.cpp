#include "pch.h"
#include <iostream>
#include <math.h>

using namespace std;
const int x = 3;
const int y = 4;
double matrica[x][y];
double mat[x][y];

void Gauss() {
	for (int i = 0; i < x; i++) {
		double z = matrica[i][i];
		for (int j = i; j < y; j++) {
			matrica[i][j] = matrica[i][j] / z;
		}
		for (int j = i + 1; j < x; j++) {
			double cof = matrica[j][i] * (-1);
			for (int z = i; z < y; z++) {
				matrica[j][z] = matrica[j][z] + cof * matrica[i][z];
			}
		}
	}
	for (int j = x - 2; j >= 0; j--) {
		for (int i = y - 2; i >= j + 1; i--) {
			matrica[j][y - 1] = matrica[j][y - 1] - matrica[i][y - 1] * matrica[j][i];
		}
	}
	cout << "Gauss metod:" << endl;
	for (int j = 0; j < x; j++) {
		cout << matrica[j][y - 1] << endl;
	}
}

void ProstayaIteraciya() {
	double a1, a2, a3, a4, b1, b2, b3, b4;
	double e = 0.0001;
	a1 = a2 = a3 = a4 = 1;
	b1 = b2 = b3 = b4 = 0;
	while (abs(b1 - a1) > e || abs(b2 - a2) > e || abs(b3 - a3) > e || abs(b4 - a4) > e) {
		a1 = b1; a2 = b2; a3 = b3; a4 = b4;
		b1 = (mat[0][4] - (mat[0][1] * a2 + mat[0][2] * a3 + mat[0][3] * a4)) / mat[0][0];
		b2 = (mat[1][4] - (mat[1][0] * a1 + mat[1][2] * a3 + mat[1][3] * a4)) / mat[1][1];
		b3 = (mat[2][4] - (mat[2][0] * a1 + mat[2][1] * a2 + mat[2][3] * a4)) / mat[2][2];
		b4 = (mat[3][4] - (mat[3][0] * a1 + mat[3][1] * a2 + mat[3][2] * a3)) / mat[3][3];
	}
	cout << "Prostaya Iteraciya metod:" << endl;
	cout << b1 << endl << b2 << endl << b3 << endl << b4 << endl;
}

void Zeydelya() {
	double a1, a2, a3, a4, b1, b2, b3, b4;
	double e = 0.0001;
	a1 = a2 = a3 = a4 = 1;
	b1 = b2 = b3 = b4 = 0;
	while (abs(b1 - a1) > e || abs(b2 - a2) > e || abs(b3 - a3) > e || abs(b4 - a4) > e) {
		a1 = b1; a2 = b2; a3 = b3; a4 = b4;
		b1 = (mat[0][4] - (mat[0][1] * a2 + mat[0][2] * a3 + mat[0][3] * a4)) / mat[0][0];
		b2 = (mat[1][4] - (mat[1][0] * b1 + mat[1][2] * a3 + mat[1][3] * a4)) / mat[1][1];
		b3 = (mat[2][4] - (mat[2][0] * b1 + mat[2][1] * b2 + mat[2][3] * a4)) / mat[2][2];
		b4 = (mat[3][4] - (mat[3][0] * b1 + mat[3][1] * b2 + mat[3][2] * b3)) / mat[3][3];
	}
	cout << "Zeydelya metod:" << endl;
	cout << b1 << endl << b2 << endl << b3 << endl << b4 << endl;
}

int main()
{
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> mat[i][j];
			matrica[i][j] = mat[i][j];
		}
	}
	Gauss();
	ProstayaIteraciya();
	Zeydelya();
	return 0;
}
