#include "classes.h"

#include <SFML/Window/Mouse.hpp>
#include <cmath>

Entity::Entity(sf::Vector2f coordinates, double width, double height, int health_points, int damage, int speed)
: Game_Object(coordinates, width, height), health_points(health_points), damage(damage), speed(speed) {}


Entity::~Entity() {}

void Entity::draw(sf::RenderWindow& window)
{
    hitbox.setPosition(coordinates);
    hitbox.setRotation(rotation);
    window.draw(hitbox);
}