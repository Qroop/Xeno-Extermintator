#pragma once

#include "game_object.h"
#include <SFML/Graphics.hpp>

/**
 * @class Wall
 * @brief Represents a wall in the game, derived from Game_Object.
 */

class Wall : public Game_Object
{
    public:
    /**
     * @brief Constructor for the Wall class.
     * @param coordinates The initial coordinates of the wall.
     * @param texture The texture used for rendering the wall.
     * @param window The render window where the wall will be drawn.
     */
    Wall(sf::Vector2f coordinates, sf::Texture& texture, sf::RenderWindow& window);

    /**
     * @brief Destructor for the Wall class.
     */
    ~Wall();
};