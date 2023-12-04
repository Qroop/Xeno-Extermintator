#include "point.h"
#include "standard.h"

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

float speed{2};

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
const size_t height = 1024; //1024

int main()
{
    sf::RenderWindow window{sf::VideoMode{width, height}, "Demo"};

    window.setKeyRepeatEnabled(true);
    window.setVerticalSyncEnabled(true);

    sf::RectangleShape shape(sf::Vector2f(32.f, 32.f));
    sf::Vector2f location{height / 2, width / 2};

    sf::Clock clock;

    bool quit = false;
    while (!quit)
    {
        sf::Event event;
        //std::cerr << event.type << "\n";
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
        sf::Vector2f direction = find_direction();

        auto delta = clock.restart();
        {
            float distance = 250.0f * delta.asSeconds();
            // if((location + (direction * distance * speed)) > )
            location += direction * distance * speed;

            if((location.x + 32) > width)
                location.x = width - 32;
            if((location.y + 32) > height)
                location.y = height - 32;
            if(location.x < 0)
                location.x = 0;
            if(location.y < 0)
                location.y = 0;

            std::cerr << location.x << " : " << location.y << "\n";
        }

        shape.setPosition(location);

        window.clear(); // Clear the window

        // Draw your game objects here
        window.draw(shape);
        window.display(); // Display the contents of the window
    }

    return 0;
}