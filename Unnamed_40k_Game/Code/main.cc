#include "point.h"
#include "standard.h"
#include "classes.h"
#include "play_state.h"

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

const size_t width = 1024;
const size_t height = 1024; //1024

int main()
{
    // sf::RenderWindow window{sf::VideoMode{width, height}, "Demo"};

    // window.setKeyRepeatEnabled(true);
    // window.setVerticalSyncEnabled(true);

    // Player player(sf::Vector2f(width / 2, height / 2), 32, 32, 10, 10, 200);
    // sf::Clock clock;

    // bool quit = false;
    // while (!quit)
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         switch(event.type)
    //         {
    //             case sf::Event::Closed:
    //                 quit = true;
    //                 break;
    //             default:
    //                 break;
    //         }
    //     }

    //     if(quit || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    //     {
    //         break;
    //     }

    //     // Handle game logic and update here
    //     player.update(clock.restart().asSeconds());
        
    //     window.clear(); // Clear the window

    //     // Draw your game objects here
    //     player.draw(window);

    //     window.display();
    // }

    Play_State object{};
    object.load("level_1.txt");
    object.render();

    return 0;
}