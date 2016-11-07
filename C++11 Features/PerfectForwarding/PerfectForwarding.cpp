// PerfectForwarding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Test {

};

template<typename T>
void Call(T &&t) {
	check(t);
}

void check(const Test &value) {
	std::cout << "lvalue\n";
}
void check(const Test &&value) {
	std::cout << "rvalue\n";
}

int main()
{
	Test test; // lvalue

	//auto &&t = Test(); // This compiles.. makes sense, putting rvalue into rvalue reference
	auto &&t = test; // This compiles too... lvalue into rvalue reference ???... reference collapsing rules

	Call(Test()); // NOT perfect forwarding, should print rvalue, but Test() loses it "rvalue-ness" as it moves across the stack
	//When T is a rvalue reference, some stuff with reference collapsing happens that messes things up

	// change line 13 -> check(static_cast<T>(arg));
	// or check(forward<T>(arg)); 
	// to preserve r/l value-ness

    return 0;
}

