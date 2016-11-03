// StructPadding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

// Person is padded, remove padding to write to file
#pragma pack(push, 1) // Align bytes by 1s, aka align by byte boundaries, aka no padding
struct Person
{
	char name[6]; // Can't be a std::string, string stores a pointer, will be useless when reading from different program
	int age;
	double weight;
};
#pragma pack(pop)

int main()
{
	Person *people = new Person[3];
	people[0] = { "Tyler", 22, 140.0 };
	people[1] = { "Sasha", 23, 240.0 };
	people[2] = { "Trex", 1234567, 11567.9 };

	std::string filename = "people.bin";
	std::ofstream out;
	out.open(filename, std::ios::binary);

	if (out.is_open())
	{
		std::cout << "Size of person: " << sizeof(Person) << '\n';
		out.write(reinterpret_cast<char *>(people), 3*sizeof(Person));
		out.close(); // Always
	}
	else
	{
		std::cout << "Couldn't open file " << filename << std::endl;
	}
	delete[] people;

	// Read binary file immediately after writing it
	Person *is_it_them = new Person[3]; // Need to make memory here, because I am going to write to this pointer
	std::ifstream in;
	in.open(filename, std::ios::binary);

	if (in.is_open())
	{
		in.read(reinterpret_cast<char *>(is_it_them), 3*sizeof(Person));
		in.close(); // Always
	}
	else
	{
		std::cout << "Couldn't read file " << filename << std::endl;
	}

	std::cout << "The people inside the struct read from the binary file is:\n";
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Name: " << is_it_them[i].name << ", age: " << is_it_them[i].age << ", weight: " << is_it_them[i].weight << '\n';
	}

	delete[] is_it_them;
    return 0;
}

