#include "game_engine.h"
#include "abstract_game_state.h"
#include "play_state.h"
#include "menu_state.h"
#include "game_over_state.h"

#include <string>
#include <array>

Game_Engine::Game_Engine()
: states{}, running{true}, active_state{0} {}

Game_Engine::~Game_Engine()
{
    if( !states[0] )
    {
        for (Abstract_Game_State* i : states)
        {
            delete i;
        }
    }
}

void Game_Engine::while_running(sf::Event & event, sf::RenderWindow & window, sf::Clock & clock, std::array<Abstract_Game_State*, 3>& states)
{
    while ( running )
    {
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                running = false;
                break;
            
            default:
                break;
            }
        }
        
        if( !running || sf::Keyboard::isKeyPressed(sf::Keyboard::Q) )
        {
            break;
        }
        else if ( states[0] -> get_resume() == true && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
        {
            if ( active_state == 0 )
            {
                change_state(1);
            }
            else if ( active_state == 1 )
            {
                change_state(0);
            }
            else
            {
                running = false;
                break;
            }
        }

        double delta_time{clock.restart().asSeconds()};

        //updates the window
        states[active_state] -> update(delta_time, window, window.getSize().x, window.getSize().y);
        window.clear();
        states[active_state] -> render(window);
        window.display();
    }
}

void Game_Engine::run()
{

    sf::RenderWindow window{sf::VideoMode{1024, 1024}, "W40k Game"};
    window.setKeyRepeatEnabled(true);
    window.setVerticalSyncEnabled(true);

    std::array<std::string, 3> levels = {"level_1.txt", "level_2.txt", "level_3.txt"};
    states[0] = new Menu_State;
    states[1] = new Play_State;
    states[2] = new Game_Over_State;
    Play_State* current_level = static_cast<Play_State*> (states[1]);
    sf::Clock clock;

    for (std::string & i : levels)
    {
        current_level -> load(i);
        sf::Event event;
        if ( running )
        {
            Game_Engine::while_running(event, window, clock, states);
        }
        else{ break; }
    }
}

void Game_Engine::change_state(int index)
{
    active_state = index;
}