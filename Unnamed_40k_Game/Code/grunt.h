#pragma once
#include "enemy.h"
#include <SFML/Graphics.hpp>

class Grunt : public Enemy
{
    public:
    Grunt(sf::Vector2f coordinates, int health_points, int damage, int speed, Player& player);    
    ~Grunt();

    // void render(sf::RenderWindow & window) override;
    void update(double delta_time, size_t window_width, size_t window_height) override;
    void move(double delta_time, size_t window_width, size_t window_height) override;

    private:
    sf::CircleShape hitbox;
};