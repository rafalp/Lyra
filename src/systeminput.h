#pragma once

struct key_state
{
    bool down = false;
    bool press = false;
    bool up = false;
};

class LyrSystemInput
{
public:
    bool e_quit = false;
    key_state k_right;
    key_state k_left;
    key_state k_up;
    key_state k_down;
    key_state k_w;
    key_state k_s;

    LyrSystemInput();

    void tick();
};