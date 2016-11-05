// Functors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Test {
public:
	virtual bool operator()(std::string&) = 0;
};

class MatchingTest: public Test { // Functor, overriding function operator
public:
	bool operator()(std::string &text) {
		return "lion" == text;
	}
};

void check(std::string text, Test &test) {
	if (test(text)) {
		std::cout << "Match\n";
	} else {
		std::cout << "No match\n";
	}
}

int main()
{
	MatchingTest pred;
	std::string value = "lion";
	check("lion", pred);

	if (pred(value)) {
		std::cout << "Success\n";
	}

    return 0;
}

