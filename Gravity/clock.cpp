#include "clock.hpp"

Clock::Clock()
{
    m_last_tick_time = 0;
    m_delta = 0;
}

void Clock::tick()
{
    m_tick_time = SDL_GetTicks();
    m_delta = m_tick_time - m_last_tick_time;
    m_last_tick_time = m_tick_time;
}

int Clock::get_delta()
{
    return m_delta/1000;
}