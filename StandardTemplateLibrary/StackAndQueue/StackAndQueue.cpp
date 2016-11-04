// StackAndQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
#include <queue>

class Test {
public:
	Test(std::string name) : name(name) {
	}

	void Print() {
		std::cout << "Name is " << name << '\n';
	}

	~Test() {
		//std::cout << "Destroyed test with name " << name << '\n';
	}
private:
	std::string name;
};

// pop doesn't return, just removes top/front
int main()
{
	// *----------- Stack
	// Can't iterate through stack/queue
	std::stack<Test> testStack;

	// Push destroys object
	testStack.push(Test("Queen"));
	testStack.push(Test("King"));
	testStack.push(Test("Ace"));

	Test &test1 = testStack.top(); // Avoid copying here
	test1.Print();
	testStack.pop();

	// However after popping the refence I have in test1 is invalid, so grab a copy if I need it after popping
	
	Test &test2 = testStack.top(); // Avoid copying here
	test2.Print();
	testStack.pop();

	// *----------- Queue
	// Can't iterate through stack/queue
	std::queue<Test> testQueue;

	// Push destroys object
	testQueue.push(Test("Queen"));
	testQueue.push(Test("King"));
	testQueue.push(Test("Ace"));

	Test &test3 = testQueue.front(); // Avoid copying here
	test3.Print();
	testQueue.pop();

	// However after popping the refence I have in test1 is invalid, so grab a copy if I need it after popping

	Test &test4 = testQueue.front(); // Avoid copying here
	test4.Print();
	testQueue.pop();

    return 0;
}

