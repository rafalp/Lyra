#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <SDL2/SDL.h>
#include "gamemodespace.h"
#include "systeminput.h"

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
        m_rotx -= 1.3;
    }
    if (m_input->k_left->press)
    {
        m_rotx += 1.3;
    }
    if (m_input->k_up->press)
    {
        m_roty += 0.8;
    }
    if (m_input->k_down->press)
    {
        m_roty -= 0.8;
    }

    if (m_rotx > 360) {
        m_rotx -= 360;
    }
    if (m_rotx < 0) {
        m_rotx += 360;
    }
    if (m_roty > 360) {
        m_roty -= 360;
    }
    if (m_roty < 0) {
        m_roty += 360;
    }

    return true;
}

void LyrGameModeSpace::render()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(180, 0.0, 1.0, 0.0);
    glRotatef(m_rotx, 0.0, -.0, 1.0);
    glRotatef(m_roty, 1.0, 0.0, 0.0);

    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.562335f, -1.89494f);
    glColor3f(0.7f, 0.7f, 0.0f);
    glVertex3f(-0.866025f, -0.5f, -2.5f);
    glColor3f(0.4f, 0.4f, 0.0f);
    glVertex3f(0.866025f, -0.5f, -2.5f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, -0.0f, 2.5f);
    glColor3f(0.0f, 0.0f, 0.7f);
    glVertex3f(-0.866025f, -0.5f, -2.5f);
    glColor3f(0.0f, 0.0f, 0.4f);
    glVertex3f(0.866025f, -0.5f, -2.5f);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 2.5f);
    glColor3f(0.7f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.562335f, -1.89494f);
    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex3f(0.866025f, -0.5f, -2.5f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 2.5f);
    glColor3f(0.0f, 0.7f, 0.0f);
    glVertex3f(0.0f, 0.562335f, -1.89494f);
    glColor3f(0.0f, 0.4f, 0.0f);
    glVertex3f(-0.866025f, -0.5f, -2.5f);

    glEnd();
}