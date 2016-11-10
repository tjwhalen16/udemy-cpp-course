#pragma once
struct ColorRgb
{
	ColorRgb(double r, double g, double b);
	friend ColorRgb operator-(ColorRgb lhs, const ColorRgb &rhs);
	double r;
	double g;
	double b;
};

