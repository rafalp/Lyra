#pragma once
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <tinyobjloader/tiny_obj_loader.h>
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
    float m_scale = 1.0f;

    tinyobj::attrib_t m_attrib;
    std::vector<tinyobj::shape_t> m_shapes;
    std::vector<tinyobj::material_t> m_materials;
};
