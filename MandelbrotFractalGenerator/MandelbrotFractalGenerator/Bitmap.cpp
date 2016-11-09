#include "stdafx.h"

#include <fstream>
#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

Bitmap::Bitmap(int width, int height) : width_(width), height_(height), pixels_(new uint8_t[width_ * height_ * 3]{ 0 }) { // *3 because each pixel has 3 color values (r, g, and b)
}

void Bitmap::SetPixelColor(int x, int y, uint8_t r, uint8_t g, uint8_t b) {
	uint8_t *pixel = pixels_.get();

	// y*width moves down approprite number of rows
	// adding x moves within that row to the correct column
	// multiply by 3 because each xy coordinate is 3 bytes long (r, g, and b)
	pixel += (y * width_ + x) * 3;

	// little endian stroes the least significant byte in the lowest memory address
	// bitmap files are stored little endian, so b is first in the memory
	pixel[0] = b;
	pixel[1] = g;
	pixel[2] = r;
}

bool Bitmap::Write(std::string filename) {
	BitmapFileHeader file_header;
	file_header.file_size = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + width_ * height_ * 3;
	file_header.data_offset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
	
	BitmapInfoHeader info_header;
	info_header.width = width_;
	info_header.height = height_;

	std::ofstream out;
	out.open(filename, std::ios::binary);

	if (!out) {
		return false; // Failed to open the file
	}

	// File opened successfully
	out.write(reinterpret_cast<char *>(&file_header), sizeof(file_header));
	out.write(reinterpret_cast<char *>(&info_header), sizeof(info_header));
	out.write(reinterpret_cast<char *>(pixels_.get()), width_ * height_ * 3);

	out.close();
	if (!out) {
		return false; // Failed to close the file
	}

	return true;
}
