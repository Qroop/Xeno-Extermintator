#include "grunt.h"
#include "point.h"
#include "player.h"
#include "projectile.h"
#include "wall.h"

#include <cmath>
#include <ctime>
#include <cstdlib>
#include <random>
#include <SFML/Graphics.hpp>
#include <iostream>

Grunt::Grunt(sf::Vector2f coordinates, 
        sf::Texture& texture,
        sf::RenderWindow& window, 
        sf::Texture& projectile_texture,
        int health_points, int damage, int speed,
        Game_Object& player,
        double rotation)
    : Enemy(coordinates, texture, window, health_points, damage, speed, player, rotation), projectile_texture{projectile_texture}
{
    rotation = 0;
    srand(coordinates.x + coordinates.y * 100000);
    int max_distance{500};
    int min_distance{350};
    distance_to_keep = (std::rand() % (max_distance - min_distance + 1) + min_distance);
    
    time_since_last_attack = static_cast<float>(std::rand() % 3000) / 1000;
    attack_cooldown = 3;
    walk_left = rand() % 2 == 0;
    rotation_speed = 50;
}

Grunt::~Grunt() {}


double Grunt::get_distance_to_player()
{
    sf::Vector2f offset_from_player{coordinates.x - player.get_coordinates().x, coordinates.y - player.get_coordinates().y};
    double distance_to_player{length(offset_from_player)};

    return distance_to_player;
}


void Grunt::update(double delta_time)
{
    
    sf::Vector2f player_coordinates{player.get_coordinates()};
    rotate(player_coordinates, delta_time);
    move(delta_time);
    hitbox.setPosition(coordinates);

    double desired_rotation = std::atan2(player_coordinates.y - coordinates.y, player_coordinates.x - coordinates.x) * (180.0 / M_PI);

    time_since_last_attack += delta_time;
    if(std::abs(shortest_angular_distance(rotation, desired_rotation)) < 20 && get_distance_to_player() > 80 && can_attack())
    {
        attack();
        time_since_last_attack = 0;
    }

    if(damage_effect_timer.getElapsedTime() < damage_effect_duration)
    {
        sprite.setColor(sf::Color(255, 0, 0));
    }
    else
    {
        sprite.setColor(sf::Color::White);
    }
}


sf::Vector2f Grunt::get_lateral_direction() const
{
    double radians = rotation * (M_PI / 180.0);
    return sf::Vector2f(-std::sin(radians), std::cos(radians));
}


void Grunt::move(double delta_time)
{
    double distance_to_move{delta_time * speed};
    double distance_to_player{get_distance_to_player()};
    sf::Vector2f offset_from_player{coordinates.x - player.get_coordinates().x, coordinates.y - player.get_coordinates().y};

    sf::Vector2f direction;

    if (distance_to_player < distance_to_keep)
    {
        direction = normalize(offset_from_player);
    }
    else if (distance_to_player >= distance_to_keep)
    {
        /*Randomly walk left and right*/
        if (rand() % 40 == 0) // 2.5% chance to switch direction every tick
        {
            walk_left = !walk_left;
        }

        sf::Vector2f forward_direction = -normalize(offset_from_player);
        sf::Vector2f lateral_direction = walk_left ? -get_lateral_direction() : get_lateral_direction();

        direction = forward_direction + lateral_direction;
    }
    coordinates = check_boundury_collision(direction, distance_to_move, window_size.x, window_size.y);
}


void Grunt::attack() const
{
    /*Spawn a projectile object in an enemies to add vector*/
    if(!loaded_enemies)
    {
        std::cerr << "Error: Loaded enemies is nullptr\n";
        return;
    }

    auto new_projectile = std::make_shared<Projectile>(coordinates, projectile_texture, window, 1, 1, 200, player, rotation);

    new_projectile -> set_enemies(*loaded_enemies);
    new_projectile -> set_height(16);
    new_projectile -> set_width(16);

    if(!loaded_enemies)
    {
        std::cerr << "Error: Loaded enemies pointer is nullptr";
    }
    loaded_enemies->push_back(new_projectile);

}

void Grunt::handle_collision(std::shared_ptr<Game_Object> collided)
{
    if (std::shared_ptr<Wall> wall = std::dynamic_pointer_cast<Wall>(collided))
    {
        handle_wall_collision(wall);
    }
    else if(std::shared_ptr<Player> player = std::dynamic_pointer_cast<Player>(collided))
    {
        player -> take_damage(damage);
    }
}

void Grunt::kill_entity(sf::Texture& dead_texture)
{
    set_texture(dead_texture);
    set_speed(0);
    set_rotation_speed(0);
    set_attack_speed(0);
}