#include "standard.h"
#include "point.h"
#include "player.h"
#include "grunt.h"

#include <cmath>
#include <ctime>
#include <cstdlib>
#include <random>

Grunt::Grunt(sf::Vector2f coordinates, sf::Texture& texture, int health_points, int damage, int speed, Game_Object& player)
    : Enemy(coordinates, texture, health_points, damage, speed, player)
{
    rotation = 0;
    // Initialize the random number generator seed
    srand(coordinates.x);
    int max_distance{350};
    int min_distance{250};
    distance_to_keep = (std::rand() % (max_distance - min_distance + 1) + min_distance);
    
    // double max_time_since_attack{1.0};
    // double min_time_since_attack{0.0};
    // time_since_last_attack = (std::rand() % (max_time_since_attack - min_time_since_attack + 1) + min_time_since_attack);

    walk_left = rand() % 2 == 0;
    rotation_speed = 65;
}

Grunt::~Grunt() {}


double Grunt::get_distance_to_player()
{
    sf::Vector2f offset_from_player{coordinates.x - player.get_coordinates().x, coordinates.y - player.get_coordinates().y};
    double distance_to_player{length(offset_from_player)};

    return distance_to_player;
}


void Grunt::update(double delta_time, size_t window_width, size_t window_height)
{
    
    sf::Vector2f player_coordinates{player.get_coordinates()};
    rotate(player_coordinates, delta_time);
    move(delta_time, window_width, window_height);
    hitbox.setPosition(coordinates);

    time_since_last_attack += delta_time;
    double desired_rotation = std::atan2(player_coordinates.y - coordinates.y, player_coordinates.x - coordinates.x) * (180.0 / M_PI);
    // std::cerr << "Rotation : " << rotation << " Desired rotation : " << desired_rotation << "\n";

    if(std::abs(shortest_angular_distance(rotation, desired_rotation)) < 20 && get_distance_to_player() > 80 && can_attack())
    {
        attack();
    }
}


sf::Vector2f Grunt::get_lateral_direction() const
{
    // Get the current lateral direction based on the rotation angle
    double radians = rotation * (M_PI / 180.0);
    return sf::Vector2f(-std::sin(radians), std::cos(radians));
}


void Grunt::move(double delta_time, size_t window_width, size_t window_height)
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
    coordinates = check_boundury_collision(direction, distance_to_move, window_width, window_height);
}

void Grunt::attack() const
{

}