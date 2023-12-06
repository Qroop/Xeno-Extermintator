#include "classes.h"
#include "point.h"
#include "standard.h"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <cmath>
#include <iostream>


Player::Player(sf::Vector2f coordinates, int health_points, int damage, int speed)
: Entity(coordinates, health_points, damage, speed)
{
    // sf::Texture texture;
    // texture.loadFromFile("player.png");
}

Player::~Player() {}


sf::Vector2f Player::find_direction() const
{
    sf::Vector2f direction;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        direction.y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        direction.y += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        direction.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        direction.x += 1;

    return normalize(direction);
}


void Player::move(double delta_time, size_t window_width, size_t window_height)
{
    sf::Vector2f direction = find_direction();

    float new_x = coordinates.x + direction.x * speed * delta_time;
    float new_y = coordinates.y + direction.y * speed * delta_time;

    if (new_x - (width / 2) >= 0 && new_x + (width / 2) <= window_width)
        coordinates.x = new_x;
    if (new_y - (height / 2) >= 0 && new_y + (height / 2) <= window_height)
        coordinates.y = new_y;
}


sf::Vector2f Player::find_mouse(sf::RenderWindow& window)
{
    sf::Vector2f mouse_position{sf::Mouse::getPosition(window)};
    return mouse_position;
}


// void Player::rotate(sf::Vector2f& direction)
// {
//     float angle = std::atan2(direction.y - coordinates.y, direction.x - coordinates.x);
//     angle = angle * 180 /  3.14159265;

//     rotation = angle;
// }


void Player::update(double delta_time, sf::RenderWindow& window, size_t window_width, size_t window_height)
{
    sf::Vector2f mouse_coordinates{find_mouse(window)};
    move(delta_time, window_width, window_height);
    rotate(mouse_coordinates);
}