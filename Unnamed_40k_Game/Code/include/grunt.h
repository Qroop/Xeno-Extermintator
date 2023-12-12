#pragma once
#include "enemy.h"
#include <SFML/Graphics.hpp>

class Grunt : public Enemy
{
    public:
    Grunt(sf::Vector2f coordinates, sf::Texture& texture, sf::Texture& projectile_texture, int health_points, int damage, int speed, int window_width, int window_height, Game_Object& player);    
    ~Grunt();

    void update(double delta_time) override;
    void move(double delta_time) override;
    void attack() const override;
    sf::Vector2f get_lateral_direction() const;
    double get_distance_to_player();

    private:
    double distance_to_keep;
    bool walk_left;
    sf::Texture& projectile_texture;
};