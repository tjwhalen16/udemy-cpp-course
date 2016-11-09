#include "stdafx.h"

#include <complex>

#include "Mandelbrot.h"

int Mandelbrot::GetIterations(double x, double y) {
	std::complex<double> z = 0;
	std::complex<double> c(x, y);

	int iterations = 0;

	// Returns the number of iterations it takes the algorithm to get to 
	// infinity (MAX_ITERATIONS) for this x,y
	while (iterations < MAX_ITERATIONS) {
		z = z*z + c;

		if (abs(z) > 2) { // if remains below 2, they are in mandlebrot set and they will never get bigger than 2
			break;
		}
		iterations++;
	}
	return iterations;
}
