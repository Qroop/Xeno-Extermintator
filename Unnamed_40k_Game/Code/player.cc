#include "classes.h"
#include <SFML/Window/Keyboard.hpp>

sf::Vector2f Player::move() 
{
    sf::Vector2f coordinates{0.0f, 0.0f};
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::W) )
        coordinates.y += 1;

    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
        coordinates.x -= 1;

    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::S) )
        coordinates.y -= 1;

    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::D) )
        coordinates.x += 1;
    return coordinates;
}


