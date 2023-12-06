#pragma once
#include <SFML/Graphics.hpp>

class Game_Object
{
    public:
    Game_Object(sf::Vector2f coordinates); 
    virtual ~Game_Object() = 0;

    sf::Vector2f get_coordinates() const;
    void set_coordinates(sf::Vector2f set_coordinates);
    double get_height() const;
    double get_width() const;
    virtual void draw(sf::RenderWindow& window);

    protected:
    sf::Vector2f coordinates;
    double width;
    double height;
    sf::RectangleShape hitbox;
    sf::Texture texture;
};