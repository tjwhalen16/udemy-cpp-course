// LeftBitShift.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

class Test {
	int id;
	std::string name;

public:
	Test() : id(0), name("") {
	}

	Test(int id, std::string name) : id(id), name(name) {
	}

	Test(const Test &other) {
		*this = other;
	}

	void Print() {
		std::cout << id << " : " << name << '\n';
	}

	Test &operator=(const Test &other) {
		id = other.id;
		name = other.name;
		return *this;
	}

	friend std::ostream &operator<<(std::ostream &out, const Test &test) {
		out << test.id << " : " << test.name;
		return out;
	}
};

int main()
{
	Test t1(0, "Tyler");
	t1.Print();
	std::cout << t1 << '\n';

    return 0;
}

