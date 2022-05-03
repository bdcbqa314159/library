#include <iostream>
#include <SDL2/SDL.h>
#include <cppTutorial1>

// This tests if we can call sdl from a simple cpp
using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL init failed" << endl;
        return 1;
    }
    cout << "SDL Init succeed" << endl;
    SDL_Quit();

    int n = 0;
    testingSDL(n);
    if (n == 0)
        cout << "C'est ok" << endl;
    else
        cout << "C'est cuit" << endl;

    windowOpening();

    return 0;
}