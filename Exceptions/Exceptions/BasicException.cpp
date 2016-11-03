// cpp experiments.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

void changeByReference(int&);
int passSafetlyByRefernce(const int&); // No copying required
void willThrowIntException();
void willThrowStringException();

int main()
{
	int num = 6;

	std::cout << "Before function num is " << num << std::endl;
	changeByReference(num);
	std::cout << "After function num is " << num << std::endl;

	std::cout << "\nCan't change num if using const, but its fast because the variable isn't copied\n";
	std::cout << "Use it for large objects to save time from unnecessary copying\n";
	std::cout << "Num + 1 is " << passSafetlyByRefernce(num) << std::endl;

	try
	{
		willThrowIntException();
	}
	catch (int e)
	{
		std::cout << "Caught integer exception with code: " << e << std::endl;
	}

	try
	{
		willThrowStringException();
	}
	catch (std::string &e)
	{
		std::cout << "Caught string exception with code: " << e << std::endl;
	}

	return 0;
}

void changeByReference(int &num)
{
	num++; // Change the num that was passed in
}

int passSafetlyByRefernce(const int& num)
{
	return num + 1;
}

void willThrowIntException()
{
	throw 8;
}

void willThrowStringException()
{
	throw std::string("Better catch this by reference!");
}
