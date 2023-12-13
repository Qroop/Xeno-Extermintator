#include "game_engine.h"
#include "abstract_game_state.h"
#include "play_state.h"
// #include "menu_state.h"
#include "game_over_state.h"

#include <string>
#include <array>
#include <memory>
#include <iostream>

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
    while (!stop)
    {
        stop = true;
        sf::RenderWindow window{sf::VideoMode{1024, 1024}, "W40k Game"};
        window.setKeyRepeatEnabled(true);
        window.setVerticalSyncEnabled(true);

        std::array<std::string, 3> levels = {"level_1.txt", "level_2.txt", "level_3.txt"};
        states[0] = std::make_shared<Play_State> (window);
        // std::cerr << "we trynna get in bby";
        states[1] = std::make_shared<Game_Over_State> (window, levels.size() );
        std::shared_ptr<Play_State> current_level = std::static_pointer_cast<Play_State>(states[0]);
        sf::Clock clock;

        for (std::string & current_map : levels)
        {
            current_level -> load(current_map);
            sf::Event event;
            if ( running )
            {
                std::cout << current_map << std::endl;
                int to_stop{while_running(event, window, clock, states)};
                if (to_stop == 2)
                {
                    break;
                }
            }
            else{ break; }
        }
    }
}

int Game_Engine::while_running(sf::Event & event, 
                                sf::RenderWindow & window, 
                                sf::Clock & clock, 
                                std::array<std::shared_ptr<Abstract_Game_State>, 2>& states)
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
        
        int the_change = states[active_state]->get_change();
        if( !running || sf::Keyboard::isKeyPressed(sf::Keyboard::Q) )
        {
            return 0;
        }
        //next level
        else if( active_state == 1 && the_change == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            change_state(0, true);
            return 1;
        }
        //restart
        else if( active_state == 1 && the_change == 3 && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            change_state(0, true);
            stop = false;
            return 2;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5))
        {
            std::cout << "numpad 5 pressed" << std::endl;
            std::shared_ptr<Play_State> play_state = std::static_pointer_cast<Play_State> (states[0]);
            play_state -> set_player_dead();
        }

        double delta_time{clock.restart().asSeconds()};

        //updates the window
        states[active_state] -> update(delta_time);
        
        sf::Color grey(150, 150, 150);
        window.clear(grey);

        states[active_state] -> render();

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
    return 0;
}



void Game_Engine::change_state(int index, bool win)
{
    active_state = index;
    if ( index == 1 )
    {
        std::shared_ptr<Game_Over_State> game_over = std::static_pointer_cast<Game_Over_State>(states[1]);
        game_over -> set_status( win );
    }
} 