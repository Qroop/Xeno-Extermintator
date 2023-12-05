#include "wall.h"
#include <iostream>

Wall::Wall(sf::Vector2f coordinates, double width, double height)
: Game_Object(coordinates, width, height)
{
    graphic.setSize(sf::Vector2f(width, height));
    graphic.setPosition(coordinates.x +16, coordinates.y +16);
}

Wall::~Wall()
{}

void Wall::render(sf::RenderWindow & window)
{
    // sf::RectangleShape(sf::Vector2f(width, height));
    // std::cout << "is wall" << coordinates.x << coordinates.y << std::endl;
    window.draw(graphic);
}