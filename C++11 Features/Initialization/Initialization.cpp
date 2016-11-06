// Initialization.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

// Braces can be used anywhere
int main()
{
	int value{ 7 };
	std::cout << value << '\n';

	int value1{}; // Default value
	std::cout << value1 << '\n';

	std::string str{ "Hello" };
	std::cout << str << '\n';

	int nums[]{ 1,2,3,4,5 };
	for (int num : nums) {
		std::cout << num << '\n';
	}

	int *p_nums = new int[3]{ 1,2,3 };
	std::cout << p_nums[1] << '\n';
	delete[] p_nums;

	int *p_int{ &value };
	std::cout << *p_int << '\n';

	int *p_null{ nullptr };
	std::cout << p_null << '\n';

	int numbers[5]{ 2 }; // Only initialized first element to 2
	for (int num : numbers) {
		std::cout << num << '\n';
	}

	struct { // Struct init doesn't need = anymore
		int value;
		std::string text;
	} s{ 5, "Hi" }, s2{ 6, "Bye" };

	std::cout << s.text << ", " << s2.text << '\n';

	// No push_back !
	std::vector<std::string> strings{ "one", "two", "three" };
	for (auto string : strings) {
		std::cout << string << '\n';
	}

    return 0;
}

