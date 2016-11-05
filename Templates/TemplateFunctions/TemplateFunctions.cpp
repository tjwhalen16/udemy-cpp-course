// TemplateFunctions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

template<typename T> // class === typename
void Print(T t) {
	std::cout << t << '\n';
}

int main()
{
	Print(1);
	Print<int>(1);
	Print("one");

	Print(2.1);
	Print<int>(2.1);

    return 0;
}

