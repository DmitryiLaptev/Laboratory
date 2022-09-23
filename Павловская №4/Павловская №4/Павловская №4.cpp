#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int i, j, h, k, n1, n2;
	const int m1 = 2, m2 = 2;
	double p, X0, Y0, R, Xa, Xb, Xc, Ya, Yb, Yc;
	int kol1 = 0, kol2 = 0;
	cout << " Enter the number of points of the first set :";
	cin >> n1;
	int **mas1 = new int *[m1];
	for (int i = 0; i < m1; i++)
		mas1[i] = new int[n1];
	cout << "Enter (x) points, and then her (y):";
	for (j = 0; j < n1; j++) {
		for (i = 0; i < m1; i++) {
			cin >> p;
			mas1[i][j] = p;
		}
	}
	cout << " Enter the number of points of the second set :";
	cin >> n2;
	int **mas2 = new int *[m2];
	for (int i = 0; i < m2; i++)
		mas2[i] = new int[n2];
	cout << "Enter (x) points, and then her (y):";
	for (j = 0; j < n2; j++) {
		for (i = 0; i < m2; i++) {
			cin >> p;
			mas2[i][j] = p;
		}
	}
	for (i = 0; i < (n1 - 2); i++) {
		for (j = (i + 1); j < (n1 - 1); j++) {
			for (h = (j + 1); h < n1; h++) {
				Xa = mas1[0][i];
				Xb = mas1[0][j];
				Xc = mas1[0][h];
				Ya = mas1[1][i];
				Yb = mas1[1][j];
				Yc = mas1[1][h];
				X0 = (Ya*(Xb*Xb + Yb * Yb - Xc * Xc - Yc * Yc) + Yb * (Xc*Xc + Yc * Yc - Xa * Xa - Ya * Ya) + Yc * (Xa*Xa + Ya * Ya - Xb * Xb - Yb * Yb)) / ((-2)*(Xa*(Yb - Yc) + Xb * (Yc - Ya) + Xc * (Ya - Yb)));
				Y0 = (Xa*(Xb*Xb + Yb * Yb - Xc * Xc - Yc * Yc) + Xb * (Xc*Xc + Yc * Yc - Xa * Xa - Ya * Ya) + Xc * (Xa*Xa + Ya * Ya - Xb * Xb - Yb * Yb)) / (2 * (Xa*(Yb - Yc) + Xb * (Yc - Ya) + Xc * (Ya - Yb)));
				R = sqrt((Xb - X0)*(Xb - X0) + (Yb - Y0)*(Yb - Y0));
				for (k = 0; k < n1; k++) {
					if ((k != i) && (k != j) && (k != h)) {
						double Xk = mas1[0][k];
						double Yk = mas1[1][k];
						if (sqrt((Xk - X0)*(Xk - X0) + (Yk - Y0)*(Yk - Y0)) < R) {
							kol1++;
						}
					}
				}
				for (k = 0; k < n2; k++) {
					double Xk = mas2[0][k];
					double Yk = mas2[1][k];
					if (sqrt((Xk - X0)*(Xk - X0) + (Yk - Y0)*(Yk - Y0)) < R) {
						kol2++;
					}
				}
				if (kol1 == kol2) {
					cout << "Center of the circle:{" << X0 << ";" << Y0 << "}" << endl << "Radius:" << R << endl;
				}
			}
		}
	}
	system("pause");
	return 0;
}