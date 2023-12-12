#pragma once
#include "entity.h"
#include <SFML/Graphics.hpp>

class Enemy : public Entity
{
    public:
    Enemy(sf::Vector2f coordinates, sf::Texture& texture, int health_points, int damage, int speed, int window_width, int window_height, Game_Object& player);
    virtual ~Enemy() = 0;

    virtual void update(double delta_time) = 0;
    void rotate(sf::Vector2f& direction, double delta_time);
    double shortest_angular_distance(double from, double to) const;
    void set_rotation_speed(double new_rotation_speed);

    protected:
    Entity& player;
    double rotation_speed;
};