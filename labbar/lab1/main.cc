#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window{sf::VideoMode (1000, 1000), "Hello World!"};

    // sf::sleep(sf::seconds(5));

    bool quit{false};
    sf::Event event;

    while(window.waitEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
            quit = true;
            break;
            
            default:
                std::cout << "Event: " << event.type << std::endl;
                break;
        }

        if(quit)
        {
            break;
        }
    }
    
    return 0;
}