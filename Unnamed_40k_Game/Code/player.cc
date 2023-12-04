#include "classes.h"
#include "point.h"
#include "standard.h"

#include <SFML/Window/Keyboard.hpp>
#include <iostream>


Player::Player(sf::Vector2f coordinates, double width, double height, int health_points, int damage, int speed)
: Entity(coordinates, width, height, health_points, damage, speed)
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

    //std::cout << "Direction: (" << direction.x << ", " << direction.y << ")\n";

    return normalize(direction);
}


void Player::move(double delta_time)
{
    sf::Vector2f direction = find_direction();
    coordinates.x += direction.x * speed * delta_time;
    coordinates.y += direction.y * speed * delta_time;
    
    std::cout << direction << std::endl;
    // std::cout << "Position: (" << coordinates.x << ", " << coordinates.y << ")\n";
}


void Player::update(double delta_time)
{
    move(delta_time);
}