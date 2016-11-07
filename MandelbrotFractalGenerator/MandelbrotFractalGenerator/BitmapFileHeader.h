#pragma once

#include <cstdint>

#pragma pack(push, 2) // TODO use boost serialization instead of pragma pack

// Struct that conatins info necessary for the top of a bitmap file
struct BitmapFileHeader {
	char filetype[2]{ 'B', 'M' }; // 2 bytes representing a bitmap file
	std::int32_t file_size;
	std::int32_t reserved{ 0 }; // Not used
	std::int32_t data_offset; // Where does the data begin?
};

#pragma pack(pop)
