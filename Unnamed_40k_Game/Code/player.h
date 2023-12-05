#pragma once
#include "entity.h"
#include <SFML/Graphics.hpp>

class Player : public Entity
{
    public:
    Player(sf::Vector2f coordinates, 
            double width, 
            double height, 
            int health_points,
            int damage,
            int speed);
            // const std::string& texturePath = "");
    ~Player();
    
    sf::Vector2f find_direction() const;
    void update(double delta_time) override;
    // bool attack() const override;
    void move(double delta_time) override;
    void render(sf::RenderWindow & window) override;

    private:
    sf::RectangleShape graphic;
};
