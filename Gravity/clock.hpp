#pragma once

#include <SDL2/SDL.h>

class Clock
{
public:
    Clock();
    ~Clock() = default;

    void tick();
    int get_delta();
private:
    int     m_last_tick_time;
    int     m_delta;
    int     m_tick_time;
};