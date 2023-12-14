#include "game_object.h"

#include <SFML/Graphics.hpp>
#include <math.h>

Game_Object::Game_Object(sf::Vector2f coordinates, sf::Texture& texture, sf::RenderWindow& window)
: coordinates{coordinates}, texture{texture}, window{window}
{
    width = 32;
    height = 32;
    
    // Set up the hitbox
    hitbox.setSize(sf::Vector2f(width, height));
    hitbox.setPosition(coordinates);
    hitbox.setOrigin(width / 2.0f, height / 2.0f);

    // Set up the texture
    sprite.setTexture(texture);
    sprite.setScale(2.0f, 2.0f);
    sprite.setPosition(coordinates);
    sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);
}


Game_Object::~Game_Object() {}


double Game_Object::get_height() const
{
    return height;
}


double Game_Object::get_width() const
{
    return width;
}


sf::Vector2f Game_Object::get_coordinates() const
{
    return coordinates;
}


void Game_Object::set_coordinates(sf::Vector2f const& set_coordinates)
{
    coordinates = set_coordinates;
}


void Game_Object::draw()
{
    hitbox.setPosition(coordinates);
    window.draw(sprite);
}


sf::FloatRect Game_Object::get_global_bounds() const
{
    return hitbox.getGlobalBounds();
}


void Game_Object::set_dimensions(sf::Vector2f const& new_dimensions)
{
    height = new_dimensions.y;
    width = new_dimensions.x;
    hitbox.setSize(sf::Vector2f(height, width));
    hitbox.setOrigin(sf::Vector2f(height / 2, width / 2));
}