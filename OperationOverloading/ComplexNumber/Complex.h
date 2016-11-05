#pragma once

#include <iostream>

class Complex
{
public:
	Complex();
	Complex(const Complex &other);
	Complex(double real, double imaginary);
	Complex &operator=(const Complex &other);
	bool operator==(const Complex &rhs);
	bool operator!=(const Complex &rhs);
	//Complex &operator+=(const Complex &rhs);
	Complex operator*();
	friend Complex operator+(Complex lhs, const Complex &rhs);
	friend Complex operator+(Complex lhs, double rhs);
	friend Complex operator+(double lhs, Complex rhs);
	friend std::ostream &operator<<(std::ostream& out, const Complex &complex);

private:
	double real;
	double imaginary;
};

