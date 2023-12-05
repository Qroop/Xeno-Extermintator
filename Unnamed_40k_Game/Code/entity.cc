#include "entity.h"

Entity::Entity(sf::Vector2f coordinates, double width, double height, int health_points, int damage, int speed)
: Game_Object(coordinates, width, height), health_points(health_points), damage(damage), speed(speed) {}

Entity::~Entity() {}