#pragma once
#include "entity.h"
#include "enemy.h"

#include <vector>
#include <SFML/Graphics.hpp>
#include <memory>

class Player : public Entity
{
    public:
    Player(sf::Vector2f coordinates,
            sf::Texture& texture,
            int health_points,
            int damage,
            int speed,
            int window_width,
            int window_height);
    ~Player();
    
    sf::Vector2f find_direction() const;
    void update(double delta_time, sf::RenderWindow& window);
    void attack() const override;
    void move(double delta_time) override;
};
