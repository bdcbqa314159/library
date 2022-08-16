#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H

#include <string>
#include <memory>
#include <vector>
#include "zoom.hpp"
#include "bitmap.hpp"
#include "zoomList.hpp"
#include "rgb.hpp"

using namespace std;

class FractalCreator
{
    unique_ptr<int[]> histogram;
    unique_ptr<int[]> fractal;
    int width, height;
    Bitmap bitmap;
    ZoomList zoomList;
    int total{0};
    vector<int> ranges;
    vector<RGB> colors;
    vector<int> rangeTotals;

    bool gotFirstRange{false};

private:
    void calculateIterations();
    void calculateTotalIterations();
    void calculateRangeTotals();
    void drawFractal();
    int getRange(int iterations) const;

    void writeBitmap(string name);

public:
    FractalCreator(int width, int height);
    void addZoom(const Zoom &zoom);
    void addRange(double rangeEnd, const RGB &rgb);
    virtual ~FractalCreator();
    void run();
};

#endif