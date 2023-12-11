#pragma once
#include "abstract_game_state.h"

#include <array>
#include <SFML/Window/Event.hpp>

class Game_Engine
{
public:
    Game_Engine();
    ~Game_Engine();

    void run();
    void while_running(sf::Event & event, sf::RenderWindow & window, sf::Clock & clock, std::array<Abstract_Game_State*, 3>& states, Play_State* play_state);
    void quit();
    void change_state(int index);
    int get_state();

private:
    std::array<Abstract_Game_State*, 3> states;
    bool running;
    int active_state;
};
