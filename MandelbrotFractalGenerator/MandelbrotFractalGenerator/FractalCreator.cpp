#include "stdafx.h"
#include "FractalCreator.h"
#include "Zoom.h"
#include "Mandelbrot.h"
#include <cstdint>
#include <vector>
#include <math.h>

FractalCreator::FractalCreator(int width, int height) : width_(width), height_(height), 
	iteration_count_(Mandelbrot::MAX_ITERATIONS, 0), iterations_per_pixel_(width_, std::vector<int>(height_, 0)), 
	bitmap_(width_, height_), zoom_list_(width_, height_) {
	// First zoom is on the center
	AddZoom(Zoom(width_ / 2, height_ / 2, 4.0 / width_));
}

void FractalCreator::CalculateIterations() {
	for (int y = 0; y < height_; y++) {
		for (int x = 0; x < width_; x++) {
			auto coordinates = zoom_list_.ZoomIn(x, y);
			int iterations = Mandelbrot::GetIterations(coordinates.first, coordinates.second);
			if (iterations < Mandelbrot::MAX_ITERATIONS) {
				iteration_count_[iterations]++;
			}
			iterations_per_pixel_[x][y] = iterations;			
		}
	}
}

void FractalCreator::CountTotalIterations()
{
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
		total_iterations_ += iteration_count_[i];
	}
}



void FractalCreator::DrawFractal() {
	int iterations{ 0 };
	for (int y = 0; y < height_; y++) {
		for (int x = 0; x < width_; x++) {
			uint8_t r{ 0 };
			uint8_t g{ 0 };
			uint8_t b{ 0 };

			iterations = iterations_per_pixel_[x][y];

			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				double hue{ 0 };

				for (int i = 0; i <= iterations; i++) {
					hue += static_cast<double>(iteration_count_[i]) / total_iterations_;
				}
				g = static_cast<uint8_t>(pow(255, hue));
			}

			bitmap_.SetPixelColor(x, y, r, g, b);
		}
	}
}

void FractalCreator::AddZoom(const class Zoom& zoom) {
	zoom_list_.Add(zoom);
}

bool FractalCreator::WriteBitmap(std::string filename) {
	if (bitmap_.Write("test.bmp")) {
		return true;
	} else {
		return false;
	}
}
