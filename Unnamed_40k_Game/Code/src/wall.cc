#include "wall.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Wall::Wall(sf::Vector2f coordinates, sf::Texture& texture, sf::RenderWindow& window)
: Game_Object(coordinates, texture, window)
{
    hitbox.setSize(sf::Vector2f(width, height));
    hitbox.setPosition(coordinates);
    hitbox.setFillColor(sf::Color::Black);
}

Wall::~Wall()
{}