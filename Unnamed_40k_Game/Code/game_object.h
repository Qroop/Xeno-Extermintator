#pragma once
#include <SFML/Graphics.hpp>

class Game_Object
{
    public:
    Game_Object(sf::Vector2f coordinates, 
            double width = 32, 
            double height = 32); 
            // const std::string& texture_path = "../Static/missing.png");
    virtual ~Game_Object() = 0;

    sf::Vector2f get_coordinates() const;
    double get_height() const;
    double get_width() const;
    void draw(sf::RenderWindow& window);
    virtual void render(sf::RenderWindow & window) = 0;

    protected:
    sf::Vector2f coordinates;
    double width;
    double height;
    sf::RectangleShape hitbox;
    sf::Texture texture;
};