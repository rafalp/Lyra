#define GL_SILENCE_DEPRECATION
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include "settings.h"
#include "window.h"

bool LyrWindow::create(LyrSettings *settings)
{
    m_window = SDL_CreateWindow(
        "Lyra",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        settings->m_screenWidth,
        settings->m_screenHeight,
        SDL_WINDOW_OPENGL | (settings->m_fullscreen && SDL_WINDOW_FULLSCREEN));

    if (m_window == NULL)
    {
        // In the case that the window could not be made...
        SDL_Log("Could not create window: %s\n", SDL_GetError());
        return false;
    }

    m_glcontext = SDL_GL_CreateContext(m_window);
    if (m_glcontext == NULL)
    {
        // In the case that the window could not be made...
        SDL_Log("Could not create OpenGL context: %s\n", SDL_GetError());
        return false;
    }

    SDL_GL_SetSwapInterval(1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -20.0, 20.0);
    //gluPerspective(60.0, settings->m_screenWidth / settings->m_screenHeight, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glShadeModel(GL_SMOOTH);
    glClearColor(0, 0, 0, 1);

    SDL_GL_MakeCurrent(m_window, m_glcontext);
    glViewport(0, 0, settings->m_screenWidth, settings->m_screenHeight);
    glLoadIdentity();

    clear();
    swap();

    return true;
}

void LyrWindow::destroy()
{
    if (m_glcontext)
    {
        SDL_GL_DeleteContext(m_glcontext);
    }
    if (m_window)
    {
        SDL_DestroyWindow(m_window);
    }
}

void LyrWindow::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void LyrWindow::swap()
{
    SDL_GL_SwapWindow(m_window);
}
