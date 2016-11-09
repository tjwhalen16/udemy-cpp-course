// MandelbrotFractalGenerator.cpp : Defines the entry point for the console application.
//
// Writes a fractal image to a bitmap

#include "stdafx.h"
#include <iostream>
#include "FractalCreator.h"

#define WIDTH 800
#define HEIGHT 600
#define FILENAME "test.bmp"

int main()
{
	FractalCreator fractal_creator(WIDTH, HEIGHT);
	
	fractal_creator.AddZoom(Zoom(250, HEIGHT - 300, 0.1));
	fractal_creator.AddZoom(Zoom(333, HEIGHT - 578, 0.1));
	fractal_creator.AddZoom(Zoom(200, HEIGHT - 422, 0.1));

	fractal_creator.CalculateIterations();
	fractal_creator.CountTotalIterations();
	fractal_creator.DrawFractal();
	
	if (fractal_creator.WriteBitmap(FILENAME)) {
		std::cout << "Write successful\n";
	} else {
		std::cout << "Failed to write\n";
	}
	
	std::cout << "Finished\n";
    return 0;
}

