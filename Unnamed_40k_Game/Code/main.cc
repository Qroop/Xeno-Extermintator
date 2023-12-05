#include "point.h"
#include "standard.h"
#include "classes.h"

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

const size_t window_width = 1024;
const size_t window_height = 1024; //1024

int main()
{
    sf::RenderWindow window{sf::VideoMode{window_width, window_height}, "Demo"};

    window.setKeyRepeatEnabled(true);
    window.setVerticalSyncEnabled(true);

    Player player(sf::Vector2f(window_width / 2, window_height / 2), 10, 10, 300);
    Enemy enemy(sf::Vector2f(900, 900), 10, 10, 10, player);

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

        // Handle game logic and update here
        player.update(clock.restart().asSeconds(), window, window_width, window_height);
        
        window.clear(); // Clear the window

        // Draw your game objects here
        player.draw(window);

        window.display();
    }

    return 0;
}