#pragma once

#include <SDL2/SDL.h>

class Matrix
{
public:
    Matrix();
    ~Matrix() = default;

    void game_loop();
    void update(double);
    const SDL_Point* generateMatrix(int);
    void draw();

private:
    SDL_Window   *m_game_window;
    SDL_Event     m_game_window_event;
    SDL_Renderer *m_game_renderer;
    SDL_Point    *m_points;
};