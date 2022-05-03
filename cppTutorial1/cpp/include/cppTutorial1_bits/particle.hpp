#ifndef PARTICLE_H
#define PARTICLE_H

#include <SDL2/SDL.h>

namespace project
{
    struct Particle
    {
        double x;
        double y;

    private:
        double speed;
        double direction;
        void init();

    public:
        Particle();

        void update(int interval);
        ~Particle();
    };
}

#endif
