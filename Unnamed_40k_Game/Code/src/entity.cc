#include "entity.h"
#include "enemy.h"
#include "grunt.h"
#include "wall.h"

#include <iostream>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>
#include <memory>
#include <memory>

Entity::Entity(sf::Vector2f coordinates, sf::Texture& texture, sf::RenderWindow& window, int health_points, int damage, int speed, double rotation)
: Game_Object(coordinates, texture, window), health_points(health_points), damage(damage), speed(speed), loaded_enemies(nullptr), rotation(rotation)
{
    int int_window_width = window.getSize().x;
    int int_window_height = window.getSize().y;
    sf::Vector2i int_window_size(int_window_width, int_window_height);
    window_size = int_window_size;

    damage_effect_duration = sf::seconds(0.3f);

    dead = false;
}


Entity::~Entity() 
{
    loaded_enemies = nullptr;
}

void Entity::handle_wall_collision(std::shared_ptr<Wall> wall)
{
    float x_pos_difference{coordinates.x - wall->get_coordinates().x};
    float y_pos_difference{coordinates.y - wall->get_coordinates().y};
        
    if(std::abs(x_pos_difference) < std::abs(y_pos_difference))
    {
        sf::Vector2f new_pos{coordinates.x, wall->get_coordinates().y};
        if(y_pos_difference > 0)
            new_pos.y += height / 2 + wall->get_height() / 2;
        else
            new_pos.y -= height / 2 + wall->get_height() / 2;
        coordinates = new_pos;
    }
    else
    {
        sf::Vector2f new_pos{wall->get_coordinates().x, coordinates.y};
        if(x_pos_difference > 0)
            new_pos.x += width / 2 + wall->get_width() / 2;
        else
            new_pos.x -= width / 2 + wall->get_width() / 2;
        coordinates = new_pos;
    }
    hitbox.setPosition(coordinates);
}

void Entity::rotate(sf::Vector2f& direction)
{
    float angle = std::atan2(direction.y - coordinates.y, direction.x - coordinates.x);
    angle = angle * 180 /  M_PI;

    rotation = angle;
}


void Entity::draw()
{
    // Set the position and rotation when initializing the sprite
    sprite.setPosition(coordinates);
    sprite.setRotation(rotation + 90.0);

    // Draw the sprite
    window.draw(sprite);
}


sf::Vector2f Entity::check_boundury_collision(sf::Vector2f & direction, double const distance_to_move)
{
    float new_x = coordinates.x + direction.x * distance_to_move;
    float new_y = coordinates.y + direction.y * distance_to_move;

    if (new_x - (width / 2) >= 0 && new_x + (width / 2) <= window_size.x)
        coordinates.x = new_x;

    if (new_y - (height / 2) >= 0 && new_y + (height / 2) <= window_size.y)
        coordinates.y = new_y;

    return coordinates;
}


bool Entity::is_dead()
{
    return dead;
}


void Entity::set_speed(int const new_speed)
{
    speed = new_speed;
}


void Entity::set_texture(sf::Texture const& new_texture)
{
    sprite.setTexture(new_texture);
}


void Entity::set_attack_speed(double const new_speed)
{
    attack_cooldown = new_speed;
}


bool Entity::can_attack() const
{
    return time_since_last_attack >= attack_cooldown;
}


void Entity::take_damage(int damage_to_take)
{
    health_points -= damage_to_take;

    sprite.setColor(sf::Color(255, 0, 0));

    damage_effect_timer.restart();

    if(health_points <= 0)
    {
        sprite.setColor(sf::Color::White);
        dead = true;
    }
}

void Entity::set_enemies(std::vector<std::shared_ptr<Enemy>>& enemies)
{
    loaded_enemies = &enemies;
}