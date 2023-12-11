#include "game_over_state.h"

Game_Over_State::Game_Over_State(int level_count)
: level_count{level_count}
{
    font.loadFromFile("../Textures/font.ttf");

    text[0] = sf::Text{"You Win!", font, 60 };
    text[1] = sf::Text{"You've Cleared Level " + (current_level_index+1), font, 60};
    text[2] = sf::Text{"You Lose!", font, 60};
    text[3] = sf::Text{instructions, font, 30};
    for ( int i ; i < 3 ; i++ )
    {
        text[i].setPosition(sf::Vector2f{512, 512});
    }
    text[3].setPosition(sf::Vector2f{512, 572});
}

Game_Over_State::~Game_Over_State()
{}

void Game_Over_State::update(double delta_time, sf::RenderWindow& window, size_t window_width, size_t window_height)
{
    window.clear();

    decision_handling(window);
}


void Game_Over_State::set_win( bool win )
{
    if ( win && level_count == current_level_index )
    {
        decision = 1;
        instructions = "Press Q to exit.";
    }
    else if( win )
    {
        decision = 2;
        instructions = "Press LEFT CLICK to continue or Q to exit.";
        current_level_index++;
    }
    else if( !win )
    {
        decision = 3;
        instructions = "Press LEFT CLICK to restart or Q to exit.";
    }
}

void Game_Over_State::decision_handling(sf::RenderWindow& window)
{
    window.clear();
    window.draw(text[decision-1]);
    window.draw(text[3]);
}

int Game_Over_State::get_change()
{

}