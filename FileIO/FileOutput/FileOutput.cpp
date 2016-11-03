// FileOutput.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ofstream out; // Alternative> std::fstream out;
	std::string filename = "test.txt";
	out.open(filename); // Alternative> out.open(filename, ios::out);

	if (out.is_open())
	{
		out << "Writing to first line of the file" << std::endl;
		out << "Writing to the 2nd line";

		out.close();
	}
	else
	{
		std::cout << "Could not create file: " << filename  << std::endl;
	}

    return 0;
}

