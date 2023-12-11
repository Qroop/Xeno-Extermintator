#pragma once
#include "entity.h"
#include "player.h"

#include <SFML/Graphics.hpp>

class Enemy : public Entity
{
    public:
    Enemy(sf::Vector2f coordinates, sf::Texture& texture, sf::Texture& dead_texture, sf::RenderWindow& window, int health_points, int damage, int speed, Player& player);
    virtual ~Enemy() = 0;

    virtual void update(double delta_time) = 0;
    virtual void death() = 0;
    virtual bool is_dead() = 0;
    void rotate(sf::Vector2f& direction, double delta_time);
    double shortest_angular_distance(double from, double to) const;
    void set_rotation_speed(double new_rotation_speed);

    protected:
    sf::Texture& dead_texture;
    Player& player;
    double rotation_speed;
};