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
//     Play_State();

//     void run(double delta_time, Player player);
//     // std::vector<Game_Object*> load(std::string file_name);

//     private:
//     Player player;
//     std::vector<Enemy*> enemies;
//     //std::vector<Game_Object*> level;
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
    Game_Object(sf::Vector2f coordinates); 
    virtual ~Game_Object() = 0;


    sf::Vector2f get_coordinates() const;
    double get_height() const;
    double get_width() const;
    virtual void draw(sf::RenderWindow& window);


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
    Entity(sf::Vector2f coordinates, int health_points, int damage, int speed);
    virtual ~Entity() = 0;


    void draw(sf::RenderWindow& window) override;
    // virtual bool attack() const = 0;
    virtual void move(double delta_time, size_t window_width, size_t window_height) = 0;
    virtual void rotate(sf::Vector2f& direction);


    protected:
    int health_points;
    int damage;
    int speed;
    double rotation;
};


class Player : public Entity
{
    public:
    Player(sf::Vector2f coordinates, int health_points, int damage, int speed);
    ~Player();
    
    sf::Vector2f find_direction() const;
    void update(double delta_time, sf::RenderWindow& window, size_t window_width, size_t window_height);
    // bool attack() const override;
    void move(double delta_time, size_t window_width, size_t window_height) override;
    sf::Vector2f find_mouse(sf::RenderWindow& window);
};


class Enemy : public Entity
{
    public:
    Enemy(sf::Vector2f coordinates, int health_points, int damage, int speed, Player& player);
    virtual ~Enemy() = 0;

    virtual void update(double delta_time, size_t window_width, size_t window_height) = 0;
    // void move(double delta_time, size_t window_width, size_t window_height) override;

    protected:
    Player& player;
};


class Grunt : public Enemy
{
    public:
    Grunt(sf::Vector2f coordinates, int health_points, int damage, int speed, Player& player);
    ~Grunt();

    void update(double delta_time, size_t window_width, size_t window_height) override;
    void move(double delta_time, size_t window_width, size_t window_height) override;
    void rotate(sf::Vector2f& direction) override;
};


// class Projectile : public Entity
// {

// };