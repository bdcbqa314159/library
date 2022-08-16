#include <game1>
#include <iostream>
#include <array>

using namespace std;

void test()
{
    message();
}

const int GAME_WIDTH = 640;
const int GAME_HEIGHT = 480;

bool isAlive(array<array<int, GAME_HEIGHT>, GAME_WIDTH> &game, const int x, const int y)
{
    int alive = 0;
    // testing the left
    if (x > 0 && game[x - 1][y] == 1)
        alive++;
    if (x < GAME_WIDTH && game[x + 1][y] == 1)
        alive++;
    if (y > 0 && game[x][y - 1] == 1)
        alive++;
    if (y < GAME_HEIGHT && game[x][y + 1] == 1)
        alive++;

    if (y > 0 && x > 0 && game[x - 1][y - 1] == 1)
        alive++;
    if (y > 0 && x < GAME_WIDTH && game[x + 1][y - 1] == 1)
        alive++;
    if (y < GAME_HEIGHT && x > 0 && game[x - 1][y + 1] == 1)
        alive++;
    if (y < GAME_HEIGHT && x < GAME_WIDTH && game[x + 1][y + 1] == 1)
        alive++;

    // live and fewer than 2
    if (game[x][y] == 1 && alive < 2)
        return false;
    // alive and 2 or 3 then live
    if (game[x][y] == 1 && (alive == 2 || alive == 3))
        return true;

    if (alive > 3)
        return false;

    if (game[x][y] == 0 && alive == 3)
        return true;

    return false;
}

int main()
{

    test();

    G screen;

    if (screen.init() == false)
    {
        cout << "Error initialising SDL" << endl;
    }

    array<array<int, GAME_HEIGHT>, GAME_WIDTH>
        display{}, swap{};

    for (auto &row : display)
        generate(row.begin(), row.end(), []()
                 { return rand() % 10 == 0 ? 1 : 0; });

    while (true)
    {
        for (int i = 0; i < GAME_WIDTH; i++)
        {
            for (int k = 0; k < GAME_HEIGHT; k++)
            {
                swap[i][k] = isAlive(display, i, k) ? 1 : 0;
            }
        }
        //
        for (int i = 0; i < GAME_WIDTH; i++)
        {
            for (int k = 0; k < GAME_HEIGHT; k++)
            {
                if (swap[i][k])
                {
                    screen.drawpixel(i, k);
                }
            }
        }

        std::copy(swap.begin(), swap.end(), display.begin());
        screen.update();
        SDL_Delay(20);
        screen.input();
        screen.clearpixels();
    }

    return 0;
}
