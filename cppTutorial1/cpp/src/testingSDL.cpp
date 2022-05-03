#include "../include/cppTutorial1_bits/testingSDL.hpp"
#include <iostream>
#include <SDL2/SDL.h>

void testingSDL(int &a)
{
    std::cout << "Testing from the library!" << std::endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL init failed" << std::endl;
        a = 1;
        return;
    }
    std::cout << "SDL Init succeed" << std::endl;
    SDL_Quit();
    a = 0;
    return;
}

void windowOpening()
{
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL init failed" << std::endl;
        return;
    }

    SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == nullptr)
    {
        SDL_Quit();
        std::cout << "Window null" << std::endl;
        return;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

    if (renderer == nullptr)
    {
        std::cout << "Could not create renderer" << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    if (texture == NULL)
    {
        std::cout << "Could not create texture" << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }
    Uint32 *buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

    memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

    // buffer[30000] = 0xFFFFFFFF;

    for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++)
        buffer[i] = 0xFFFF00FF;

    SDL_UpdateTexture(texture, nullptr, buffer, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);

    bool quit = false;
    SDL_Event event;
    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        }
    }

    delete[] buffer;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return;
}