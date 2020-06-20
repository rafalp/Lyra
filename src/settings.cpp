#include <iostream>
#include <fstream>
#include <sstream>
#include <SDL.h>
#include <nlohmann/json.hpp>
#include "settings.h"

using namespace std;
using json = nlohmann::json;

bool LyrSettings::init() {
    SDL_DisplayMode dm;
    if (SDL_GetDesktopDisplayMode(0, &dm) != 0) {
        SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
        return false;
    }

    m_fullscreen = true;
    m_screenWidth = dm.w;
    m_screenHeight = dm.h;

    if (!load() && !save()) {
        return false;
    }

    return true;
}

bool LyrSettings::load() {
    ifstream fp;
    stringstream buffer;

    fp.open("settings.json", ios::in);
    if (!fp.is_open()) {
        return false;
    }

    buffer << fp.rdbuf();
    fp.close();

    try {
        json j = json::parse(buffer);
        if (!j.is_object()) {
            return false;
        }

        m_fullscreen = j.value("fullscreen", true);
        m_screenWidth = j.value("screenWidth", m_screenWidth);
        m_screenHeight = j.value("screenHeight", m_screenHeight);
    } catch (json::parse_error e) {
        return false;
    }

    if (m_screenWidth < 320 || m_screenHeight < 240) {
        return false;
    }

    return true;
}

bool LyrSettings::save() {
    json j;
    ofstream fp;

    j["fullscreen"] = m_fullscreen;
    j["screenWidth"] = m_screenWidth;
    j["screenHeight"] = m_screenHeight;

    fp.open("settings.json", ios::out | ios::trunc);
    if (fp.is_open()) {
        fp << j.dump();
        fp.close();
        return true;
    }

    return false;
}