#pragma once
#include <SFML/Graphics.hpp>

class Game_Object
{
    public:
    Game_Object(sf::Vector2f coordinates, sf::Texture& texture, sf::RenderWindow& window); // ,sf::Texture& dead_texture); 
    virtual ~Game_Object() = 0;

    virtual void update(double delta_time) = 0;
    virtual bool is_dead() = 0;
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
    sf::Texture* texture;
    sf::Sprite sprite;
    sf::RenderWindow& window;
    float window_width;
    float window_height;
    bool dead;
};