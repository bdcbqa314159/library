#ifndef BITMAPFILEHEADER_H
#define BITMAPFILEHEADER_H

#include <cstdint>

using namespace std;

#pragma pack(push, 2)

struct BitMapFileHeader
{
    char header[2]{'B', 'M'};
    int32_t fileSize;
    int32_t reserved{0};
    int32_t dataOffset;
};
#pragma pack(pop)

#endif