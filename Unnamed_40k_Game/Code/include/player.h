#pragma once
#include "entity.h"
#include "enemy.h"
#include "grunt.h"

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
            int speed,
            sf::Texture& fire_texture,
            double rotation = 0);
    ~Player();
    
    sf::Vector2f find_direction() const;
    void update(double delta_time);
    void handle_collision(std::shared_ptr<Game_Object> collided) override;
    void attack() const override;
    void move(double delta_time) override;
    void kill_entity(sf::Texture& dead_texture) override;
    void set_health(int hp);

    private:
    sf::Texture& fire_texture;
};
