#pragma once
#include <string>
#include "Bitmap.h"
#include "ZoomList.h"

class FractalCreator
{
public:
	FractalCreator(int width, int height);
	void CalculateIterations();
	void CountTotalIterations();
	void DrawFractal();
	void AddZoom(const class Zoom& zoom);
	bool WriteBitmap(std::string filename);

private:
	int total_iterations_{ 0 };
	int width_;
	int height_;
	std::vector<int> iteration_count_;
	std::vector<std::vector<int>> iterations_per_pixel_;
	Bitmap bitmap_;
	ZoomList zoom_list_;	
};

