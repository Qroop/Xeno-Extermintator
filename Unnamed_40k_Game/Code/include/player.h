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
            int window_width,
            int window_height);
    ~Player();
    
    sf::Vector2f find_direction() const;
    void update(double delta_time, sf::RenderWindow& window);
    void attack() const override;
    void move(double delta_time, size_t window_width, size_t window_height) override;
    bool is_dead() override;
    void death() override;
    void set_enemies(std::vector<std::shared_ptr<Grunt>>& enemies);

    private:
    std::vector<std::shared_ptr<Grunt>>* loaded_enemies;
};
