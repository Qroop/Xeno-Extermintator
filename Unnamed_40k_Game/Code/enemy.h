#pragma once
#include "entity.h"
#include "player.h"

#include <SFML/Graphics.hpp>

class Enemy : public Entity
{
    public:
    Enemy(sf::Vector2f coordinates, int health_points, int damage, int speed, Player& player);
    virtual ~Enemy() = 0;

    virtual void update(double delta_time, size_t window_width, size_t window_height) = 0;

    protected:
    Player& player;
};