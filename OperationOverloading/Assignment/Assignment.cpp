// Assignment.cpp : Defines the entry point for the console application.
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

	Test(int id, std::string name): id(id), name(name) {
	}

	Test(const Test &other) {
		std::cout << "Copy constructor\n";
		*this = other;
	}

	void Print() {
		std::cout << id << " : " << name << '\n';
	}

	Test &operator=(const Test &other) {
		std::cout << "= operator\n";
		id = other.id;
		name = other.name;
		return *this;
	}
};

int main()
{
	Test t1(0, "Tyler");
	t1.Print();
	Test t2(1, "Jane");
	
	//t2 = t1;
	//t2.Print();

	Test t3;
	//Test t3 = t1;
	//t3.Print();

	(t1 = t3) = t2;
	t1.Print();

    return 0;
}

