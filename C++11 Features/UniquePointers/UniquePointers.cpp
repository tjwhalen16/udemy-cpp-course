// UniquePointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>

class Test {
public:
	Test() {
		std::cout << "created\n";
	}

	~Test() {
		std::cout << "destroyed\n";
	}

	void Greet() {
		std::cout << "Hello!\n";
	}
};

class HasATest {
public:
	HasATest() : p_test(new Test[2]), raw(new Test) {

	}


private:
	std::unique_ptr<Test[]> p_test; // Don't need to write my own destructor when pointer is not raw
	Test *raw; // This doesn't get destroyed when object leaves scope
};

int main()
{
	std::unique_ptr<int> p_int(new int);
	*p_int = 7;
	std::cout << *p_int << '\n';

	{
		//std::unique_ptr<Test[]> p_test(new Test[2]); // This does get destroyed
		//p_test[1].Greet();
		HasATest has_a_test; // The test inside this object does get destroyed

		Test *raw_test = new Test; // This doesn't get destroyed
		
	} // It gets destroyed once it leaves scope
	

	std::cout << "Finished\n";
    return 0;
}

