#pragma once

#include "abstract_game_state.h"
#include <SFML/Graphics.hpp>

class Game_Over_State : public Abstract_Game_State
{
    public:
    Game_Over_State(sf::RenderWindow& window, int level_count);
    ~Game_Over_State();
    
    void update(double delta_time) override;
    void render() override;
    void set_status( bool win );
    int get_change() override;
    void decision_handling();

    private:
    int level_count;
    int current_level_index;
    int decision;
    sf::Font font;
    std::string instructions;
    std::array<sf::Text, 4> text;
    sf::Vector2f upper_text_size;
    sf::Vector2f lower_text_size;
    // sf::RectangleShape test;
    // bool win_or_lose;
};
