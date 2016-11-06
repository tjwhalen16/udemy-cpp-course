// L_R Values.cpp : Defines the entry point for the console application.
//
// L values can have their addresses taken, R values cannot

#include "stdafx.h"
#include <iostream>

class Test {
public:
	//int i{ 5 };

	Test() {

	}
	Test(int i) {}
	Test(const Test &t) {
	}

	Test& operator=(const Test &rhs) {
		return *this;
	}

	void bar(Test &other) {

	}
};

//std::ostream &operator<<(std::ostream &out, const Test &test) {
//	out << "Hello from test";
//	return out;
//}

// Functions return r-values
Test getTest() {
	return Test();
}

int foo() { return 3; }
//int& bar() { return 3; } // must return an l-value

int main()
{
	Test test1 = getTest();

	//std::cout << test1 << '\n';

	//Test &refTest1 = test1; // Can do this becuase test1 is an l-value
	Test *refTest2 = &getTest(); // This is not suppossed to work apparently, but it does in VS2015

	//int &ref = foo(); // Compile error, foo returns an int, a r-value
	const int &ref = foo(); // Make is const to make it work

	// Why do these work?
	// the = operator is a function, and I can call functions on r-values
	getTest() = test1;
	getTest().operator=(getTest());

	test1.bar(Test(1)); // This doesn't work on an online compiler, can't convert Test to Test&


	///////////////////////
	// r-value reference
	//////////////////////
	//Test &&rtest1 = test1; // This line doesn't compile, putting l-value into r-value reference
	Test &&rTest = getTest();
	int &&refInt = foo();

    return 0;
}

