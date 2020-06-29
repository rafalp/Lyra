#include <SDL2/SDL.h>
#include "stdio.h"
#include "systeminput.h"

LyrSystemInput::LyrSystemInput()
{
    k_right = key_state();
    k_left = key_state();
    k_up = key_state();
    k_down = key_state();
    k_w = key_state();
    k_s = key_state();
}

void press(key_state *k)
{
    k->down = true;
    k->press = true;
}

void release(key_state *k)
{
    k->up = true;
    k->press = false;
}

void LyrSystemInput::tick()
{
    SDL_Event e;

    e_quit = false;
    k_right.down = false;
    k_right.up = false;
    k_left.down = false;
    k_left.up = false;
    k_up.down = false;
    k_up.up = false;
    k_down.down = false;
    k_down.up = false;
    k_w.down = false;
    k_w.up = false;
    k_s.down = false;
    k_s.up = false;

    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            e_quit = true;
        }
        if (e.type == SDL_KEYDOWN)
        {
            if (e.key.keysym.sym == SDLK_ESCAPE)
                e_quit = true;
            if (e.key.keysym.sym == SDLK_RIGHT)
                press(&k_right);
            if (e.key.keysym.sym == SDLK_LEFT)
                press(&k_left);
            if (e.key.keysym.sym == SDLK_UP)
                press(&k_up);
            if (e.key.keysym.sym == SDLK_DOWN)
                press(&k_down);
            if (e.key.keysym.sym == SDLK_w)
                press(&k_w);
            if (e.key.keysym.sym == SDLK_s)
                press(&k_s);
        }
        if (e.type == SDL_KEYUP)
        {
            if (e.key.keysym.sym == SDLK_RIGHT)
                release(&k_right);
            if (e.key.keysym.sym == SDLK_LEFT)
                release(&k_left);
            if (e.key.keysym.sym == SDLK_UP)
                release(&k_up);
            if (e.key.keysym.sym == SDLK_DOWN)
                release(&k_down);
            if (e.key.keysym.sym == SDLK_w)
                release(&k_w);
            if (e.key.keysym.sym == SDLK_s)
                release(&k_s);
        }
    }
}