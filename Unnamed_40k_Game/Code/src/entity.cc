#include "entity.h"

#include <iostream>
#include <SFML/Window/Mouse.hpp>
#include <cmath>

Entity::Entity(sf::Vector2f coordinates, sf::Texture& texture, int health_points, int damage, int speed)
: Game_Object(coordinates, texture), health_points(health_points), damage(damage), speed(speed) 
{
    dead = false;
}


Entity::~Entity() {}


void Entity::rotate(sf::Vector2f& direction)
{
    float angle = std::atan2(direction.y - coordinates.y, direction.x - coordinates.x);
    angle = angle * 180 /  3.14159265;

    rotation = angle;
}


void Entity::draw(sf::RenderWindow& window)
{
    // Set the position and rotation when initializing the sprite
    sprite.setPosition(coordinates);
    sprite.setRotation(rotation + 90.0);

    // Draw the sprite
    //window.draw(hitbox);
    window.draw(sprite);
}


sf::Vector2f Entity::check_boundury_collision(sf::Vector2f direction, double distance_to_move, size_t window_width, size_t window_height)
{
    float new_x = coordinates.x + direction.x * distance_to_move;
    float new_y = coordinates.y + direction.y * distance_to_move;

    if (new_x - (width / 2) >= 0 && new_x + (width / 2) <= window_width)
        coordinates.x = new_x;

    if (new_y - (height / 2) >= 0 && new_y + (height / 2) <= window_height)
        coordinates.y = new_y;

    return coordinates;
}


bool Entity::is_dead()
{
    return dead;
}


void Entity::set_speed(int new_speed)
{
    speed = new_speed;
}


void Entity::set_texture(sf::Texture& new_texture)
{
    sprite.setTexture(new_texture);
}


void Entity::set_attack_speed(double new_cooldown)
{
    attack_cooldown = new_cooldown;
}


bool Entity::can_attack() const
{
    return time_since_last_attack >= attack_cooldown;
}


void Entity::take_damage(int damage_to_take)
{
    std::cerr << "Damage taken: " << damage_to_take << " Health left: " << health_points <<"\n";
    health_points -= damage_to_take;

    if(health_points <= 0)
    {
        dead = true;
    }
}

void Entity::set_enemies(std::vector<std::unique_ptr<Enemy>>& enemies)
{
    loaded_enemies = &enemies;
}