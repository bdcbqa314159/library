#ifndef SCREEN_H
#define SCREEN_H

#include <SDL2/SDL.h>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
class Screen
{
public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    Uint32 *buffer1;
    Uint32 *buffer2;

public:
    Screen();
    bool init();
    bool processEvents();
    void close();
    void update();
    // void clear();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    void boxBlur();
};

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

class G
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_bool done;
    vector<SDL_FPoint> points;
    vector<SDL_Color> colors;
    SDL_Event event;

public:
    const static int SCREEN_WIDTH = 640;
    const static int SCREEN_HEIGHT = 480;

    G() : window(nullptr), renderer(nullptr)
    {
    }

    bool init()
    {
        // SDL_Init(SDL_INIT_VIDEO);
        // SDL_CreateWindowAndRenderer(640 * 40, 480 * 4, SDL_WINDOW_ALLOW_HIGHDPI, &window, &renderer);
        // SDL_RenderSetScale(renderer, 4, 4);

        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            std::cout << "SDL init failed" << std::endl;
            return false;
        }

        window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (window == nullptr)
        {
            SDL_Quit();
            std::cout << "Window null" << std::endl;
            return false;
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
        // texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

        if (renderer == nullptr)
        {
            std::cout << "Could not create renderer" << std::endl;
            SDL_DestroyWindow(window);
            SDL_Quit();
            return false;
        }

        // if (texture == NULL)
        // {
        //     std::cout << "Could not create texture" << std::endl;
        //     SDL_DestroyRenderer(renderer);
        //     SDL_DestroyWindow(window);
        //     SDL_Quit();
        //     return false;
        // }
        // buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
        // buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

        // memset(buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
        // memset(buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

        // buffer[30000] = 0xFFFFFFFF;

        // for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++)
        //     buffer[i] = 0xFFFF00FF;

        return true;
    }

    void drawpixel(double xm, double ym, uint8_t r = 255, uint8_t g = 255, uint8_t b = 255, uint8_t a = 255)
    {
        SDL_FPoint tempFPoint;
        tempFPoint.x = xm;
        tempFPoint.y = ym;
        points.push_back(tempFPoint);
        SDL_Color tempColor;
        tempColor.r = r;
        tempColor.g = g;
        tempColor.b = b;
        tempColor.a = a;
        colors.push_back(tempColor);
    }

    void clearpixels()
    {
        points.clear();
    }

    void update()
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        for (long unsigned int i = 0; i < points.size(); i++)
        {

            SDL_SetRenderDrawColor(renderer, colors[i].r, colors[i].g, colors[i].b, colors[i].a);
            SDL_RenderDrawPointF(renderer, points[i].x, points[i].y);
        }
        SDL_RenderPresent(renderer);
    }

    void input()
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            /* SDL_QUIT event (window close) */
            case SDL_QUIT:
                SDL_Quit();
                exit(0);
                break;

            default:
                break;
            }
        }
    }
};

#endif