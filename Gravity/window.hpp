#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "box.hpp"
#include "clock.hpp"

using namespace std;

class Window
{
public:
    Window();
    ~Window() = default;

    void game_loop();
    void update(double);
    void draw();

private:
    SDL_Window   *m_game_window;
    SDL_Event     m_game_window_event;
    SDL_Renderer *m_game_renderer;

    vector<Box>   m_boxes;
    Clock         m_clock;
};