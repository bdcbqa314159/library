#include <fstream>
#include "../include/cppTutorial1_bits/bitmap.hpp"
#include "../include/cppTutorial1_bits/bitmapInfoHeader.hpp"
#include "../include/cppTutorial1_bits/bitmapFileHeader.hpp"

Bitmap::Bitmap(int width, int height) : width(width), height(height), pixels(new uint8_t[width * height * 3]())
{
}

Bitmap::~Bitmap()
{
}

bool Bitmap::write(string filename)
{
    BitMapFileHeader fileHeader;
    BitMapInfoHeader infoHeader;

    fileHeader.fileSize = sizeof(BitMapFileHeader) + sizeof(BitMapInfoHeader) + width * height * 3;

    fileHeader.dataOffset = sizeof(BitMapFileHeader) + sizeof(BitMapInfoHeader);

    infoHeader.width = width;
    infoHeader.height = height;

    ofstream file;

    file.open(filename.c_str(), ios::out | ios::binary);

    if (!file)
    {
        return false;
    }

    file.write((char *)&fileHeader, sizeof(fileHeader));
    file.write((char *)&infoHeader, sizeof(infoHeader));
    file.write((char *)pixels.get(), width * height * 3);

    file.close();

    if (!file)
    {
        return false;
    }

    return false;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{
    uint8_t *pixel = pixels.get();

    pixel += 3 * (y * width + x);
    pixel[0] = blue;
    pixel[1] = green;
    pixel[2] = red;

    return;
}