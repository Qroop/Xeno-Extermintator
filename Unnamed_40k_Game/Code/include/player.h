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
            sf::RenderWindow& window,
            int health_points,
            int damage,
            int speed);
    ~Player();
    
    sf::Vector2f find_direction() const;
    void update(double delta_time) override;
    void attack() const override;
    void move(double delta_time, size_t window_width, size_t window_height) override;
    bool is_dead() override;
    void death() override;
};
