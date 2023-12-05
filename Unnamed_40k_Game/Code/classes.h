#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "game_object.h"

// class Game_Engine
// {


//     private:
//     std::vector<Abstract_Game_State*> states;
//     bool running;
//     int active_state;
// };

// class Abstract_Game_State
// {

// };


// class Menu_State
// {

// };

// class Game_Over_State
// {

// };





class Wall : public Game_Object
{
    public:
    Wall(sf::Vector2f coordinates, double width, double height);
    Wall(sf::Vector2f coordinates);
    ~Wall();
};


class Entity : public Game_Object
{
    public:
    Entity(sf::Vector2f coordinates, 
            double width, 
            double height, 
            int health_points,
            int damage,
            int speed);

    virtual ~Entity() = 0;

    
    virtual void update(double delta_time) = 0;
    // virtual bool attack() const = 0;
    virtual void move(double delta_time) = 0;
    

    protected:
    int health_points;
    int damage;
    int speed;
    double rotation;
};


class Player : public Entity
{
    public:
    Player(sf::Vector2f coordinates, 
            double width, 
            double height, 
            int health_points,
            int damage,
            int speed);
            // const std::string& texturePath = "");
    Player(sf::Vector2f coordinates);
    ~Player();
    
    sf::Vector2f find_direction() const;
    void update(double delta_time) override;
    // bool attack() const override;
    void move(double delta_time) override;
};


class Enemy : public Entity
{
    public:
    Enemy(sf::Vector2f coordinates);

    void update(double delta_time) override;
    void move(double delta_time) override;
};


// class Grunt : public Entity
// {

// };


// class Projectile : public Entity
// {

// };