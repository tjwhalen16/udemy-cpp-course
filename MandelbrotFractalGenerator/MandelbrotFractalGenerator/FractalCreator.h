#pragma once
#include <string>
#include "Bitmap.h"
#include "ZoomList.h"
#include "ColorRgb.h"

class FractalCreator
{
public:
	FractalCreator(int width, int height);
	void AddZoom(const Zoom& zoom);
	void AddRange(double rangeEnd, const ColorRgb& rgb);
	void run(std::string filename);

private:
	void CalculateIterations();
	void CountTotalIterations();
	void DrawFractal();
	bool WriteBitmap(std::string filename);
	void CalculateRangeTotals();
	int GetRange(int iterations) const;


	int total_iterations_{ 0 };
	int width_;
	int height_;
	std::vector<int> iteration_count_;
	std::vector<std::vector<int>> iterations_per_pixel_;
	Bitmap bitmap_;
	ZoomList zoom_list_;	
	std::vector<double> ranges_;
	std::vector<ColorRgb> colors_;
	std::vector<int> range_totals_;
	bool got_first_range_{ false };
};

