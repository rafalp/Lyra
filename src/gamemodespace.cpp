#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include "gamemodespace.h"

void LyrGameModeSpace::create()
{
    m_entities = new LyrEntities();
}

void LyrGameModeSpace::render()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(300.0, 1.0, 0.0, 0.0);
    glRotatef(0.0, 0.0, 0.0, 1.0);

    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -1.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.5f, -0.5f, -1.0f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, -1.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 1.0f, -1.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0, 1.0f, -1.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-0.5f, -0.5f, -1.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0, 1.0f, -1.0f);
    glVertex3f(-0.5f, -0.5f, -1.0f);
    glVertex3f(0.5f, -0.5f, -1.0f);

    glEnd();
}