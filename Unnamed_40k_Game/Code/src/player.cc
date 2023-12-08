#include "player.h"
#include "point.h"
#include "standard.h"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <cmath>
#include <iostream>


Player::Player(sf::Vector2f coordinates, sf::Texture& texture, int health_points, int damage, int speed)
    : Entity(coordinates, texture, health_points, damage, speed)
{
    texture_scale = 3;
    width = width * texture_scale / 2;
    height = height * texture_scale / 2;
    
    // Set the sprite scale
    sprite.setScale(texture_scale, texture_scale);

    // Set the hitbox size and position (considering scaling)
    hitbox.setSize(sf::Vector2f(width, height));
    hitbox.setOrigin(width / 2.0f, height / 2.0f);  // Set the origin at the center
    hitbox.setPosition(coordinates);
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
    double distance_to_move{speed * delta_time};

    coordinates = check_boundury_collision(direction, distance_to_move, window_width, window_height);
}


void Player::update(double delta_time, sf::RenderWindow& window, size_t window_width, size_t window_height)
{
    sf::Vector2f mouse_position{sf::Mouse::getPosition(window)};
    rotate(mouse_position);
    move(delta_time, window_width, window_height);
    hitbox.setPosition(coordinates);
}