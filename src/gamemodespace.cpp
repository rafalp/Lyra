#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <SDL2/SDL.h>
#include "gamemodespace.h"
#include "systeminput.h"

const float obj[] = {
    0.0f, 0.562335f, -1.89494f,
    -0.866025f, -0.5f, -2.5f,
    0.866025f, -0.5f, -2.5f,
    0.0f, -0.0f, 2.5f,
    -0.866025f, -0.5f, -2.5f,
    0.866025f, -0.5f, -2.5f,
    0.0f, 0.0f, 2.5f,
    0.0f, 0.562335f, -1.89494f,
    0.866025f, -0.5f, -2.5f,
    0.0f, 0.0f, 2.5f,
    0.0f, 0.562335f, -1.89494f,
    -0.866025f, -0.5f, -2.5f
};

const float colors[] = {
    1.0f, 1.0f, 0.0f,
    0.7f, 0.7f, 0.0f,
    0.4f, 0.4f, 0.0f,
    0.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 0.7f,
    0.0f, 0.0f, 0.4f,
    1.0f, 0.0f, 0.0f,
    0.7f, 0.0f, 0.0f,
    0.4f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.7f, 0.0f,
    0.0f, 0.4f, 0.0f,
};


void LyrGameModeSpace::create()
{
    m_entities = new LyrEntities();
    m_input = new LyrSystemInput();
}

void LyrGameModeSpace::destroy()
{
    delete m_entities;
    delete m_input;
}

bool LyrGameModeSpace::tick()
{
    m_input->tick();
    if (m_input->e_quit)
    {
        return false;
    }

    if (m_input->k_right->press)
    {
        m_rot_x -= 1.3;
    }
    if (m_input->k_left->press)
    {
        m_rot_x += 1.3;
    }
    if (m_input->k_up->press)
    {
        m_rot_y += 0.8;
    }
    if (m_input->k_down->press)
    {
        m_rot_y -= 0.8;
    }

    if (m_rot_x > 360)
    {
        m_rot_x -= 360;
    }
    if (m_rot_x < 0)
    {
        m_rot_x += 360;
    }
    if (m_rot_y > 360)
    {
        m_rot_y -= 360;
    }
    if (m_rot_y < 0)
    {
        m_rot_y += 360;
    }

    if (m_input->k_w->press)
    {
        m_pos_z += 0.01;
    }
    if (m_input->k_s->press)
    {
        m_pos_z -= 0.01;
    }

    return true;
}

void LyrGameModeSpace::render()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_TRIANGLES);

    int vertexes = sizeof(obj) / sizeof(obj[0]) / 3;
    for (int v = 0; v < vertexes; v ++) {
        int i = v * 3;
        glColor3f(colors[i], colors[i + 1], colors[i + 2]);
        glVertex3f(obj[i], obj[i + 1], obj[i + 2]);
    }
    glEnd();
}