#include "enemy.h"
#include "player.h"
#include "standard.h"

#include <SFML/Graphics.hpp>
#include <cmath>


Enemy::Enemy(sf::Vector2f coordinates, int health_points, int damage, int speed, Player& player)
: Entity(coordinates, health_points, damage, speed), player{player}
{
    hitbox.setFillColor(sf::Color(100, 250, 50));
}

Enemy::~Enemy() {}


// Calculate the shortest angular distance between two angles in degrees
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

    // Ensure that rotation doesn't overshoot
    if (std::abs(rotation_difference) > rotation_speed * delta_time)
    {
        rotation_difference = (rotation_difference > 0) ? rotation_speed * delta_time : -rotation_speed * delta_time;
    }

    cout << "Rotation difference : " << rotation_difference << endl;
    cout << "Current rotation : " << rotation << endl;
    cout << "Desired rotation : " << desired_rotation << endl;
    cout << "Rotation speed : " << rotation_speed << endl;

    rotation += rotation_difference;
}

