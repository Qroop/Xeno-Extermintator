#include "point.h"
#include "standard.h"
#include "play_state.h"
#include "player.h"
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
    Grunt enemy(sf::Vector2f(900, 900), 10, 10, 100, player);

    Play_State level{};
    level.load("level_1.txt");
    
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

        // Handle game logic and update here
        player.update(delta_time, window, window_width, window_height);
        enemy.update(delta_time, window_width, window_height);

        window.clear(); // Clear the window

        // Draw your game objects here
        player.draw(window);
        enemy.draw(window);
        level.render(window);

        window.display();
    }

    // Play_State object{};
    // object.load("level_1.txt");
    // object.render();

    return 0;
}
