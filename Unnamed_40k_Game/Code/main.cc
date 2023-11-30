#include <SFML/Graphics.hpp>

const size_t width = 1024;
const size_t height = 1024;

int main()
{
    sf::RenderWindow window{sf::VideoMode{width, height}, "Demo"};

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Handle game logic and update here

        window.clear(); // Clear the window

        // Draw your game objects here

        window.display(); // Display the contents of the window
    }

    return 0;
}