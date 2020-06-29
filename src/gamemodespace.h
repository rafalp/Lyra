#pragma once
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include "entities.h"
#include "gamemode.h"
#include "systeminput.h"

class LyrGameModeSpace : public LyrGameMode
{
public:
    LyrSystemInput *m_input;

    void create();
    void destroy();
    bool tick();
    void render();

private:
    float m_rot_x = 0.0;
    float m_rot_y = 0.0;
    GLfloat m_pos_x = 0.0f;
    GLfloat m_pos_y = 0.0f;
    GLfloat m_pos_z = 0.0f;
};
