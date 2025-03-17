#pragma once

#include "abstract_game_state.h"
#include <SFML/Graphics.hpp>
#include <array>

/**
 * @class Game_Over_State
 * @brief Represents the game state when the game is over, derived from Abstract_Game_State.
 */
class Game_Over_State : public Abstract_Game_State
{
    public:
    /**
     * @brief Constructor for the Game_Over_State class.
     * @param window The render window for the game.
     * @param level_count The total number of levels in the game.
     */
    Game_Over_State(sf::RenderWindow& window, int level_count);

    /**
     * @brief Destructor for the Game_Over_State class.
     */
    ~Game_Over_State();

    /**
     * @brief Updates the game over state over time.
     * @param delta_time The time elapsed since the last update.
     */
    void update(double const delta_time) override;

    /**
     * @brief Renders the game over state.
     */
    void render() override;

    /**
     * @brief Sets the win/lose status of the game.
     * @param win True if the player won, false if they lost.
     */
    void set_status(bool const win);

    /**
     * @brief Gets the change in the game state.
     * @return The change in the game state.
     */
    int get_change() const override;

    /**
     * @brief Handles decision-making logic for the game over state.
     */
    void decision_handling();

    private:
    int level_count; ///< The total number of levels in the game.
    int current_level_index; ///< The index of the current level.
    int decision; ///< The decision made by the player.
    sf::Font font; ///< The font used for rendering text.
    std::string instructions; ///< Instructions displayed on the screen.
    std::array<sf::Text, 4> text; ///< Array of texts for rendering different options.
    sf::Vector2f upper_text_size; ///< Size of upper text elements.
    sf::Vector2f lower_text_size; ///< Size of lower text elements.
};

