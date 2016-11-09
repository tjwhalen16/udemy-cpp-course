#pragma once

#include "Zoom.h"
#include <vector>
#include <utility>

class ZoomList
{
public:
	ZoomList(int width, int height);
	void add(const Zoom& zoom);
	std::pair<double, double> ZoomIn(int x, int y);

private:
	double x_center_{ 0 };
	double y_center_{ 0 };
	double scale_{ 1.0 };
	int width_;
	int height_;
	std::vector<Zoom> zooms_;
};

