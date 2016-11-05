// TemplateClasses.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

template<class T>
class Test {
public:
	Test(T t) : t(t) {
	}

	void Print() {
		std::cout << t << '\n';
	}

private:
	T t;
};

int main()
{
	Test<std::string> t1("Template string");
	t1.Print();
    return 0;
}

