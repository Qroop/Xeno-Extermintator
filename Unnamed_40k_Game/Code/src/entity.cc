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