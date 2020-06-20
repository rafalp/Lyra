#pragma once

class LyrSettings {
    public:
        bool m_fullscreen;
        int m_screenWidth;
        int m_screenHeight;

        bool fullscreen() {
            return m_fullscreen;
        }

        int screenWidth() {
            return m_screenWidth;
        }

        int screenHeight() {
            return m_screenHeight;
        }

        bool init();
        bool load();
        bool save();
};