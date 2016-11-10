// MandelbrotFractalGenerator.cpp : Defines the entry point for the console application.
//
// Writes a fractal image to a bitmap

#include "stdafx.h"
#include <iostream>
#include "FractalCreator.h"
#include "ColorRgb.h"

#define WIDTH 800
#define HEIGHT 600
#define FILENAME "test.bmp"

int main()
{
	FractalCreator fractal_creator(WIDTH, HEIGHT);
	
	fractal_creator.AddRange(0.0, ColorRgb(0, 0, 0));
	fractal_creator.AddRange(0.3, ColorRgb(255, 0, 0));
	fractal_creator.AddRange(0.5, ColorRgb(0, 255, 0));
	fractal_creator.AddRange(1.0, ColorRgb(0, 0, 255));

	fractal_creator.AddZoom(Zoom(250, HEIGHT - 300, 0.1));
	fractal_creator.AddZoom(Zoom(333, HEIGHT - 578, 0.1));
	fractal_creator.AddZoom(Zoom(200, HEIGHT - 422, 0.1));

	fractal_creator.run(FILENAME);
	
	
	std::cout << "Finished\n";
    return 0;
}

