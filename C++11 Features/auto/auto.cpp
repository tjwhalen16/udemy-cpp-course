// auto.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

template<class T>
auto test(T t) -> T {
	return t;
}

int get() {
	return 8;
}

auto test2() -> decltype(get()) {
	return get();
}

int main()
{
	auto var = 8;

	std::cout << var << '\n';
	std::cout << test(8) << '\n';
	std::cout << test2() << '\n';
    return 0;
}

