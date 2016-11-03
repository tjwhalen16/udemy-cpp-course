// Lists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>

bool InsertNumbers(std::list<int> &nums, int after, int to_insert);
bool DeleteNumbers(std::list<int> &nums, int toDelete);
void PrintListStartingAtIt(const std::list<int> &nums, std::list<int>::iterator it);

int main()
{
	// The C++ STL list is a doubley linked list
	std::list<int> numbers;

	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_front(0);

	std::cout << "List by default\n";
	for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		std::cout << *it << std::endl;
	}

	std::cout << "List after inserting 2 after 2\n";
	InsertNumbers(numbers, 2, 2);
	for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		std::cout << *it << std::endl;
	}

	std::cout << "List after deleting all 2s\n";
	DeleteNumbers(numbers, 2);
	for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		std::cout << *it << std::endl;
	}

    return 0;
}

bool InsertNumbers(std::list<int> &nums, int after, int to_insert) {
	bool did_insert = false;

	for (std::list<int>::iterator it = nums.begin(); it != nums.end(); it++) {
		if (after == *it) {
			nums.insert(it, to_insert);
			did_insert = true;
		}
	}
	return did_insert;
}

bool DeleteNumbers(std::list<int> &nums, int to_delete) {
	bool did_delete = false;
	std::list<int>::iterator it = nums.begin();
	while (it != nums.end()) {
		if (to_delete == *it) {
			it = nums.erase(it);
			did_delete = true;
		}
		else {
			it++; // only increment if I didn't delete anything
		}		
	}
	return did_delete;
}

void PrintListStartingAtIt(const std::list<int> &nums, std::list<int>::iterator it) {
	std::cout << "print list from it\n";
	for (it; it != nums.end(); it++) {
		std::cout << *it << ",";
	}
	std::cout << "\nlist printed\n";
}
