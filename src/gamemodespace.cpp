#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <SDL2/SDL.h>
#include <tinyobjloader/tiny_obj_loader.h>
#include "gamemodespace.h"
#include "systeminput.h"

void LyrGameModeSpace::create()
{
    m_entities = new LyrEntities();
    m_input = new LyrSystemInput();

    std::string warn;
    std::string err;

    bool ret = tinyobj::LoadObj(&m_attrib, &m_shapes, &m_materials, &warn, &err, "data/harrier.obj");
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
        return false;
    if (m_input->k_right.press)
        m_rot_x -= 1.3;
    if (m_input->k_left.press)
        m_rot_x += 1.3;
    if (m_input->k_up.press)
        m_rot_y += 0.8;
    if (m_input->k_down.press)
        m_rot_y -= 0.8;

    if (m_rot_x > 360)
        m_rot_x -= 360;
    if (m_rot_x < 0)
        m_rot_x += 360;
    if (m_rot_y > 360)
        m_rot_y -= 360;
    if (m_rot_y < 0)
        m_rot_y += 360;

    if (m_input->k_w.press)
        m_scale += 0.01;
    if (m_input->k_s.press)
        m_scale -= 0.01;

    return true;
}

void LyrGameModeSpace::render()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(m_rot_x, 0.0, 1.0, 0.0);
    glRotatef(m_rot_y, 1.0, 0.0, 0.0);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.6f, 1.0f);
    for (size_t s = 0; s < m_shapes.size(); s++) {
        size_t index_offset = 0;
        for (size_t f = 0; f < m_shapes[s].mesh.num_face_vertices.size(); f++) {
            int fv = m_shapes[s].mesh.num_face_vertices[f];
            for (size_t v = 0; v < fv; v++) {
                tinyobj::index_t idx = m_shapes[s].mesh.indices[index_offset + v];
                tinyobj::real_t vx = m_attrib.vertices[3*idx.vertex_index+0];
                tinyobj::real_t vy = m_attrib.vertices[3*idx.vertex_index+1];
                tinyobj::real_t vz = m_attrib.vertices[3*idx.vertex_index+2];

                glVertex3f(vx, vy, vz);
            }
            index_offset += fv;
        }
    }
    glEnd();
}