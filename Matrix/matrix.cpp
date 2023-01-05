#include "matrix.hpp"

Matrix::Matrix()
{
    m_game_window = SDL_CreateWindow("Matrix",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 680, 480, 0);
    m_game_renderer = SDL_CreateRenderer(m_game_window, -1, 0);
}

void Matrix::game_loop()
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

        update(1.0/60.0);
        draw();
    }
}

void Matrix::update(double delta_time)
{

}

const SDL_Point* Matrix::generateMatrix(int n)
{
    // Allocates more memory on the heap for points
    m_points = new SDL_Point[n*n];

    int w, h;
    SDL_GetRendererOutputSize(m_game_renderer, &w, &h);

    int spacing = 10;
    int xoff = w/2 - (n*spacing)/2;
    int yoff = h/2 - (n*spacing)/2;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            m_points[j*n + i].x = j + xoff + j*spacing;
            m_points[j*n + i].y = i + yoff + i*spacing;
        }
    }

    return m_points;
}

void Matrix::draw()
{
    SDL_SetRenderDrawColor(m_game_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_game_renderer);

    // Sets the color for the objects
    SDL_SetRenderDrawColor(m_game_renderer, 255, 255, 255, 255);

    // Draws a line between the given indexes
    //SDL_RenderDrawLine(m_game_renderer, 50, 50, 100, 100);

    // Draws a single point at the given index
    //SDL_RenderDrawPoint(m_game_renderer, 110, 110);

    int num_points = 30;
    SDL_RenderDrawPoints(m_game_renderer, generateMatrix(num_points), num_points*num_points);

    SDL_RenderPresent(m_game_renderer);
}

