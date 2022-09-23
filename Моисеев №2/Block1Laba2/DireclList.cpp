#include <iostream>  
#include "DirectList.h" 
#include <string>

using namespace std;

int main()
{
	List<string> list;

	string str = "Jon Snow";
	list.insert_first(new string(str));
	cout << "Element \"" << str << "\" Added to the top of the list" << endl;

	str = "Tyrion Lannister";
	list.insert_last(new string(str));
	cout << "Element \"" << str << "\" Added to the end of the list" << endl;

	str = "Petyr Baelish";
	list.insert_last(new string(str));
	cout << "Element \"" << str << "\" Added to the end of the list" << endl;

	str = "Theon Greyjoy";
	list.insert_first(new string(str));
	cout << "Element \"" << str << "\" Added to the end of the list" << endl;

	str = "Jaime Lannister";
	list.insert_first(new string(str));
	cout << "Element \"" << str << "\" Added to the top of the list" << endl;

	string* cStr = list.removal_back();
	cout << "pulled an element \"" << *cStr << "\" From the end of the list" << endl;
	delete cStr;
	cStr = list.removal_back();
	cout << "pulled an element \"" << *cStr << "\" From the end of the list" << endl;
	delete cStr;

	auto it = List<string>::Iterator(list.front());
	auto itForInsert = it;
	itForInsert++;
	str = "Sansa Stark";
	list.insert_after(itForInsert, &str);
	cout << "Element \"" << str << "\" Inserted after the iterator" << endl;
	cout << endl;
	cout << "The output of elements:" << endl;
	for (auto i = it; i.getPLI() != list.back()->cFollowing; i++)
	{
		cout << **i << endl;
	}
	cout << endl;
	auto itForremove_iterator = List<string>::Iterator(list.front());
	itForremove_iterator++;
	list.remove_iterator(itForremove_iterator);
	auto iter = List<string>::Iterator(list.front());
	cout << "Element \"" << str << "\" deleted by iterator" << endl;
	cout << endl;
	cout << "The output of elements after the method remove_iterator:" << endl;
	for (auto i = iter; i.getPLI() != list.back()->cFollowing; i++)
	{
		cout << **i << endl;
	}
}