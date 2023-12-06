#include "classes.h"
#include "standard.h"

#include <cmath>

Grunt::Grunt(sf::Vector2f coordinates, int health_points, int damage, int speed, Player& player)
: Enemy(coordinates, health_points, damage, speed, player)
{

}

Grunt::~Grunt() {}

void Grunt::update(double delta_time, size_t window_width, size_t window_height)
{
    /*Grunt to do
    1. Find the players coordinates
    2. Look at it
    3. Move towards it*/
    sf::Vector2f player_coordinates{player.get_coordinates()};
    cout << player_coordinates.x << " : " << player_coordinates.y << endl;
    rotate(player_coordinates);
    cout << delta_time << window_width << window_height << endl;
}

void Grunt::move(double delta_time, size_t window_width, size_t window_height)
{
    /*Move To Do
    1. Cal*/
    double radians = rotation * (M_PI / 180.0);

    double horizontal_component = speed * cos(radians);
    double vertical_component = speed * sin(radians);

    // Update object's coordinates based on the components
    coordinates.x += horizontal_component * delta_time * speed;
    coordinates.y += vertical_component * delta_time * speed;
}