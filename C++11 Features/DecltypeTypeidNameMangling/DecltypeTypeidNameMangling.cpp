// DecltypeTypeidNameMangling.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <typeinfo>
#include <string>
int main()
{
	std::string type;

	std::cout << typeid(type).name() << '\n';

	decltype(type) name = "Tyler";
	std::cout << "Name: " << name << '\n';
    return 0;
}

