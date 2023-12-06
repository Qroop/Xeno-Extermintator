#include "standard.h"
#include "point.h"
#include "player.h"
#include "grunt.h"

#include <cmath>

Grunt::Grunt(sf::Vector2f coordinates, int health_points, int damage, int speed, Player& player)
: Enemy(coordinates, health_points, damage, speed, player) {}

Grunt::~Grunt() {}


void Grunt::update(double delta_time, size_t window_width, size_t window_height)
{
    sf::Vector2f player_coordinates{player.get_coordinates()};
    rotate(player_coordinates);
    move(delta_time, window_width, window_height);
}


void Grunt::move(double delta_time, size_t window_width, size_t window_height)
{
    double distance_to_move{delta_time * speed};

    sf::Vector2f offset_from_player{coordinates.x - player.get_coordinates().x, coordinates.y - player.get_coordinates().y};
    float distance_to_player{length(offset_from_player)};

    float distance_to_keep{500};
    if(distance_to_player <= distance_to_keep)
    {
        // Move away from the player
        sf::Vector2f direction = normalize(offset_from_player);
        coordinates.x += direction.x * distance_to_move;
        coordinates.y += direction.y * distance_to_move;
    }
    else if(distance_to_player > distance_to_keep)
    {
        // Move towards the player
        sf::Vector2f direction = normalize(offset_from_player);
        coordinates.x -= direction.x * distance_to_move;
        coordinates.y -= direction.y * distance_to_move;
    }


    // Skriver ut bara för att dem ska användas.
    cout << "it moves" << window_width << window_height <<
    "\n" << "Player coords : " << player.get_coordinates().x << " : " << player.get_coordinates().y << endl;
}