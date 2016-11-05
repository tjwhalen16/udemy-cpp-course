// FunctionPointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <array>
#include <string>

bool Match(std::string str) {
	return str.size() == 3;
}

int NumMatches(const std::array<std::string, 4> &strings, bool(*func)(std::string)) {
	int num_matches = 0;
	for (std::string string : strings) {
		if (func(string)) {
			num_matches++;
		}
	}
	return num_matches;
}

int main()
{
	std::array<std::string, 4> strings{ "yes", "no", "son", "cart" };
	std::cout << std::count_if(strings.begin(), strings.end(), Match) << '\n';
	std::cout << NumMatches(strings, Match) << '\n';

    return 0;
}

