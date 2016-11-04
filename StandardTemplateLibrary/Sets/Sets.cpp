// Sets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <set>
#include <string>
#include <sstream>

class Person {
public:
	Person() : name(""), age(0) {}
	Person(std::string name, int age) : name(name), age(age) {}
	// copy constructor
	Person(const Person &other) : name(other.name), age(other.age) {
	}

	void print() const {
		std::cout << name << ", " << age;
	}

	// operator override, like a compareTo
	bool operator<(const Person &other) const {
		if (name == other.name) {
			return age < other.age;
		}
		return name < other.name;
	}
private:
	std::string name;
	int age;

};

int main()
{
	std::set<int> numbers;

	numbers.insert(4);
	numbers.insert(2);
	numbers.insert(3);
	numbers.insert(1);

	for (auto it = numbers.begin(); it != numbers.end(); it++) {
		std::cout << *it << '\n';
	}

	// Finding
	std::set<int>::iterator itFind = numbers.find(2);
	if (itFind != numbers.end()) {
		std::cout << "Found: " << *itFind << '\n';
	}
	if (numbers.count(2)) {
		std::cout << "Found: 2\n";
	}


	std::set<Person> people;

	people.insert(Person("Tyler", 22));
	people.insert(Person("Taylor", 32));
	for (auto it = people.begin(); it != people.end(); it++) {
		it->print();
		std::cout << '\n';
	}

    return 0;
}

