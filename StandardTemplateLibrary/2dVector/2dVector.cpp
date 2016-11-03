// 2dVector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

void PrintGrid(const std::vector< std::vector<int> > &grid);

int main()
{
	// rows holding columns, initialized each row with a column of size 4, put 0 everywhere
	std::vector< std::vector<int> > grid(3, std::vector<int>(4, 0));

	PrintGrid(grid);
	std::cout << std::endl;

	// Ragged array, different sized rows
	grid[1].push_back(3);
	grid[1].push_back(3);
	PrintGrid(grid);
	std::cout << std::endl;

    return 0;
}

void PrintGrid(const std::vector< std::vector<int> > &grid) {
	for (int row = 0; row < grid.size(); row++) {
		for (int col = 0; col < grid[row].size(); col++) {
			std::cout << grid[row][col];
		}
		std::cout << std::endl;
	}
}
