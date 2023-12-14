#pragma once
#include "abstract_game_state.h"
#include "play_state.h"

#include <array>
#include <SFML/Window/Event.hpp>

/**
 * @brief The main game engine class.
 * 
 * This class manages the game loop and state transitions.
 */
class Game_Engine
{
    public:
    /**
     * @brief Constructor for the Game_Engine class.
     */
    Game_Engine();

    /**
     * @brief Destructor for the Game_Engine class.
     */
    ~Game_Engine();

    /**
     * @brief Run the game engine.
     * 
     * This function starts and manages the main game loop.
     */
    void run();

    /**
     * @brief Main loop for handling events and updating the game state.
     * 
     * @param event Reference to the SFML Event.
     * @param window Reference to the SFML RenderWindow.
     * @param clock Reference to the SFML Clock.
     * @param states Array of shared pointers to Abstract_Game_State objects.
     * @return An integer representing the next active state index.
     */
    int while_running(sf::Event & event, sf::RenderWindow & window, sf::Clock & clock, std::array<std::shared_ptr<Abstract_Game_State>, 2>& states);

    /**
     * @brief Change the active game state.
     * 
     * @param index Index of the new active game state.
     * @param win_or_lose Indicates whether the game was won or lost (used for specific state transitions).
     */
    void change_state(int const index, bool const win_or_lose);

    private:
    /**
     * @brief Array of shared pointers to Abstract_Game_State objects representing different game states.
     */
    std::array<std::shared_ptr<Abstract_Game_State>, 2> states;

    /**
     * @brief Flag indicating whether the game engine is running.
     */
    bool running;

    /**
     * @brief Flag indicating whether the game engine should stop.
     */
    bool stop;

    /**
     * @brief Index of the currently active game state.
     */
    int active_state;
};
