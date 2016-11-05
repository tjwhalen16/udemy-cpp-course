// NestedTemplateRingBuffer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Ring.h"
#include <iostream>

int main()
{
	Ring<int> int_ring(3);
	int_ring.Add(1);
	int_ring.Add(2);
	int_ring.Add(3);
	int_ring.Add(4); // Will overwirte 1

	//std::cout << "Size: " << int_ring.size() << '\n';
	//std::cout << int_ring.begin() << '\n';
	//std::cout << int_ring.end() << '\n';
	//std::cout << sizeof(int_ring.begin()) << '\n';
	//std::cout << sizeof(int_ring.end()) << '\n';
	//std::cout << *int_ring.begin() << '\n';
	//std::cout << *int_ring.end() << '\n';

	for (int i = 0; i < int_ring.size(); i++) {
		std::cout << int_ring.Get(i) << '\n';
	}

	//Ring<std::string> test_ring(3);
	//text_ring.add("one");
	//text_ring.add("two");
	//text_ring.add("three");
	//text_ring.add("four"); // Will overwirte "one"
    return 0;
}

