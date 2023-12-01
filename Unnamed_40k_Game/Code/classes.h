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
    public:
    std::vector<Game_Object*> load(std::string file_name);

    private:
    std::vector<Game_Object*> level;
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
    Game_Object(sf::Vector2f coordinates, double width = 32, double height = 32);
    virtual ~Game_Object();

    double get_x_coordinate();
    double get_y_coordinate();
    double get_height();
    double get_width();
    virtual void draw(sf::RenderWindow window) const = 0;

    protected:
    sf::Vector2f coordinates;
    double width;
    double height;
    sf::RectangleShape shape;
};


class Wall : public Game_Object
{
    public:
    Wall(sf::Vector2f coordinates, double width, double height);
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

    
    virtual void update() const = 0;
    virtual bool attack() const = 0;
    virtual void move() const = 0;
    

    protected:
    double rotation;
    int health_points;
    int damage;
    int speed;
};


class Player : public Entity
{
    public:
    Player(sf::Vector2f coordinates, double width, double height, int health_points);
    
    sf::Vector2f move() override;

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