// L_R Values.cpp : Defines the entry point for the console application.
//
// L values can have their addresses taken, R values cannot

#include "stdafx.h"
#include <iostream>
#include <vector>

class Test {
private:
	static const int SIZE = 100;
	int *buf{nullptr};
public:
	Test() {
		buf = new int[SIZE] {};
	}

	Test(int i) {
		buf = new int[SIZE] {};
		for (int i = 0; i < SIZE; i++) {
			buf[i] = 7 * i;
		}
	}

	Test(const Test &t) {
		buf = new int[SIZE] {};
		memcpy(buf, t.buf, SIZE * sizeof(int));
	}

	Test& operator=(const Test &rhs) {
		buf = new int[SIZE] {};
		memcpy(buf, rhs.buf, SIZE * sizeof(int));
		return *this;
	}

	~Test() {
		delete[] buf;
	}

	/*void bar(Test &other) {

	}*/

	///////////////////////
	// Move constructor
	//////////////////////
	// Takes an rvalue, and we want to steal resources from it
	Test(Test &&other) {
		std::cout << "move ctor\n";
		buf = other.buf;
		other.buf = nullptr; // so deleteing other's buf doesn't kill the memory
	}
	///////////////////////////
	// Move assignmentoperator
	//////////////////////////
	Test& operator=(Test &&rhs) {
		std::cout << "move assignment operator\n";
		delete[] buf; // 'this' already has memory allocated, get rid of it
		buf = rhs.buf;
		rhs.buf = nullptr;

		return *this;
	}
	

};

std::ostream &operator<<(std::ostream &out, const Test &test) {
	out << "Hello from test";
	return out;
}

// Functions return r-values
Test getTest() {
	return Test();
}

int foo() { return 3; }
//int& bar() { return 3; } // must return an l-value

void check(const Test &value) {
	std::cout << "lvalue function\n";
}
void check(const Test &&value) {
	std::cout << "rvalue function\n";
}


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

	//test1.bar(Test(1)); // This doesn't work on an online compiler, can't convert Test to Test&


	///////////////////////
	// r-value reference
	//////////////////////
	//Test &&rtest1 = test1; // This line doesn't compile, putting l-value into r-value reference
	Test &&rTest = getTest();
	int &&refInt = foo();

	check(getTest());
	check(rTest);
	check(refInt);

	///////////////////////
	// Move constructor
	//////////////////////
	// Takes an rvalue and moves it into a permananent object, takes the rvalue by an rvalue reference
	std::vector<Test> vec;
	vec.push_back(Test());

	///////////////////////
	// Move assignment
	//////////////////////
	Test test;
	test = getTest();


    return 0;
}

