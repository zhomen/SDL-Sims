#include "window.hpp"

Window::Window()
{
    m_game_window = SDL_CreateWindow("Gravity",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 680, 480, 0);
    m_game_renderer = SDL_CreateRenderer(m_game_window, -1, 0);

    int w, h;
    SDL_GetRendererOutputSize(m_game_renderer, &w, &h);

    Box boxA(w/2 - 25, 10, 1);
    Box boxB(10, 10, 1);
    m_boxes.push_back(boxA);
    m_boxes.push_back(boxB);
}

void Window::game_loop()
{
    bool keep_running = true;
    while(keep_running)
    {
        while(SDL_PollEvent(&m_game_window_event) > 0)
        {
            switch(m_game_window_event.type)
            {
                case SDL_QUIT:
                    keep_running = false;
            }
        }

        update(m_clock.get_delta());
        draw();
        m_clock.tick();
    }
}

void Window::update(double delta_time)
{
    for (auto & element : m_boxes)
    {
        element.update(delta_time);
    }
}

void Window::draw()
{
    SDL_SetRenderDrawColor(m_game_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_game_renderer);

    // Sets the color for the objects
    SDL_SetRenderDrawColor(m_game_renderer, 255, 255, 255, 255);

    for (auto & element : m_boxes)
    {
        element.draw(m_game_renderer);
    }

    SDL_RenderPresent(m_game_renderer);
}

