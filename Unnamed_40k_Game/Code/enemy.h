#pragma once
#include "entity.h"
#include <SFML/Graphics.hpp>

class Enemy : public Entity
{
    public:
    Enemy(sf::Vector2f coordinates, 
            double width, 
            double height, 
            int health_points,
            int damage,
            int speed);


    virtual void update(double delta_time) = 0;
    virtual void move(double delta_time) = 0;
    virtual void render(sf::RenderWindow & window) = 0;
};