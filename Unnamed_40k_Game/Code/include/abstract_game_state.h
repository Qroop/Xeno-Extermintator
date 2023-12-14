#pragma once

#include <SFML/Graphics.hpp>

/**
 * @brief Abstract base class for game states.
 * 
 * This class defines the common interface for different game states.
 */
class Abstract_Game_State
{
    public:
    /**
     * @brief Constructor for Abstract_Game_State.
     * 
     * @param window Reference to the SFML RenderWindow.
     */
    Abstract_Game_State(sf::RenderWindow& window);

    /**
     * @brief Destructor for Abstract_Game_State.
     */
    ~Abstract_Game_State();

    /**
     * @brief Update function to be implemented by derived classes.
     * 
     * This function is called to update the state of the game.
     * 
     * @param delta_time Time elapsed since the last update.
     */
    virtual void update(double const delta_time) = 0;

    /**
     * @brief Render function to be implemented by derived classes.
     * 
     * This function is called to render the game state.
     */
    virtual void render() = 0;

    /**
     * @brief Get the change in game state.
     * 
     * @return An integer representing the change in game state.
     */
    virtual int get_change() const = 0;

    protected:
    /**
     * @brief Reference to the SFML RenderWindow.
     */
    sf::RenderWindow& window;
};