#pragma once

#include <SFML/Graphics.hpp>

class Abstract_Game_State
{
public:
    Abstract_Game_State(/* args */);
    ~Abstract_Game_State();

    virtual void update(double delta_time, sf::RenderWindow& window) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual int get_change() = 0;

};
