// NestedTemplateRingBuffer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Ring.h"
#include <iostream>

int main()
{
	Ring<int> ring(3);
	ring.Add(1);
	ring.Add(2);
	ring.Add(3);
	ring.Add(4); // Will overwirte 1

	for (int i = 0; i < ring.size(); i++) {
		std::cout << ring.Get(i) << '\n';
	}

	std::cout << '\n';
	Ring<int> ring_copy = ring;

	for (auto value : ring_copy) {
		std::cout << value << '\n';
	}


	return 0;

	// Couldn't get it working for strings becuase setting up the copy constructor was getting crazy

	//Ring<std::string> ring(3);
	//ring.Add("one");
	//ring.Add("two");
	//ring.Add("three");
	//ring.Add("four"); // Will overwirte 1

	//for (int i = 0; i < ring.size(); i++) {
	//	std::cout << ring.Get(i) << '\n';
	//}

	//std::cout << '\n';
	//Ring<std::string> ring_copy = ring;

	//for (auto value : ring_copy) {
	//	std::cout << value << '\n';
	//}

	////for (auto it )

 //   return 0;
}

