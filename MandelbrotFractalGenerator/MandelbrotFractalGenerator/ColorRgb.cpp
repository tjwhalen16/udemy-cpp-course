#include "stdafx.h"
#include "ColorRgb.h"


ColorRgb::ColorRgb(double r, double g, double b) : r(r), g(g), b(b) {

}

ColorRgb operator-(ColorRgb lhs, const ColorRgb &rhs) {
	lhs.r -= rhs.r;
	lhs.g -= rhs.g;
	lhs.b -= rhs.b;
	return lhs;
}
