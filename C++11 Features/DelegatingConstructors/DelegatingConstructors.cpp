// DelegatingConstructors.cpp : Defines the entry point for the console application.
// 
// Can call constructos within constructors

#include "stdafx.h"
#include <iostream>

class Base {
	int num;
	std::string str;

public:
	// After commenting this out, and add string arguement to line 32, derived will not allow compilation
	Base() : Base("") { // Delegating this constructor to call a different constructor
		std::cout << "No parameter base constructor\n";
	}

	Base(std::string str) : num(6), str(str) {
		std::cout << "string parameter base constructor\n";
	}
};

class Derived : public Base {
public:
	Derived() : Base("") { // Need to tell derived to call the non default constructor for base to fix problem stated on line 13
	
	}
};

int main()
{
	Base base;
	Derived derived;	

    return 0;
}

