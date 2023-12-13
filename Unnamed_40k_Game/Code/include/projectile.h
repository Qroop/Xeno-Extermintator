#pragma once
#include "enemy.h"
#include "game_object.h"

#include <SFML/Graphics.hpp>

class Projectile : public Enemy
{
    public:
    Projectile(sf::Vector2f coordinates, 
                sf::Texture& texture,
                sf::RenderWindow& window,
                int health_points, 
                int damage, 
                int speed,
                Game_Object& player,
                double rotation);
    ~Projectile();

    void update(double delta_time) override;
    void attack() const override;
    void move(double delta_time) override;
    void handle_collision(std::shared_ptr<Game_Object> collided) override;
    void kill_entity(sf::Texture& dead_texture) override;

    private:
    sf::Vector2f direction_to_move;
};