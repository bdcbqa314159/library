#include "../include/cppTutorial1_bits/zoomList.hpp"

ZoomList::ZoomList(int width, int height) : width(width), height(height)
{
}

void ZoomList::add(const Zoom &zoom)
{
    zooms.push_back(zoom);
    xCenter += (zoom.x - width / 2) * scale;
    yCenter += -(zoom.y - height / 2) * scale;

    scale *= zoom.scale;
}

pair<double, double> ZoomList::doZoom(int x, int y)
{
    double xFractal = (x - width / 2) * scale + xCenter;
    double yFractal = (y - height / 2) * scale + yCenter;
    return make_pair(xFractal, yFractal);
}