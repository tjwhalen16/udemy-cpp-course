// Parsing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream in;
	std::string filename = "stats.txt";
	in.open(filename);

	if (!in.is_open())
	{
		return 1;
	}
	std::string line;
	while (std::getline(in, line, ':'))
	{
		int population;
		in >> population;

		in >> std::ws; // Skip over to the next line through any whitespace

		std::cout << line << " -- Population is " << population << std::endl;
	}

	in.close(); // Always
    return 0;
}

