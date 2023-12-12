#include "game_object.h"
#include <SFML/Graphics.hpp>

Game_Object::Game_Object(sf::Vector2f coordinates, sf::Texture& texture)
: coordinates{coordinates}, texture{&texture}
{
    width = 32;
    height = 32;
    
    // Set up the hitbox
    hitbox.setSize(sf::Vector2f(width, height));
    hitbox.setPosition(coordinates);
    hitbox.setOrigin(width / 2.0f, height / 2.0f);

    // Set up the texture
    //texture.loadFromFile("../Static/Textures/missing.png"); // default texture if no texture is given
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


void Game_Object::set_coordinates(sf::Vector2f set_coordinates)
{
    coordinates = set_coordinates;
}


void Game_Object::draw(sf::RenderWindow& window)
{
    hitbox.setPosition(coordinates);
    window.draw(sprite);
}


sf::FloatRect Game_Object::get_global_bounds() const
{
    return hitbox.getGlobalBounds();
}