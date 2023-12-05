#include "enemy.h"

Enemy::Enemy(sf::Vector2f coordinates, 
            double width, 
            double height, 
            int health_points,
            int damage,
            int speed)
: Entity(coordinates, width, height, health_points, damage, speed)
{}

