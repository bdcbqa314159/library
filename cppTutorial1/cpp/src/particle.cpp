#include "../include/cppTutorial1_bits/particle.hpp"
#include <iostream>
#include <math.h>
#include <stdlib.h>

namespace project
{
    Particle::Particle() : x(0), y(0)
    {
        init();
    }

    void Particle::init()
    {
        x = 0;
        y = 0;

        direction = (2 * M_PI * rand()) / RAND_MAX;
        speed = (0.04 * rand()) / RAND_MAX;
        speed *= speed;
    }

    Particle::~Particle()
    {
    }

    void Particle::update(int interval)
    {
        direction += interval * 0.0002;

        double xSpeed = speed * cos(direction);
        double ySpeed = speed * sin(direction);

        x += xSpeed * interval;
        y += ySpeed * interval;

        if (x < -1 || x > 1 || y < -1 || y > 1)
        {
            init();
        }

        if (rand() < RAND_MAX / 100)
        {
            init();
        }
    }
}