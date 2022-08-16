#ifndef BITMAP_H
#define BITMAP_H

#include <string>
#include <cstdint>
#include <memory>

using namespace std;

class Bitmap
{

    int width{0}, height{0};
    unique_ptr<uint8_t[]> pixels{nullptr};

public:
    Bitmap(int width, int height);
    ~Bitmap();

    bool write(string filename);
    void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
};

#endif