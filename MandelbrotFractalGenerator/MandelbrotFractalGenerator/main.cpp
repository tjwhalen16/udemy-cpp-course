// MandelbrotFractalGenerator.cpp : Defines the entry point for the console application.
//
// Writes a fractal image to a bitmap

#include "stdafx.h"
#include <iostream>
#include "Bitmap.h"

int main()
{
	const int WIDTH = 800;
	const int HEIGHT = 600;

	Bitmap bitmap(WIDTH, HEIGHT);

	bitmap.SetPixelColor(WIDTH / 2, HEIGHT / 2, 255, 255, 255);
	bitmap.SetPixelColor(100, 100, 255, 255, 255); // paints pixel in bottom left, bitmap file's 0,0 coordinate is at bottom left

	// set every pixel to red
	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++) {
			bitmap.SetPixelColor(x, y, 0, 255, 255);
		}
	}

	if (bitmap.Write("test.bmp")) {
		std::cout << "Successful write\n";
	} else {
		std::cout << "Failed to write\n";
	}

	std::cout << "Finished\n";
    return 0;
}

