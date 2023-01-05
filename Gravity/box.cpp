#include "box.hpp"

Box::Box(int x, int y, int mass)
{
    m_position.w = 50;
    m_position.h = 50;
    m_position.x = x;
    m_position.y = y;
    m_xprev = x;
    m_yprev = y;
    m_mass = mass;
}

void Box::handle_input(SDL_Event const &event)
{

}

void Box::update(double delta_time)
{
    float force_x = 0.0;
    float force_y = 0.1;

    float acceleration_x = force_x / m_mass;
    float acceleration_y = force_y / m_mass;

    int xprev = m_position.x;
    int yprev = m_position.y;

    m_position.x = m_position.x * 2 - m_xprev + acceleration_x * (delta_time * delta_time);
    m_position.y = m_position.y * 2 - m_yprev + acceleration_y * (delta_time * delta_time);

    m_xprev = xprev;
    m_yprev = yprev;
}

void Box::draw(SDL_Renderer *renderer)
{
    SDL_RenderDrawRect(renderer, &m_position);
}