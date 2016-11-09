// MandelbrotFractalGenerator.cpp : Defines the entry point for the console application.
//
// Writes a fractal image to a bitmap

#include "stdafx.h"
#include <iostream>
#include <cstdint>
#include <vector>
#include <math.h>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "FractalCreator.h"

int main()
{
	const int WIDTH = 800;
	const int HEIGHT = 600;

	Bitmap bitmap(WIDTH, HEIGHT);

	ZoomList zoom_list(WIDTH, HEIGHT);
	zoom_list.add(Zoom(WIDTH/2, HEIGHT/2, 4.0/WIDTH)); // First zoom is on the center
	zoom_list.add(Zoom(250, 300, 0.1));
	zoom_list.add(Zoom(333, HEIGHT-578, 0.1));
	zoom_list.add(Zoom(200, HEIGHT - 422, 0.1));

	// Color histogram, zeroed out
	// TODO errors probably
	std::vector<int> iteration_count(Mandelbrot::MAX_ITERATIONS, 0);
	std::vector<std::vector<int>> iterations_per_pixel(WIDTH, std::vector<int>(HEIGHT, 0));

	// set every pixel to red
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			auto coordinates = zoom_list.ZoomIn(x, y);
			//double x_fractal = pair.first;
			//double y_fractal = pair.second;

			int iterations = Mandelbrot::GetIterations(coordinates.first, coordinates.second);
			if (iterations < Mandelbrot::MAX_ITERATIONS) {
				iteration_count[iterations]++;
			}
			iterations_per_pixel[x][y] = iterations; // TODO errors probably			
		}
	}

	int total = 0;
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
		total += iteration_count[i];
	}

	int total_pixel_iterations = 0;
	int iterations{ 0 };
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			uint8_t r{ 0 };
			uint8_t g{ 0 }; //static_cast<uint8_t>(hue * 255)
			uint8_t b{ 0 };

			iterations = iterations_per_pixel[x][y];
			//uint8_t color = static_cast<uint8_t>(256 * static_cast<double>(iterations) / Mandelbrot::MAX_ITERATIONS);

			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				double hue{ 0 };

				for (int i = 0; i <= iterations; i++) {
					hue += static_cast<double>(iteration_count[i]) / total;
				}

				g = static_cast<uint8_t>(pow(255, hue));
			}

			//color = color * color * color;
			bitmap.SetPixelColor(x, y, r, g, b);
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

