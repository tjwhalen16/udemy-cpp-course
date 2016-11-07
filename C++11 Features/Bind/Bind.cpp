// Bind.cpp : Defines the entry point for the console application.
//
// Make aliases to functions

#include "stdafx.h"
#include <iostream>
#include <functional>

class Test {
public:
	int add(int a, int b, int c) {
		std::cout << a << ", " << b << ", " << c << '\n';
		return a + b + c;
	}
};

int run(std::function<int(int, int)> func) {
	return func(1, 2);
}

int main()
{
	Test test;

	// Make a function variable that has set arguments, can swap args around
	auto calculate = std::bind(&Test::add, test, std::placeholders::_2, std::placeholders::_1, 3);

	std::cout << calculate(1, 2) << '\n';
	std::cout << run(calculate) << '\n';

    return 0;
}

