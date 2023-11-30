#include "classes.h"
#include <SFML/Window/Keyboard.hpp>

 Player::move() 
{
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::W) )
        coordinates.y += 1;

    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
        coordinates.x -= 1;

    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::S) )
        coordinates.y -= 1;

    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::D) )
        coordinates.x += 1;
}


