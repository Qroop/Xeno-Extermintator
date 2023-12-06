#pragma once
#include "entity.h"
#include <SFML/Graphics.hpp>

class Player : public Entity
{
    public:
    Player(sf::Vector2f coordinates,
            int health_points,
            int damage,
            int speed);
            // const std::string& texturePath = "");
    ~Player();
    
    sf::Vector2f find_direction() const;
    void update(double delta_time, sf::RenderWindow& window, size_t window_width, size_t window_height);
    // bool attack() const override;
    void move(double delta_time, size_t window_width, size_t window_height);
    sf::Vector2f find_mouse(sf::RenderWindow& window);
};
