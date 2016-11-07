#pragma once

#include <string>
#include <cstdint>
#include <memory>

class Bitmap
{
public:
	Bitmap(int width, int height);
	void SetPixelColor(int x, int y, std::uint8_t r, std::uint8_t g, std::uint8_t b);
	bool Write(std::string filename);

private:
	int width_{ 0 };
	int height_{ 0 };
	std::unique_ptr<std::uint8_t[]> pixels_;
};

