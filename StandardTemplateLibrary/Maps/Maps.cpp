// Maps.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>

bool MapContainsKey(const std::map<std::string, int> &ages, const std::string &key);

int main()
{
	std::map<std::string, int> ages; // maps are ordered by key
	ages["Tyler"] = 22;
	ages["Rob"] = 32;
	ages.insert(std::pair<std::string, int>("Mike", 38));
	ages.insert(std::make_pair("Bobby", 41));
	
	// checking key in map?
	if (MapContainsKey(ages, "Vicky")) {
		std::cout << "error\n";
	}
	if (!MapContainsKey(ages, "Tyler")) {
		std::cout << "error\n";
	}

	// iterate
	for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
		std::cout << "key: " << it->first << ", value: " << it->second << '\n';
	}

    return 0;
}

bool MapContainsKey(const std::map<std::string, int> &ages, const std::string &key) {
	if (ages.find(key) != ages.end()) {
		return true;
	} else {
		return false;
	}
}
