#pragma once
#include "enemy.h"
#include <SFML/Graphics.hpp>

class Grunt : public Enemy
{
    public:
    Grunt(sf::Vector2f coordinates, 
            sf::Texture& texture,
            sf::RenderWindow& window, 
            sf::Texture& projectile_texture,  
            int health_points, int damage, int speed,
            Game_Object& player,
            double rotation = 0);    
    ~Grunt();

    void update(double delta_time) override;
    void move(double delta_time) override;
    void attack() const override;
    // bool is_dead() override;
    // void death() override;
    sf::Vector2f get_lateral_direction() const;
    double get_distance_to_player();
    void kill_entity(sf::Texture& dead_texture) override;
    int get_health();


    private:
    double distance_to_keep;
    bool walk_left;
    sf::Texture& projectile_texture;
};