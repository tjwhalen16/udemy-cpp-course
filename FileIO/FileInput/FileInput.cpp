// FileInput.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::string filename = "test.txt";
	std::fstream in;

	in.open(filename);
	if (in.is_open())
	{
		while (in)
		{
			std::string line;
			std::getline(in, line);
			std::cout << "filestream operator one time results in reading: " << line << std::endl;
		}
		in.close();
	}
	else
	{
		std::cout << "Failed to open file: " << filename << std::endl;
	}


    return 0;
}

