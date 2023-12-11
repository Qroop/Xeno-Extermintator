#include "enemy.h"
#include "player.h"
#include "standard.h"

#include <SFML/Graphics.hpp>
#include <cmath>


Enemy::Enemy(sf::Vector2f coordinates, sf::Texture& texture, sf::Texture& dead_texture, sf::RenderWindow& window, int health_points, int damage, int speed, Game_Object& player)
: Entity(coordinates, texture, window, health_points, damage, speed), player{player}, dead_texture{dead_texture}
{
    hitbox.setFillColor(sf::Color(100, 250, 50));
}

Enemy::~Enemy() {}


double Enemy::shortest_angular_distance(double from, double to) const
{
    double distance = to - from;
    if (distance > 180.0)
        return distance - 360.0;
    else if (distance < -180.0)
        return distance + 360.0;
    else
        return distance;
}


void Enemy::rotate(sf::Vector2f& direction, double delta_time)
{
    double desired_rotation = std::atan2(direction.y - coordinates.y, direction.x - coordinates.x) * (180.0 / M_PI);
    double rotation_difference{shortest_angular_distance(rotation, desired_rotation)};

    // Förhindra att fienden roterar för mycket
    if (std::abs(rotation_difference) > rotation_speed * delta_time)
    {
        rotation_difference = (rotation_difference > 0) ? rotation_speed * delta_time : -rotation_speed * delta_time;
    }

    rotation += rotation_difference;
}


void Enemy::set_rotation_speed(double new_rotation_speed)
{
    rotation_speed = new_rotation_speed;
}