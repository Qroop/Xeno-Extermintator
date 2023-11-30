#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class Game_Engine
{


    private:
    std::vector<Abstract_Game_State*> states;
    bool running;
    int active_state;
};

class Abstract_Game_State
{

};

class Play_State
{

};

class Menu_State
{

};

class Game_Over_State
{

};

class Game_Object
{
    public:
    Game_Object(sf::Vector2f coordinates, double width, double height);
    virtual ~Game_Object();

    double get_x_coordinate();
    double get_y_coordinate();
    double get_height();
    double get_width();
    virtual void draw() const = 0;

    protected:
    sf::Vector2f coordinates;
    double width;
    double height;
};

class Walls : public Game_Object
{

};

class Entity : public Game_Object
{
    public:
    Entity();

    virtual void update() const = 0;
    virtual bool attack() const = 0;
    virtual void move() const = 0;
    
    protected:
    sf::Vector2f coordinates;
    int health_points;
    int damage;
    int speed;
};


class Player : public Entity
{
    public:
    Player();
    
    void move() override;

    private:
};


class Enemy : public Entity
{

};


class Grunt : public Entity
{

};


class Projectile : public Entity
{

};