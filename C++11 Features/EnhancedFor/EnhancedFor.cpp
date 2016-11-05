// EnhancedFor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

int main()
{
	auto texts = { "one", "two", "three" };

	for (auto text : texts) {
		std::cout << text << '\n';
	}

	for (auto c : "Hello") {
		std::cout << c << '\n';
	}

    return 0;
}

