// CustomExceptions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//#include <string>

class MyException : public std::exception
{
public:
	virtual  const char* what() const throw()
	{
		return "Something bad happened!";
	}
};

class ThrowsException
{
public:
	void static Throws()
	{
		throw MyException();
	}
};

int main()
{
	try
	{
		ThrowsException::Throws();
	}
	catch (std::exception &e) // If you don't catch by reference it won't print the message defined on line 13
	{
		std::cout << "Error message was " << e.what() << std::endl;
	}

    return 0;
}

