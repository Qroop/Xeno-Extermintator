#include "standard.h"
#include "point.h"
#include "player.h"
#include "grunt.h"

#include <cmath>

Grunt::Grunt(sf::Vector2f coordinates, int health_points, int damage, int speed, Player& player)
: Enemy(coordinates, health_points, damage, speed, player) 
{
    rotation_speed = 55;
}

Grunt::~Grunt() {}


void Grunt::update(double delta_time, size_t window_width, size_t window_height)
{
    sf::Vector2f player_coordinates{player.get_coordinates()};
    rotate(player_coordinates, delta_time);
    move(delta_time, window_width, window_height);
}


void Grunt::move(double delta_time, size_t window_width, size_t window_height)
{
    double distance_to_move{delta_time * speed};

    sf::Vector2f offset_from_player{coordinates.x - player.get_coordinates().x, coordinates.y - player.get_coordinates().y};
    float distance_to_player{length(offset_from_player)};

    float distance_to_keep{300};
    sf::Vector2f direction;

    if (distance_to_player <= distance_to_keep)
    {
        direction = normalize(offset_from_player);
    }
    else if (distance_to_player > distance_to_keep)
    {
        direction = -normalize(offset_from_player);
    }

    coordinates = check_boundury_collision(direction, distance_to_move, window_width, window_height);
}