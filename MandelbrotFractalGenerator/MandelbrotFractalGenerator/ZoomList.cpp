#include "stdafx.h"
#include "ZoomList.h"


ZoomList::ZoomList(int width, int height) : width_(width), height_(height) {
}

void ZoomList::add(const Zoom& zoom) {
	zooms_.push_back(zoom);

	x_center_ += (zoom.x - width_ / 2) * scale_; // ... += center of screen for this zoom
	y_center_ += (zoom.y - height_ / 2) * scale_; // ... += center of screen for this zoom
	scale_ *= zoom.scale;
}

std::pair<double, double> ZoomList::ZoomIn(int x, int y) {
	return std::pair<double, double>((x - width_ / 2) * scale_ + x_center_, (y - height_ / 2) * scale_ + y_center_);
}
