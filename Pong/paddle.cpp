#include "paddle.hpp"

Paddle::Paddle(int x, int y)
{
    m_position.x = x;
    m_position.y = y;
    m_position.w = 25;
    m_position.h = 75;
}

void Paddle::handle_input(SDL_Event const &event)
{
    switch(event.type)
    {
        case SDL_KEYDOWN:
            Uint8 const *keys = SDL_GetKeyboardState(nullptr);

            if(m_type == Type::LEFT)
            {
                if(keys[SDL_SCANCODE_W])
                {
                    m_direction = Direction::UP;
                }
                else if(keys[SDL_SCANCODE_S])
                {
                    m_direction = Direction::DOWN;
                }
            } else if(m_type == Type::RIGHT)
            {
                if(keys[SDL_SCANCODE_UP])
                {
                    m_direction = Direction::UP;
                }
                else if(keys[SDL_SCANCODE_DOWN])
                {
                    m_direction = Direction::DOWN;
                }
            }
    }
}

void Paddle::update(double delta_time)
{
    if(m_direction == Direction::UP)
    {
        m_y = m_y - 5.0 * delta_time;
        m_position.y = m_y;
    }
    else if(m_direction == Direction::DOWN)
    {
        m_y = m_y + 5.0 * delta_time;
        m_position.y = m_y;
    }
}

void Paddle::draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &m_position);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}