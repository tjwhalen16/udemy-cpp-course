// ComplexNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Complex.h"
#include <iostream>

int main()
{
	Complex imag(4.5, -1.23);
	Complex inverse(-4.5, 1.23);
	Complex imagCopy = imag;
	Complex inverseCopy = inverse;
	inverse = inverse + 1.0;
	inverse = 1.0 + inverse;
	std::cout << (imag + inverse) << '\n';

	if (imag == imagCopy) {
		std::cout << "Success\n";
	}

	if (inverse != imagCopy) {
		std::cout << "Success\n";
	}

	std::cout << "imag: " << imag << '\n';
	std::cout << "imag congegate: " << *imag << '\n';

    return 0;
}

