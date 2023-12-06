#include "enemy.h"
#include "player.h"

#include "standard.h"

Enemy::Enemy(sf::Vector2f coordinates, int health_points, int damage, int speed, Player& player)
: Entity(coordinates, health_points, damage, speed), player{player}
{
    hitbox.setFillColor(sf::Color(100, 250, 50));
}

Enemy::~Enemy() {}