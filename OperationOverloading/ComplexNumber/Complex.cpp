#include "stdafx.h"
#include "Complex.h"
#include <iostream>

Complex::Complex() : real(0), imaginary(0) {
}

Complex::Complex(const Complex &other) : real(other.real), imaginary(other.imaginary) {
}

Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary) {
}

Complex& Complex::operator=(const Complex &other) {
	real = other.real;
	imaginary = other.imaginary;
	return *this;
}

bool Complex::operator==(const Complex &rhs) {
	return real == rhs.real && imaginary == rhs.imaginary;
}

bool Complex::operator!=(const Complex &rhs) {
	return !(*this == rhs);
}

Complex Complex::operator*() {
	return Complex(real, -imaginary);
}

Complex operator+(Complex c, const Complex &other) {
	c.real = c.real + other.real;
	c.imaginary = c.imaginary + other.imaginary;
	return c;

}

Complex operator+(Complex lhs, double rhs) {
	lhs.real = lhs.real + rhs;
	return lhs;
}

Complex operator+(double lhs, Complex rhs) {
	//rhs.real = rhs.real + lhs;
	//return rhs;
	return rhs + lhs;
}

std::ostream& operator<<(std::ostream& out, const Complex &complex) {
	out << complex.real << " + " << complex.imaginary << "i";
	return out;
}



