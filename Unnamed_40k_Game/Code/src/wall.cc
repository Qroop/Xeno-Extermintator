#include "wall.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Wall::Wall(sf::Vector2f coordinates, sf::Texture& texture)
: Game_Object(coordinates, texture)
{
    hitbox.setSize(sf::Vector2f(width, height));
    hitbox.setPosition(coordinates);
    hitbox.setFillColor(sf::Color::Black);
}

Wall::~Wall()
{}

// void Wall::update(double delta_time)
// {

// }

// bool Wall::is_dead()
// {
//     return false;
// }