#include "../include/cppTutorial1_bits/swarm.hpp"
#include <iostream>
#include <stdlib.h>

namespace project
{
    Swarm::Swarm() : pParticles(new Particle[NPARTICLES]), lastTime(0)
    {
    }

    Swarm::~Swarm()
    {
        delete[] pParticles;
    }

    void Swarm::update(int elapsed)
    {
        int interval = elapsed - lastTime;
        for (int i = 0; i < NPARTICLES; i++)
        {
            pParticles[i].update(interval);
        }

        lastTime = elapsed;
    }
}