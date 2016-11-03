// Vectors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
	std::vector<std::string> strings; // strings(5);

	strings.push_back("1");
	strings.push_back("2");
	strings.push_back("3");

	std::cout << "size: " << strings.size() << std::endl;

	// Looping vectors
	std::cout << "Use loop\n";
	for (int i = 0; i < strings.size(); i++) {
		std::cout << strings[i] << std::endl;
	}

	std::cout << "Use Iterator\n";
	for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++) {
		std::cout << *it << std::endl;
	}
	

    return 0;
}

