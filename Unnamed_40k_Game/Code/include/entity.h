#pragma once
#include "game_object.h"
#include <SFML/Graphics.hpp>

class Entity : public Game_Object
{
    public:
    Entity(sf::Vector2f coordinates,
            sf::Texture& texture, 
            int health_points = 3,
            int damage = 1,
            int speed = 1);

    virtual ~Entity() = 0;

    void draw(sf::RenderWindow& window) override;
    // virtual void update(double delta_time, sf::RenderWindow& window, size_t window_width, size_t window_height) = 0;
    // virtual bool attack() const = 0;
    virtual void move(double delta_time, size_t window_width, size_t window_height) = 0;
    void rotate(sf::Vector2f& direction);
    sf::Vector2f check_boundury_collision(sf::Vector2f direction, double distance_to_move, size_t window_width, size_t window_height);
    bool is_dead();
    void set_speed(int new_speed);
    void set_texture(sf::Texture& new_texture);
    void set_attack_speed(double new_speed);


    protected:
    int health_points;
    int damage;
    int speed;
    double rotation;
    float texture_scale;
    double attack_speed;
    bool dead;
}; 