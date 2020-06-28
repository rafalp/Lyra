#include <SDL2/SDL.h>
#include "stdio.h"
#include "systeminput.h"

LyrSystemInput::LyrSystemInput()
{
    k_right = new key_state;
    k_left = new key_state;
    k_up = new key_state;
    k_down = new key_state;
}

LyrSystemInput::~LyrSystemInput()
{
    delete k_right;
    delete k_left;
    delete k_up;
    delete k_down;
}

void LyrSystemInput::tick()
{
    SDL_Event e;

    e_quit = false;
    k_right->down = false;
    k_right->up = false;
    k_left->down = false;
    k_left->up = false;
    k_up->down = false;
    k_up->up = false;
    k_down->down = false;
    k_down->up = false;

    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            e_quit = true;
        }
        if (e.type == SDL_KEYDOWN)
        {
            if (e.key.keysym.sym == SDLK_ESCAPE)
            {
                e_quit = true;
            }
            if (e.key.keysym.sym == SDLK_RIGHT)
            {
                k_right->down = true;
                k_right->press = true;
            }
            if (e.key.keysym.sym == SDLK_LEFT)
            {
                k_left->down = true;
                k_left->press = true;
            }
            if (e.key.keysym.sym == SDLK_UP)
            {
                k_up->down = true;
                k_up->press = true;
            }
            if (e.key.keysym.sym == SDLK_DOWN)
            {
                k_down->down = true;
                k_down->press = true;
            }
        }
        if (e.type == SDL_KEYUP)
        {
            if (e.key.keysym.sym == SDLK_RIGHT)
            {
                k_right->up = true;
                k_right->press = false;
            }
            if (e.key.keysym.sym == SDLK_LEFT)
            {
                k_left->up = true;
                k_left->press = false;
            }
            if (e.key.keysym.sym == SDLK_UP)
            {
                k_up->up = true;
                k_up->press = false;
            }
            if (e.key.keysym.sym == SDLK_DOWN)
            {
                k_down->up = true;
                k_down->press = false;
            }
        }
    }
}