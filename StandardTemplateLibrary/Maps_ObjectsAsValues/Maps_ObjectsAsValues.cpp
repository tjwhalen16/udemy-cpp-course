// Maps_ObjectsAsValues.cpp : Defines the entry point for the console application.
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
		std::cout << "copy constructor running\n";
	}

	void print() const {
		std::cout << name << ", " << age << '\n';
	}
private:
	std::string name;
	int age;

};


int main()
{
	std::map<int, Person> people;

	people[0] = Person("Tyler", 22);
	people.insert(std::pair<int, Person>(1, Person("Mike", 27)));
	people.insert(std::make_pair(2, Person("Chad", 15)));

	// iterate
	for (std::map<int, Person>::iterator it = people.begin(); it != people.end(); it++) {
		it->second.print();
	}

    return 0;
}

