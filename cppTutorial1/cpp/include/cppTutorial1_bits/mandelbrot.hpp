#ifndef MANDELBROT_H
#define MANDELBROT_H

class Mandelbrot
{

public:
    static const int MAX_ITERATIONS = 1000;

public:
    Mandelbrot();

    static int getIterations(double x, double y);
    ~Mandelbrot();
};

#endif