// StandardFunctionType.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool pred(std::string &test) {
	return test.size() == 3;
}

class Functor {
public:
	bool operator()(std::string &test) { // Can't pass string literal when accepting string by reference
		return test.size() == 3;
	}
};

// Here is how to tell a function to accept any callable as an argument
void run(std::function<bool(std::string&)> test) {
	std::string three_letter_string = "dog";
	
	if (test(three_letter_string)) {
		std::cout << "Success\n";
	}
}

int main()
{	
	// So many ways to pass a function...

	// Lambda way
	int size = 3;
	std::vector<std::string> vec{ "one", "two", "three" };
	std::cout << std::count_if(vec.begin(), vec.end(), [size](std::string &test) { return test.size() == size; }) << '\n';

	// Function pointer way
	std::cout << std::count_if(vec.begin(), vec.end(), pred) << '\n';

	// Functor way
	Functor functor;
	std::cout << std::count_if(vec.begin(), vec.end(), functor) << '\n';

	run([size](std::string &test) { return test.size() == size; });
	run(pred);
	run(functor);

    return 0;
}

