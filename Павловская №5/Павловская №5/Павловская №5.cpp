#include "pch.h"
#include <iostream>
using namespace std;

struct WORKER {
	char surname[255];
	char name[255];
	char position[255];
	int yearAdm;
};

void task() {
	WORKER structs[10];
	for (int i = 0; i < 10; i++) {
		cout << "Enter surname:";
		cin >> structs[i].surname;
		cout << "Enter name:";
		cin >> structs[i].name;
		cout << "Enter position:";
		cin >> structs[i].position;
		cout << "Enter year:";
		cin >> structs[i].yearAdm;
	}
	WORKER s;
	for (int t = 0; t < 10; t++)
		for (int i = 0; i < 10; i++)
			if (structs[i].surname[0] > structs[t].surname[0])
			{
				s = structs[i];
				structs[i] = structs[t];
				structs[t] = s;
			}
	for (int i = 0; i < 10; i++) {
		cout << structs[i].surname << " " << structs[i].name << " ,his position:" << structs[i].position << " ,admission year:" << structs[i].yearAdm << endl;
	}
	int year;
	cout << "Enter required experience:";
	cin >> year;
	int m = 0;
	for (int i = 0; i < 10; i++) {
		if ((2018 - structs[i].yearAdm) > year) {
			cout << structs[i].surname << " " << structs[i].name << " ,his position:" << structs[i].position << " ,admission year:" << structs[i].yearAdm << endl;
			m = 1;
		}
	}
	if (m == 0) {
		cout << "Does not exist" << endl;
	}
}

int main() {
	task();
	system("pause");
	return 0;
}
