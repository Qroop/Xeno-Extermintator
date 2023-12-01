#include "classes.h"

Game_Object::Game_Object(sf::Vector2f coordinates, double width, double height)
: coordinates{coordinates}, width{width}, height{height}
{
    shape.setSize(sf::Vector2f(static_cast<float>(width), static_cast<float>(height)));
    shape.setPosition(coordinates);
}

double Game_Object::get_x_coordinate()
{
    return coordinates.x;
}

double Game_Object::get_y_coordinate()
{
    return coordinates.y;
}

double Game_Object::get_height()
{
    return height;
}

double Game_Object::get_width()
{
    return width;
}