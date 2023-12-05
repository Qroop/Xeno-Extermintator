#pragma once
#include "enemy.h"
#include <SFML/Graphics.hpp>

class Grunt : public Enemy
{
    public:
    Grunt(sf::Vector2f coordinates, 
            double width, 
            double height, 
            int health_points,
            int damage,
            int speed);    
    void render(sf::RenderWindow & window) override;
    void update(double delta_time) override;
    void move(double delta_time) override;

    private:
    sf::CircleShape graphic;
};