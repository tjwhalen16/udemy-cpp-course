// StandardExceptions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class AllocatedTooMuchMemory
{
public:
	AllocatedTooMuchMemory()
	{
		char *pMem = new char[999999999999];
		delete[] pMem;
	}
};

int main()
{
	try
	{
		AllocatedTooMuchMemory too_much;
	}
	catch (int e)
	{

	}
		


    return 0;
}

 