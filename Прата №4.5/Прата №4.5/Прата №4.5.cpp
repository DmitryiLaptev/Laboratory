#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

struct candyBar
{
	string name;
	double weight;
	int kcal;
};

int main()
{
	candyBar snack
	{
	"Mocha Munch",
	2.3,
	350
	};

	cout << "The name of these chocolates: " << snack.name << endl;
	cout << "The weight of these chocolates: " << snack.weight << endl;
	cout << "The kcal of these chocolates: " << snack.kcal << endl;
	return 0;
}