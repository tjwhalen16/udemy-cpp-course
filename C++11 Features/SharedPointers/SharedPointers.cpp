// SharedPointers.cpp : Defines the entry point for the console application.
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

int main()
{
	std::shared_ptr<Test> p_test2(nullptr);

	{
		std::shared_ptr<Test> p_test = std::make_shared<Test>();
		p_test2 = p_test;
	} // Not destroyed here because p_test2 still holding the memory	

	std::cout << "Finished\n";
    return 0;
}

