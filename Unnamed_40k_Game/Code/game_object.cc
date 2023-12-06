#include "game_object.h"

Game_Object::Game_Object(sf::Vector2f coordinates)
: coordinates{coordinates}
{
    width = 32;
    height = 32;
    hitbox.setSize(sf::Vector2f(width, height));
    hitbox.setPosition(coordinates);
    hitbox.setOrigin(width / 2.0f, height / 2.0f);
}

Game_Object::~Game_Object() {}


double Game_Object::get_height() const
{
    return height;
}

double Game_Object::get_width() const
{
    return width;
}

sf::Vector2f Game_Object::get_coordinates() const
{
    return coordinates;
}

void Game_Object::draw(sf::RenderWindow& window)
{
    hitbox.setPosition(coordinates);
    window.draw(hitbox);
}