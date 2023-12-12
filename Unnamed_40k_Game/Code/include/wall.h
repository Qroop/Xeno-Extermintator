#pragma once
#include "game_object.h"
#include <SFML/Graphics.hpp>

class Wall : public Game_Object
{
    public:
    Wall(sf::Vector2f coordinates, sf::Texture& texture);
    ~Wall();

    // void update(double delta_time);
    // bool is_dead() override;
};

