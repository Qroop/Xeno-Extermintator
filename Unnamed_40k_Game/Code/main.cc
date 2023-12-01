#include "point.h"
#include "standard.h"

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>


sf::Vector2f find_direction() {
    sf::Vector2f direction;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        direction.y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        direction.y += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        direction.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        direction.x += 1;

    return normalize(direction);
}


const size_t width = 1024;
const size_t height = 1024;

int main()
{
    sf::RenderWindow window{sf::VideoMode{width, height}, "Demo"};

    window.setKeyRepeatEnabled(true);
    window.setVerticalSyncEnabled(true);

    sf::RectangleShape shape(sf::Vector2f(120.f, 50.f));
    sf::Vector2f location{300, 300};

    bool quit = false;
    while (!quit)
    {
        sf::Event event;
        std::cerr << event.type << "\n";
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

        if(quit)
        {
            break;
        }

        // Handle game logic and update here
        sf::Vector2f direction = find_direction();
        location += direction;
        shape.setPosition(location);

        window.clear(); // Clear the window

        // Draw your game objects here
        window.draw(shape);
        window.display(); // Display the contents of the window
    }

    return 0;
}