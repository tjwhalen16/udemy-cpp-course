// SublcassExceptions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

// std::exception
// is parent of 
// std::bad_alloc

void GoesWrong()
{
	bool error_1 = true;
	bool error_2 = false;

	if (error_1)
	{
		throw std::bad_alloc();
	}
	if (error_2)
	{
		throw std::exception();
	}
}

int main()
{
	try
	{
		GoesWrong();
	}
	catch (std::bad_alloc &e) // Catch children first, because bad_alloc "is a" exception
	{
		std::cout << "Catching bad_alloc " << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Catching exception " << e.what() << std::endl;
	}
    return 0;

	
}

