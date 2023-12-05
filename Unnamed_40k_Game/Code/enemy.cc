#include "classes.h"
#include "standard.h"

Enemy::Enemy(sf::Vector2f coordinates, int health_points, int damage, int speed, Player& player)
: Entity(coordinates, health_points, damage, speed), player{player}
{
    /*To Do
    1. Set the color of the hitbox to something else
    2. Set the playerpointer to the player*/
    hitbox.setFillColor(sf::Color(100, 250, 50));
}

// void Enemy::update(double delta_time, sf::RenderWindow& window, size_t window_width, size_t window_height)
// {
//     cout << delta_time << 
// }