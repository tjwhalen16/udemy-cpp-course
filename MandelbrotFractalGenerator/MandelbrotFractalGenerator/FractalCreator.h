#pragma once
#include <string>

class FractalCreator
{
public:
	FractalCreator(int width, int height);
	void CalculateIterations();
	void DrawFractal();
	void AddZoom(const class Zoom& zoom);
	void WriteBitmap(std::string filename);

private:
	int width_;
	int height_;
};

