#include "standard.h"
#include "point.h"
#include "player.h"
#include "grunt.h"

#include <cmath>
#include <ctime>
#include <cstdlib>
#include <random>

Grunt::Grunt(sf::Vector2f coordinates, sf::Texture& texture, int health_points, int damage, int speed, Player& player)
    : Enemy(coordinates, texture, health_points, damage, speed, player)
{
    // Initialize the random number generator seed
    srand(static_cast<unsigned>(time(nullptr)));
    walk_left = rand() % 2 == 0;
    rotation_speed = 65;
    int max{350};
    int min{200};
    distance_to_keep = std::rand() % (max - min + 1) + min;
}

Grunt::~Grunt() {}


void Grunt::update(double delta_time, size_t window_width, size_t window_height)
{
    sf::Vector2f player_coordinates{player.get_coordinates()};
    rotate(player_coordinates, delta_time);
    move(delta_time, window_width, window_height);
    hitbox.setPosition(coordinates);
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

    sf::Vector2f offset_from_player{coordinates.x - player.get_coordinates().x, coordinates.y - player.get_coordinates().y};
    float distance_to_player{length(offset_from_player)};

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

int Grunt::get_health()
{
    return health_points;
}