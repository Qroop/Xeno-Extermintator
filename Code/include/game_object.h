#pragma once

#include <SFML/Graphics.hpp>

/**
 * @class Game_Object
 * @brief Represents a generic game object.
 */
class Game_Object
{
    public:
    /**
     * @brief Constructor for the Game_Object class.
     * @param coordinates The initial coordinates of the game object.
     * @param texture The texture used for rendering the game object.
     * @param window The render window where the game object will be drawn.
     */
    Game_Object(sf::Vector2f coordinates, sf::Texture& texture, sf::RenderWindow& window);

    /**
     * @brief Virtual destructor for the Game_Object class.
     */
    virtual ~Game_Object() = 0;

    /**
     * @brief Gets the coordinates of the game object.
     * @return The coordinates of the game object.
     */
    sf::Vector2f get_coordinates() const;

    /**
     * @brief Sets the coordinates of the game object.
     * @param set_coordinates The new coordinates to set.
     */
    void set_coordinates(sf::Vector2f const& set_coordinates);

    /**
     * @brief Gets the height of the game object.
     * @return The height of the game object.
     */
    double get_height() const;

    /**
     * @brief Gets the width of the game object.
     * @return The width of the game object.
     */
    double get_width() const;

    /**
     * @brief Sets the dimensions of the game object.
     * @param new_dimensions The new dimensions to set.
     */
    void set_dimensions(sf::Vector2f const& new_dimensions);

    /**
     * @brief Draws the game object on the render window.
     */
    virtual void draw();

    /**
     * @brief Gets the global bounding rectangle of the game object.
     * @return The global bounding rectangle of the game object.
     */
    sf::FloatRect get_global_bounds() const;

    protected:
    sf::Vector2f coordinates; ///< The coordinates of the game object.
    double width; ///< The width of the game object.
    double height; ///< The height of the game object.
    sf::RectangleShape hitbox; ///< The hitbox of the game object.
    sf::Texture& texture; ///< The texture used for rendering the game object.
    sf::Sprite sprite; ///< The sprite of the game object.
    sf::RenderWindow& window; ///< The render window where the game object will be drawn.
};
