// InitializerList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <initializer_list>
#include <iostream>
#include <string>

class Test {
public:
	Test() = default; // Add back the default constructor
	Test(const Test &) = delete; // Remove the copy constructor
	Test &operator=(const Test &rhs) = delete; // Can delete default operators

	Test(std::initializer_list<std::string> texts) {
		for (auto text : texts) {
			std::cout << text << '\n';
		}
	}

	void print(std::initializer_list<std::string> texts) {
		for (auto text : texts) {
			std::cout << text << '\n';
		}
	}
};

int main()
{
	Test test{ "liver", "rib", "heart" };
	test.print({ "1", "2", "3", "4" });
    return 0;
}

