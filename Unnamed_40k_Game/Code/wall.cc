#include "wall.h"
#include <iostream>

Wall::Wall(sf::Vector2f coordinates)
: Game_Object(coordinates)
{
    hitbox.setSize(sf::Vector2f(width, height));
    hitbox.setPosition(coordinates.x, coordinates.y);
}

Wall::~Wall()
{}