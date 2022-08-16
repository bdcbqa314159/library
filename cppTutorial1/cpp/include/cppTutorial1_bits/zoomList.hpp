#ifndef ZOOMLIST_H
#define ZOOMLIST_H

#include <vector>
#include <utility>
#include "zoom.hpp"

using namespace std;

class ZoomList
{

    double xCenter{0}, yCenter{0}, scale{1.0};
    int width{0}, height{0};
    vector<Zoom> zooms;

public:
    ZoomList(int width, int height);
    pair<double, double> doZoom(int x, int y);

    void add(const Zoom &zoom);
};

#endif