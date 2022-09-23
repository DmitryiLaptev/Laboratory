#include "pch.h"
#include <iostream>

#include <cstring>


int main() {

	char FirstName[1024];

	char LastName[1024];

	std::cout << "Enter your first name: ";

	std::cin >> FirstName;

	std::cout << "Enter your last name: ";

	std::cin >> LastName;

	char *itog = new char[strlen(FirstName) + 2 + strlen(LastName) + 1];

	itog[0] = 0;

	strcpy(itog, LastName);

	strcat(itog, ", ");

	strcat(itog, FirstName);

	std::cout << "Here's the information in a single string: " << itog << std::endl;

	delete[] itog;

	return 0;

}