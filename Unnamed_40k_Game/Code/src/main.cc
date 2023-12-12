#include "point.h"
#include "standard.h"
#include "play_state.h"
#include "player.h"
#include "grunt.h"

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

const size_t window_width = 1024;
const size_t window_height = 1024; //1024

int main()
{
    sf::RenderWindow window{sf::VideoMode{window_width, window_height}, "Demo"};
    sf::Color white(255, 255, 255);
    window.clear(white);

    window.setKeyRepeatEnabled(true);
    window.setVerticalSyncEnabled(true);

    Play_State level{};
    level.load("level_1.txt", window_width, window_height);
    
    sf::Clock clock;

    bool quit = false;
    while (!quit)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    quit = true;
                    break;
                default:
                    break;
            }
        }

        if(quit || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            break;
        }

        double delta_time{clock.restart().asSeconds()};

        window.clear(white); // Clear the window

        level.update(delta_time, window);

        level.render(window);

        window.display();
    }
    return 0;
}
