#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include "gamemodespace.h"

void LyrGameModeSpace::onTick() {
    m_rotation += 1.0;
    if (m_rotation > 360.0) {
        m_rotation -= 360.0;
    }
}

void LyrGameModeSpace::render() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(300.0, 1.0, 0.0, 0.0);
    glRotatef(m_rotation, 0.0, 0.0, 1.0);

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