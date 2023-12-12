#include "projectile.h"
#include "enemy.h"
#include "game_object.h"

#include "SFML/Graphics.hpp"

Projectile::Projectile(sf::Vector2f coordinates, sf::Texture& texture, int health_points, int damage, int speed, int window_width, int window_height, Game_Object& player)
: Enemy(coordinates, texture, health_points, damage, speed, window_width, window_height, player)
{

}


Projectile::~Projectile() {}


void Projectile::update(double delta_time)
{

}


void Projectile::attack() const
{
    
    player.take_damage(damage);
}