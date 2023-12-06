#include "entity.h"

#include <SFML/Window/Mouse.hpp>
#include <cmath>

Entity::Entity(sf::Vector2f coordinates, int health_points, int damage, int speed)
: Game_Object(coordinates), health_points(health_points), damage(damage), speed(speed) {}


Entity::~Entity() {}


void Entity::rotate(sf::Vector2f& direction)
{
    float angle = std::atan2(direction.y - coordinates.y, direction.x - coordinates.x);
    angle = angle * 180 /  3.14159265;

    rotation = angle;
}


void Entity::draw(sf::RenderWindow& window)
{
    hitbox.setPosition(coordinates);
    hitbox.setRotation(rotation);
    window.draw(hitbox);
}