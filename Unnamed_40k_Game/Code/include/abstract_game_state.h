#pragma once

#include <SFML/Graphics.hpp>

class Abstract_Game_State
{
public:
    Abstract_Game_State(sf::RenderWindow& window);
    ~Abstract_Game_State();

    virtual void update(double delta_time) = 0;
    virtual void render() = 0;
    virtual int get_change() = 0;

    protected:
    sf::RenderWindow& window;
};
