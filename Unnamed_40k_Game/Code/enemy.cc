#include "classes.h"

Enemy::Enemy(sf::Vector2f coordinates)
: Entity(coordinates, width, height, health_points, damage, speed)
{}