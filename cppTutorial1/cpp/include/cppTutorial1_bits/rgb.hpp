#ifndef RGB_H
#define RGB_H

struct RGB
{
    double r, g, b;

    RGB(double r, double g, double b);
    ~RGB(){};
};

RGB operator-(const RGB &first, const RGB &second);

#endif