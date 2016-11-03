// MultiMap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>

int main()
{
	std::multimap<int, std::string> lookup;
	lookup.insert(std::make_pair(30, "thirty"));
	lookup.insert(std::make_pair(10, "ten"));
	lookup.insert(std::make_pair(30, "thirty_2"));
	lookup.insert(std::make_pair(30, "thirty_3"));
	lookup.insert(std::make_pair(20, "twenty"));
	lookup.insert(std::make_pair(10, "ten_2"));

	auto its = lookup.equal_range(30); // auto === std::pair<std::multimap<int, std::string>::iterator, std::multimap<int, std::string>::iterator>

	for (auto it = its.first; it != its.second; it++) { // auto === std::multimap<int, std::string>::iterator
		std::cout << "key: " << it->first << ", value: " << it->second << '\n';
	}

    return 0;
}

