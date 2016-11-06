// LambdaExpressions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

class Test {
private:
	int one{ 1 };
	int two{ 2 };

public:
	void run() {
		int three{ 3 };
		int four{ 4 };

		// Can't capture one, two, but can capture this
		// captureing this always captures by reference
		auto lambda = [this, three, four]() {
			std::cout << "Member variables: " << one << ", " << two << '\n';
			std::cout << "Local variables: " << three << ", " << four << '\n';
		};
		lambda();
	}
};

void test(void (*func)()) {
	func();
}

void Greet(void(*func)(std::string)) {
	func("Tyler");
}

int main()
{
	[]() { std::cout << "This is a lambda\n"; }();
	auto func = []() { std::cout << "This is a lambda\n"; };
	func();

	test(func);

	test([]() { 
		std::cout << "This is a lambda\n"; 
	});

	auto greet = [](std::string name) { std::cout << "Hello " << name << '\n'; };
	Greet(greet);

	///////////////////////
	/// Parameters/Return
	///////////////////////

	auto divide = [](double a, double b) -> double { // Must specify a return type when it is ambiguous
		if (b == 0.0) {
			return 0;
		}
		return a / b;
	};

	std::cout << "10 / 5 = " << divide(10, 5) << '\n';
	std::cout << "10 / 3 = " << divide(10, 3) << '\n';
	std::cout << "10 / 0 = " << divide(10, 5) << '\n';

	//////////////////////////
	/// Capture expressions
	//////////////////////////
	int one = 1; 
	int two = 2;
	int three = 3;

	// Captures one,two by value
	[one, two]() {std::cout << one << ", " << two << '\n'; }();

	// Captures all local variables by value
	[=]() {std::cout << one << ", " << two << ", " << three << '\n'; }();
	// Captures all local variables by reference
	[&]() {std::cout << one << ", " << two << ", " << three << '\n'; }();

	// Captures all local variables by value, but capture 3 by reference
	[=, &three]() {std::cout << one << ", " << two << ", " << three << '\n'; three = -3; }();
	std::cout << "three was changed to negative: " << three << '\n';

	// Captures all local variables by reference, but capture 3 by value
	[&, three]() {std::cout << one << ", " << two << ", " << three << '\n'; }();

	//////////////////////////
	/// mutable keyword
	//////////////////////////

	// Allows changing the copy of the captured variable like you'd expect in a regular function
	[one]() mutable {
		one = -1;
		std::cout << "one was changed to negative using mutable keyword: " << one << '\n';
	}();
	std::cout << "one was not changed to -1 outside of the lambda function: " << one << '\n';

	//////////////////////////
	/// Capturing this
	//////////////////////////
	Test test;
	test.run();

    return 0;
}

