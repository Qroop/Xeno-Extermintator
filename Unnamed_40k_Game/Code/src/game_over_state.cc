#include "game_over_state.h"

#include <iostream>
#include <cmath>

Game_Over_State::Game_Over_State(sf::RenderWindow& window ,int level_count)
: Abstract_Game_State{window}, level_count{level_count}
{
    if (!font.loadFromFile("../Static/Textures/arial.ttf") )
    {
        
        throw std::invalid_argument("failed to load font");
    }
    
    text[0] = sf::Text{"You\'ve won!", font};
    text[1] = sf::Text{"You\'ve cleared the level!", font};
    text[2] = sf::Text{"You Lose!", font};
    text[3] = sf::Text{instructions, font};
    for ( int i = 0 ; i < 3 ; i++ )
    {
        text[i].setCharacterSize(60);
    }

    current_level_index = 1;

}

Game_Over_State::~Game_Over_State()
{}

void Game_Over_State::update(double delta_time)
{
    window.clear();

    decision_handling();
}

void Game_Over_State::render()
{
    window.draw( text[decision-1] );
    window.draw( text[3] );
}



void Game_Over_State::set_status( bool win )
{
    if ( win && level_count == current_level_index )
    {
        decision = 1;
        instructions = "Press Esc to exit.";
    }
    else if( win )
    {
        decision = 2;
        instructions = "Press SPACE to continue or Esc to exit.";
        current_level_index++;
    }
    else if( !win )
    {
        decision = 3;
        instructions = "Press SPACE to restart or Esc to exit.";
    }
}

void Game_Over_State::decision_handling()
{
    upper_text_size = sf::Vector2f{(window.getSize().x / 2) - text[decision-1].getGlobalBounds().width / 2, (window.getSize().y / 2) - text[decision-1].getGlobalBounds().height / 2};
    upper_text_size.y -= 30;
    text[decision-1].setPosition(upper_text_size);
    text[3].setString(instructions);
    lower_text_size = sf::Vector2f{(window.getSize().x / 2) - text[3].getGlobalBounds().width / 2, (window.getSize().y / 2) - text[3].getGlobalBounds().height / 2};
    lower_text_size.y += 30;
    text[3].setPosition(lower_text_size);
}

int Game_Over_State::get_change()
{
    return decision;
}