#pragma once
#include "enemy.h"
#include "game_object.h"

#include <SFML/Graphics.hpp>

class Projectile : public Enemy
{
    public:
    Projectile(sf::Vector2f coordinates, 
                sf::Texture& texture, 
                int health_points, 
                int damage, 
                int speed, 
                int window_width, 
                int window_height, 
                Game_Object& player);
    ~Projectile();

    void update(double delta_time) override;
    void attack() const override;
    void move(double delta_time) override;
};