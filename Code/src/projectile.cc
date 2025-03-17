#include "projectile.h"
#include "enemy.h"
#include "game_object.h"
#include "wall.h"
#include "player.h"

#include "point.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <cmath>

Projectile::Projectile(sf::Vector2f coordinates, sf::Texture& texture, sf::RenderWindow& window, int health_points, int damage, int speed, Game_Object& player, double rotation)
    : Enemy(coordinates, texture, window, health_points, damage, speed, player, rotation)
{
    double rotation_radians{rotation * (M_PI /180.0)};
    direction_to_move = sf::Vector2f(std::cos(rotation_radians), std::sin(rotation_radians));
    rotation_speed = 10;
}


Projectile::~Projectile() {}


void Projectile::update(double const delta_time)
{
    move(delta_time);
    rotation += rotation_speed;
    hitbox.setPosition(coordinates);
}


void Projectile::attack() const {}


void Projectile::move(double const delta_time)
{
    double distance_to_move{speed * delta_time};
    coordinates.x += direction_to_move.x * distance_to_move;
    coordinates.y += direction_to_move.y * distance_to_move;

    if(coordinates.x - width >= window_size.x || coordinates.x + width <= 0)
    {
        dead = true;
    }
    if(coordinates.y - height >= window_size.y || coordinates.y + height <= 0)
    {
        dead = true;
    }
}


void Projectile::kill_entity(sf::Texture const& dead_texture)
{
    set_texture(dead_texture);
}


void Projectile::handle_collision(std::shared_ptr<Game_Object> collided)
{
    std::shared_ptr<Wall> wall = std::dynamic_pointer_cast<Wall> (collided);
    std::shared_ptr<Player> player = std::dynamic_pointer_cast<Player> (collided);

    if(wall)
    {
        dead = true;
    }
    if(player)
    {
        player -> take_damage(damage);
        dead = true;
    }
}