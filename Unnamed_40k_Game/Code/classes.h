#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

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

// class Play_State
// {
//     public:
//     std::vector<Game_Object*> load(std::string file_name);

//     private:
//     std::vector<Game_Object*> level;
// };

// class Menu_State
// {

// };

// class Game_Over_State
// {

// };

class Game_Object
{
    public:
    Game_Object(sf::Vector2f coordinates, 
            double width = 32, 
            double height = 32); 
            // const std::string& texture_path = "../Static/missing.png");
    virtual ~Game_Object() = 0;

    sf::Vector2f get_coordinates() const;
    double get_height() const;
    double get_width() const;
    void draw(sf::RenderWindow& window);

    protected:
    sf::Vector2f coordinates;
    double width;
    double height;
    sf::RectangleShape hitbox;
    sf::Texture texture;
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
    ~Player();
    
    sf::Vector2f find_direction() const;
    void update(double delta_time) override;
    // bool attack() const override;
    void move(double delta_time) override;
};


// class Enemy : public Entity
// {

// };


// class Grunt : public Entity
// {

// };


// class Projectile : public Entity
// {

// };