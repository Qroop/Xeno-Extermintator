#pragma once
#include "enemy.h"
#include <SFML/Graphics.hpp>

class Grunt : public Enemy
{
    public:
    Grunt(sf::Vector2f coordinates, sf::Texture& texture, int health_points, int damage, int speed, int window_width, int window_height, Game_Object& player);    
    ~Grunt();

    void update(double delta_time) override;
    void move(double delta_time, size_t window_width, size_t window_height) override;
    void attack() const override;
    // bool is_dead() override;
    // void death() override;
    sf::Vector2f get_lateral_direction() const;
    double get_distance_to_player();
    int get_health();


    private:
    double distance_to_keep;
    bool walk_left;
};