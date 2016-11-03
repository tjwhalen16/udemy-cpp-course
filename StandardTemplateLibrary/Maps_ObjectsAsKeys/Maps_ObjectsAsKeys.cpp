// Maps_ObjectsAsKeys.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
#include <iostream>
#include <string>


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
	std::map<Person, int> people;

	people[Person("Tyler", 22)] = 0;
	people.insert(std::pair<Person, int>(Person("Mike", 27), 1));
	people.insert(std::make_pair(Person("Chad", 15), 2));

	// iterate
	for (std::map<Person, int>::iterator it = people.begin(); it != people.end(); it++) {
		it->first.print();
		std::cout << " --- their id is " << it->second << '\n';
	}

	return 0;
}

