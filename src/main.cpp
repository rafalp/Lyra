#define TINYOBJLOADER_IMPLEMENTATION
#include <stdio.h>
#include <SDL2/SDL.h>
#include "gamemode.h"
#include "gamemodespace.h"
#include "settings.h"
#include "window.h"

int quit()
{
    SDL_Quit();
    return 1;
}

int main(int argc, char *args[])
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    LyrSettings *settings = new LyrSettings();
    if (!settings->init())
    {
        return quit();
    }

    LyrWindow *window = new LyrWindow();
    if (!window->create(settings))
    {
        return quit();
    }

    LyrGameModeSpace *gamemode = new LyrGameModeSpace();
    gamemode->create();

    bool runloop = true;
    while (runloop)
    {
        window->clear();
        if (gamemode->tick())
        {
            gamemode->tick();
            gamemode->render();
            window->swap();

            SDL_Delay(16);
        }
        else
        {
            gamemode->destroy();
            runloop = false;
        }
    }

    SDL_Quit();

    window->destroy();
    delete window;
    delete settings;
    return 0;
}