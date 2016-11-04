// StdSorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Test {
public:
	Test() : name("") {

	}
	Test(std::string name) : name(name) {
	}

	void Print() {
		std::cout << "Name is " << name << '\n';
	}
	
	friend bool compare(const Test &a, const Test &b);
private:
	std::string name;
};

bool compare(const Test &a, const Test &b);

int main()
{
	std::vector<Test> tests;
	tests.push_back(Test("Diane"));
	tests.push_back(Test("Anne"));
	tests.push_back(Test("Charlie"));
	tests.push_back(Test("Bill"));

	// Either overload < in class or supply comparator if I can't overload <
	std::sort(tests.begin(), tests.end(), compare);

	for (Test test : tests) {
		test.Print();
	}

    return 0;
}

bool compare(const Test &a, const Test &b) {
	return a.name < b.name;
}

