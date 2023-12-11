#include "game_engine.h"
#include "abstract_game_state.h"
#include "play_state.h"
#include "menu_state.h"
#include "game_over_state.h"

#include <string>
#include <array>
#include <memory>

Game_Engine::Game_Engine()
: states{}, running{true}, active_state{0} {}

Game_Engine::~Game_Engine()
{
    // if( !states[0] )
    // {
    //     for (std::shared_ptr<Abstract_Game_State> i : states)
    //     {
    //         states.;
    //     }
    // }
}

void Game_Engine::run()
{

    sf::RenderWindow window{sf::VideoMode{1024, 1024}, "W40k Game"};
    window.setKeyRepeatEnabled(true);
    window.setVerticalSyncEnabled(true);

    std::array<std::string, 3> levels = {"level_1.txt", "level_2.txt", "level_3.txt"};
    // states[0] = new Menu_State;
    states[0] = std::make_shared<Abstract_Game_State> (Play_State());
    states[1] = std::make_shared<Abstract_Game_State> (Game_Over_State( levels.size() ));
    std::shared_ptr<Play_State> current_level = std::make_shared<Play_State> (states[0]);
    sf::Clock clock;

    for (std::string & i : levels)
    {
        current_level -> load(i, window);
        sf::Event event;
        if ( running )
        {
            while_running(event, window, clock, states, current_level);
        }
        else{ break; }
    }
}


void Game_Engine::while_running(sf::Event & event, 
                                sf::RenderWindow & window, 
                                sf::Clock & clock, 
                                std::array<std::shared_ptr<Abstract_Game_State>, 2>& states, 
                                std::shared_ptr<Play_State> play_state)
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

        double delta_time{clock.restart().asSeconds()};

        //updates the window
        states[active_state] -> update(delta_time, window, window.getSize().x, window.getSize().y);
        window.clear();
        states[active_state] -> render(window);
        window.display();
        if ( active_state == 0 && states[active_state] -> get_change() == 1)
        {
            change_state(1, true);
        }
        else if ( active_state == 0 && states[active_state] -> get_change() == 2 )
        {
            change_state(1, false);
        }
    }
}



void Game_Engine::change_state(int index, bool win)
{
    active_state = index;
    if ( index == 1 )
    {
        auto game_over = std::make_shared<Game_Over_State>(states[1]);
        game_over -> set_win( win );
    }
}