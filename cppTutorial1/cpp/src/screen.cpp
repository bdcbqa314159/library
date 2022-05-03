#include "../include/cppTutorial1_bits/screen.hpp"
#include <iostream>
#include <sstream>

namespace project
{
    Screen::Screen() : window(nullptr), renderer(nullptr), texture(nullptr), buffer1(nullptr), buffer2(nullptr)
    {
    }
    bool Screen::init()
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            std::cout << "SDL init failed" << std::endl;
            return false;
        }

        window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (window == nullptr)
        {
            SDL_Quit();
            std::cout << "Window null" << std::endl;
            return false;
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
        texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

        if (renderer == nullptr)
        {
            std::cout << "Could not create renderer" << std::endl;
            SDL_DestroyWindow(window);
            SDL_Quit();
            return false;
        }

        if (texture == NULL)
        {
            std::cout << "Could not create texture" << std::endl;
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            SDL_Quit();
            return false;
        }
        buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
        buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

        memset(buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
        memset(buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

        // buffer[30000] = 0xFFFFFFFF;

        // for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++)
        //     buffer[i] = 0xFFFF00FF;

        return true;
    }

    bool Screen::processEvents()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                return false;
            }
        }
        return true;
    }

    void Screen::close()
    {
        delete[] buffer1;
        delete[] buffer2;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyTexture(texture);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    void Screen::update()
    {
        SDL_UpdateTexture(texture, nullptr, buffer1, SCREEN_WIDTH * sizeof(Uint32));
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, nullptr, nullptr);
        SDL_RenderPresent(renderer);
    }

    // void Screen::clear()
    // {
    //     memset(buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
    //     return;
    // }

    void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
    {
        if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
        {
            return;
        }

        Uint32 color = 0;

        color += red;
        color <<= 8;
        color += green;
        color <<= 8;
        color += blue;
        color <<= 8;
        color += 0xFF;

        buffer1[(y * SCREEN_WIDTH) + x] = color;
    }

    void Screen::boxBlur()
    {
        Uint32 *temp = buffer1;
        buffer1 = buffer2;
        buffer2 = temp;

        for (int y = 0; y < Screen::SCREEN_HEIGHT; y++)
        {
            for (int x = 0; x < Screen::SCREEN_WIDTH; x++)
            {
                int redTotal = 0, greenTotal = 0, blueTotal = 0;
                for (int row = -1; row <= 1; row++)
                {

                    for (int col = -1; col <= 1; col++)
                    {
                        int currX = x + col;
                        int currY = y + row;

                        if (currX >= 0 && currX < SCREEN_WIDTH && currY >= 0 && currY < SCREEN_HEIGHT)
                        {
                            Uint32 color = buffer2[currY * SCREEN_WIDTH + currX];

                            Uint8 red = color >> 24;
                            Uint8 green = color >> 16;
                            Uint8 blue = color >> 8;

                            redTotal += red;
                            greenTotal += green;
                            blueTotal += blue;
                        }
                    }
                }
                Uint8 red = redTotal / 9;
                Uint8 green = greenTotal / 9;
                Uint8 blue = blueTotal / 9;
                setPixel(x, y, red, green, blue);
            }
        }
    }
}