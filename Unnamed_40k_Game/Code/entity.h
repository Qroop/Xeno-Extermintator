#pragma once
#include "game_object.h"
#include <SFML/Graphics.hpp>

class Entity : public Game_Object
{
    public:
    Entity(sf::Vector2f coordinates,
            double width, 
            double height, 
            int health_points = 3,
            int damage = 1,
            int speed = 1);

    virtual ~Entity() = 0;

    
    virtual void update(double delta_time) = 0;
    // virtual bool attack() const = 0;
    virtual void move(double delta_time) = 0;
    virtual void render(sf::RenderWindow & window) = 0;
    

    protected:
    int health_points;
    int damage;
    int speed;
    double rotation;
};