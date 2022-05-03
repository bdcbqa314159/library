#ifndef SWARM_H
#define SWARM_H

#include <SDL2/SDL.h>
#include "particle.hpp"

namespace project
{
    class Swarm
    {
    public:
        const static int NPARTICLES = 5000;

    private:
        Particle *pParticles;
        int lastTime;

    public:
        Swarm();

        const Particle *const getParticles()
        {
            return pParticles;
        }
        void update(int elapsed);

        ~Swarm();
    };
}

#endif