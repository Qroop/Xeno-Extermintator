#include "classes.h"

#include <SFML/Window/Mouse.hpp>
#include <cmath>

Entity::Entity(sf::Vector2f coordinates, int health_points, int damage, int speed)
: Game_Object(coordinates), health_points(health_points), damage(damage), speed(speed) {}


Entity::~Entity() {}

void Entity::draw(sf::RenderWindow& window)
{
    hitbox.setPosition(coordinates);
    hitbox.setRotation(rotation);
    window.draw(hitbox);
}