#include "game_object.h"

Game_Object::Game_Object(sf::Vector2f coordinates, double width, double height) // const std::string& texture_path)
: coordinates{coordinates}, width{width}, height{height}
{
    hitbox.setSize(sf::Vector2f(static_cast<float>(width), static_cast<float>(height)));
    hitbox.setPosition(coordinates);
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