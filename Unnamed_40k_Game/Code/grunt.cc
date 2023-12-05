#include "grunt.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Grunt::Grunt(sf::Vector2f coordinates, 
            double width, 
            double height, 
            int health_points,
            int damage,
            int speed)
:Enemy(coordinates, width, height, health_points, damage, speed), graphic{}
{
    graphic.setRadius(width/2);
    graphic.setPosition(coordinates.x +16, coordinates.y +16);
}

void Grunt::render(sf::RenderWindow & window)
{
    // std::cout << "is grunt" << coordinates.x << coordinates.y << std::endl;
    window.draw(graphic);
}

void Grunt::move(double delta_time)
{
    coordinates.x += 1 * delta_time;
    coordinates.y += 1;
}

void Grunt::update(double delta_time)
{
    Grunt::move(delta_time);
}