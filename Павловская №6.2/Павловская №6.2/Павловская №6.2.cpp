#include "pch.h"
#include <iostream>
using namespace std;

struct WORKER {
	char surname[255];
	char name[255];
	char position[255];
	int yearAdm;
};

void task(WORKER *Wk, int n) {

	for (int i = 0; i < n; i++) {
		cout << "Enter surname:";
		cin >> Wk[i].surname;
		cout << "Enter name:";
		cin >> Wk[i].name;
		cout << "Enter position:";
		cin >> Wk[i].position;
		cout << "Enter year:";
		cin >> Wk[i].yearAdm;
	}
	WORKER s;
	for (int t = 0; t < n; t++)
		for (int i = 0; i < n; i++)
			if (Wk[i].surname[0] > Wk[t].surname[0])
			{
				s = Wk[i];
				Wk[i] = Wk[t];
				Wk[t] = s;
			}
	for (int i = 0; i < n; i++) {
		cout << Wk[i].surname << " " << Wk[i].name << " ,his position:" << Wk[i].position << " ,admission year:" << Wk[i].yearAdm << endl;
	}
	int year;
	cout << "Enter required experience:";
	cin >> year;
	int m = 0;
	for (int i = 0; i < n; i++) {
		if ((2018 - Wk[i].yearAdm) > year) {
			cout << Wk[i].surname << " " << Wk[i].name << " ,his position:" << Wk[i].position << " ,admission year:" << Wk[i].yearAdm << endl;
			m = 1;
		}
	}
	if (m == 0) {
		cout << "Does not exist" << endl;
	}
}

int main() {
	int n;
	cout << "Enter of number workers:" << endl;
	cin >> n;
	WORKER *Wk = new WORKER[n];
	task(Wk, n);
	system("pause");
	return 0;
}