#pragma once
#include "game_object.h"
#include "wall.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>



class Enemy;

class Entity : public Game_Object
{
    public:
    Entity(sf::Vector2f coordinates,
            sf::Texture& texture,
            sf::RenderWindow& window, 
            int health_points = 3,
            int damage = 1,
            int speed = 1,
            double rotation = 0);

    virtual ~Entity();


    void draw() override;
    virtual void attack() const = 0;
    virtual void move(double delta_time) = 0;
    virtual void handle_collision(std::shared_ptr<Game_Object> collided) = 0;
    void handle_wall_collision(std::shared_ptr<Wall> wall);
    void rotate(sf::Vector2f& direction);
    sf::Vector2f check_boundury_collision(sf::Vector2f direction, double distance_to_move, size_t window_width, size_t window_height);
    bool is_dead();
    void set_speed(int new_speed);
    void set_texture(sf::Texture& new_texture);
    void set_attack_speed(double new_speed);
    bool can_attack() const;
    void set_enemies(std::vector<std::shared_ptr<Enemy>>& enemies);
    std::string check_set_enemies() const;
    virtual void kill_entity(sf::Texture& dead_texture) = 0;
    virtual void take_damage(int damage_to_take);


    protected:
    int health_points;
    int damage;
    int speed;
    float texture_scale;
    bool dead;
    float attack_distance;
    double attack_cooldown;
    double time_since_last_attack;
    std::vector<std::shared_ptr<Enemy>>* loaded_enemies;
    sf::Vector2i window_size;
    double rotation;
    sf::Vector2f last_pos;
    
    sf::Clock damage_effect_timer;
    sf::Time damage_effect_duration;
}; 