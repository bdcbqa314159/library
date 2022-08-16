#include <cmath>
#include <utility>
#include <cassert>

#include "../include/cppTutorial1_bits/fractalCreator.hpp"
#include "../include/cppTutorial1_bits/mandelbrot.hpp"
#include "../include/cppTutorial1_bits/zoom.hpp"

using namespace std;

void FractalCreator::run()
{
    calculateIterations();
    calculateTotalIterations();
    calculateRangeTotals();
    drawFractal();
    writeBitmap("Mandelbrot.bmp");
}

FractalCreator::FractalCreator(int width, int height) : width(width), height(height), histogram(new int[Mandelbrot::MAX_ITERATIONS]{}), fractal(new int[width * height]{}), bitmap(width, height), zoomList(width, height)
{
    zoomList.add(Zoom(width / 2, height / 2, 4. / width));
}

FractalCreator::~FractalCreator()
{
}

void FractalCreator::addRange(double rangeEnd, const RGB &rgb)
{
    ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
    colors.push_back(rgb);

    if (gotFirstRange)
    {
        rangeTotals.push_back(0);
    }

    gotFirstRange = true;
}

int FractalCreator::getRange(int iterations) const
{
    int range = 0;
    for (int i = 1; i < ranges.size(); i++)
    {
        range = i;
        if (ranges[i] > iterations)
        {
            break;
        }
    }
    range--;
    assert(range > -1);
    assert(range < ranges.size());
    return range;
}

void FractalCreator::calculateIterations()
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            pair<double, double> coords = zoomList.doZoom(x, y);

            int iterations = Mandelbrot::getIterations(coords.first, coords.second);
            fractal[y * width + x] = iterations;

            if (iterations != Mandelbrot::MAX_ITERATIONS)
            {
                histogram[iterations]++;
            }
        }
    }
}

void FractalCreator::calculateRangeTotals()
{
    int rangeIndex = 0;
    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
    {
        int pixels = histogram[i];

        if (i >= ranges[rangeIndex + 1])
        {
            rangeIndex++;
        }
        rangeTotals[rangeIndex] += pixels;
    }
}

void FractalCreator::calculateTotalIterations()
{
    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
    {
        total += histogram[i];
    }
}

void FractalCreator::drawFractal()
{

    RGB startColor(0, 0, 20);
    RGB endColor(255, 128, 74);
    RGB colorDiff = endColor - startColor;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int iterations = fractal[y * width + x];
            int range = getRange(iterations);
            int rangeTotal = rangeTotals[range];
            int rangeStart = ranges[range];

            RGB &startColor = colors[range];
            RGB &endColor = colors[range + 1];

            RGB colorDiff = endColor - startColor;

            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            if (iterations != Mandelbrot::MAX_ITERATIONS)
            {
                int totalPixels = 0;
                for (int i = rangeStart; i <= iterations; i++)
                {
                    totalPixels += histogram[i];
                }

                red = startColor.r + colorDiff.r * (double)totalPixels / rangeTotal;
                blue = startColor.b + colorDiff.g * (double)totalPixels / rangeTotal;
                green = startColor.g + colorDiff.b * (double)totalPixels / rangeTotal;
            }

            bitmap.setPixel(x, y, red, green, blue);
        }
    }
}

void FractalCreator::addZoom(const Zoom &zoom)
{
    zoomList.add(zoom);
}

void FractalCreator::writeBitmap(string name)
{
    bitmap.write(name);
}