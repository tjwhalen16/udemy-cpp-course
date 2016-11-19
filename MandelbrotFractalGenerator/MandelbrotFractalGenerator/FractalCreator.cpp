#include "stdafx.h"
#include "FractalCreator.h"
#include "Zoom.h"
#include "Mandelbrot.h"
#include <cstdint>
#include <vector>
#include <math.h>
#include <iostream>
#include "ColorRgb.h"

FractalCreator::FractalCreator(int width, int height) : width_(width), height_(height), 
	iteration_count_(Mandelbrot::MAX_ITERATIONS, 0), iterations_per_pixel_(width_, std::vector<int>(height_, 0)), 
	bitmap_(width_, height_), zoom_list_(width_, height_) {
	// First zoom is on the center
	AddZoom(Zoom(width_ / 2, height_ / 2, 4.0 / width_));
}

void FractalCreator::AddRange(double rangeEnd, const ColorRgb& rgb) {
	ranges_.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
	colors_.push_back(rgb);

	if (got_first_range_) {
		range_totals_.push_back(0);
	}
	got_first_range_ = true;
}

void FractalCreator::AddZoom(const class Zoom& zoom) {
	zoom_list_.Add(zoom);
}

void FractalCreator::run(std::string filename) {
	CalculateIterations();
	CountTotalIterations();
	CalculateRangeTotals();
	DrawFractal();

	if (WriteBitmap(filename)) {
		std::cout << "Write successful\n";
	} else {
		std::cout << "Failed to write\n";
	}
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

void FractalCreator::CalculateRangeTotals() {
	int range_index = 0;
	int pixels;

	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
		pixels = iteration_count_[i];
		
		if (i >= ranges_[range_index + 1]) {
			range_index++;
		}
		range_totals_[range_index] += pixels;
	}
}

int FractalCreator::GetRange(int iterations) const {
	int range = 0;

	for (int i = 1; i < ranges_.size(); i++) {
		range = i;
		if (ranges_[i] > iterations) {
			break;
		}
	}

	range--; // Convert to 0-based index
	return range;
}

void FractalCreator::DrawFractal() {
	ColorRgb diff(0, 0, 0);// = end_color - start_color;

	int iterations{ 0 };
	int range{ 0 };
	int range_total{ 0 };
	for (int y = 0; y < height_; y++) {
		for (int x = 0; x < width_; x++) {
			uint8_t r{ 0 };
			uint8_t g{ 0 };
			uint8_t b{ 0 };

			iterations = iterations_per_pixel_[x][y];
			//std::cout << iterations << '\n';
			range = GetRange(iterations);
			range_total = range_totals_[range];

			ColorRgb &start_color = colors_[range];
			ColorRgb &end_color = colors_[range + 1];
			diff = end_color - start_color;

			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				//double hue{ 0 };
				int total_pixels = 0;

				for (int i = ranges_[range]; i <= iterations; i++) { // count only in this range
					//hue += static_cast<double>(iteration_count_[i]) / total_iterations_;
					total_pixels += iteration_count_[i];
				}
				
				r = static_cast<uint8_t>(start_color.r + diff.r * static_cast<double>(total_pixels) / range_total);//diff.r * hue;
				g = static_cast<uint8_t>(start_color.g + diff.g * static_cast<double>(total_pixels) / range_total);//diff.r * hue;
				b = static_cast<uint8_t>(start_color.b + diff.b * static_cast<double>(total_pixels) / range_total);//diff.r * hue;

				//std::cout << r << ", " << g << ", " << b << '\n';
				//g = static_cast<uint8_t>(pow(255, hue));
			}

			bitmap_.SetPixelColor(x, y, r, g, b);
		}
	}
}

bool FractalCreator::WriteBitmap(std::string filename) {
	if (bitmap_.Write(filename)) {
		return true;
	} else {
		return false;
	}
}
