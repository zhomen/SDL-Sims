#pragma once

#include <SDL2/SDL.h>

class Box
{
public:
    Box(int x, int y, int mass);
    ~Box() = default;

    void handle_input(SDL_Event const &event);
    void update(double delta_time);
    void draw(SDL_Renderer*);
private:
    SDL_Rect m_position;
    int m_xprev;
    int m_yprev;
    int m_mass;
};