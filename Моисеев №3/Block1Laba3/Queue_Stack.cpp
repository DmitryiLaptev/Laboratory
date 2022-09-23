#include <iostream>  
#include "Stack.h"  
#include "Queue.h"
#include <string>

using namespace std;

int main()
{
	Queue<string> queue;
	string str = "Crime and Punishment, Book 1";
	queue.push_back(new string(str));
	cout << "element \"" << str << "\" added to the queue" << endl;
	str = "The Idiot, Book 2";
	queue.push_back(new string(str));
	cout << "element \"" << str << "\" added to the queue" << endl;
	str = "Demons, Book 3";
	queue.push_back(new string(str));
	cout << "element \"" << str << "\" added to the queue" << endl;
	str = "Poor Folk, Book 4";
	queue.push_back(new string(str));
	cout << "element \"" << str << "\" added to the queue" << endl;
	str = "The Brothers Karamazov, Book 5";
	queue.push_back(new string(str));
	cout << "element \"" << str << "\" added to the queue" << endl;
	queue.pop_front();
	cout << "Removed an element from the queue" << endl;
	queue.pop_front();
	cout << "Removed an element from the queue" << endl;
	queue.pop_front();
	cout << "Removed an element from the queue" << endl;
	cout << endl;
	auto itQ = Queue<string>::Iterator(queue.front());
	cout << "Output of queue elements: " << endl;
	for (auto i = itQ; i.getPLI() != queue.back()->cfoll; i++) {
		cout << **i << endl;
	}

	cout << endl;

	Stack<string> stack;
	str = "Statue of Zeus at Olympia, Wonders World 1";
	stack.push(new string(str));
	cout << "element \"" << str << "\" added to the stack" << endl;
	str = "Mausoleum at Halicarnassus, Wonders World 2";
	stack.push(new string(str));
	cout << "element \"" << str << "\" added to the stack" << endl;
	str = "Lighthouse of Alexandria, Wonders World 3";
	stack.push(new string(str));
	cout << "element \"" << str << "\" added to the stack" << endl;
	str = "Hanging Gardens of Babylon, Wonders World 4";
	stack.push(new string(str));
	cout << "element \"" << str << "\" added to the stack" << endl;
	str = "Colossus of Rhodes, Wonders World 5";
	stack.push(new string(str));
	cout << "element \"" << str << "\" added to the stack" << endl;
	str = "Great Pyramid of Giza, Wonders World 6";
	stack.push(new string(str));
	cout << "element \"" << str << "\" added to the stack" << endl;
	str = "Temple of Artemis, Wonders World 7";
	stack.push(new string(str));
	cout << "element \"" << str << "\" added to the stack" << endl;
	stack.pop();
	cout << "Removed an element from the stack" << endl;
	stack.pop();
	cout << "Removed an element from the stack" << endl;
	stack.pop();
	cout << "Removed an element from the stack" << endl;
	cout << endl;
	auto itS = Stack<string>::Iterator(stack.front());
	cout << "Output of stack elements: " << endl;
	for (auto i = itS; i.getPLI() != stack.back()->cfoll; i++) {
		cout << **i << endl;
	}
}