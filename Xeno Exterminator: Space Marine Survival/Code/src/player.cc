#include "player.h"
#include "point.h"
#include "wall.h"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <cmath>
#include <iostream>


Player::Player(sf::Vector2f coordinates, sf::Texture& texture, sf::RenderWindow& window, int health_points, int damage, int speed, sf::Texture& fire_texture, double rotation)
    : Entity(coordinates, texture, window, health_points, damage, speed, rotation), fire_texture(fire_texture)
{

    texture_scale = 2.3;
    width = 40;
    height = 40;
    attack_distance = 120;
    attack_cooldown = 0.5;
    time_since_last_attack = 0.0;
    invul_time = sf::seconds(1.5f);
    damage_effect_timer.restart();
    
    sprite.setScale(texture_scale, texture_scale);

    hitbox.setSize(sf::Vector2f(width, height));
    hitbox.setOrigin(width / 2.0f, height / 2.0f);
    hitbox.setPosition(coordinates);

    
}


Player::~Player() {}


sf::Vector2f Player::find_direction() const
{
    sf::Vector2f direction;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        direction.y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        direction.y += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        direction.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        direction.x += 1;

    return normalize(direction);
}


void Player::move(double const delta_time)
{
    sf::Vector2f direction = find_direction();
    double distance_to_move{speed * delta_time};

    coordinates = check_boundury_collision(direction, distance_to_move);
}


void Player::update(double const delta_time)
{
    sf::Vector2f mouse_position{sf::Mouse::getPosition(window)};
    rotate(mouse_position);
    move(delta_time);
    hitbox.setPosition(coordinates);

    time_since_last_attack += delta_time;
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && can_attack())
    {
        attack();
        time_since_last_attack = 0.0;
    }

    if(damage_effect_timer.getElapsedTime() < damage_effect_duration)
    {
        sprite.setColor(sf::Color(255, 0, 0));
    }
    else
    {
        sprite.setColor(sf::Color::White);
    }

    if( health_points <= 0)
    {
        dead = true;
    }
}


void Player::handle_collision(std::shared_ptr<Game_Object> collided)
{
    std::shared_ptr<Wall> wall = std::dynamic_pointer_cast<Wall> (collided);
    if (wall)
    {
        float x_pos_difference{coordinates.x - wall->get_coordinates().x};
        float y_pos_difference{coordinates.y - wall->get_coordinates().y};
        
        if(std::abs(x_pos_difference) < std::abs(y_pos_difference))
        {
            sf::Vector2f new_pos{coordinates.x, wall->get_coordinates().y};
            if(y_pos_difference > 0)
                new_pos.y += height / 2 + wall->get_height() / 2;
            else
                new_pos.y -= height / 2 + wall->get_height() / 2;
            coordinates = new_pos;
        }
        else
        {
            sf::Vector2f new_pos{wall->get_coordinates().x, coordinates.y};
            if(x_pos_difference > 0)
                new_pos.x += width / 2 + wall->get_width() / 2;
            else
                new_pos.x -= width / 2 + wall->get_width() / 2;
            coordinates = new_pos;
        }
        hitbox.setPosition(coordinates);
    }
}


void Player::attack() const 
{
    sf::Vector2f hitbox_position = coordinates;

    sf::RectangleShape attack_hitbox;
    float hitbox_height{attack_distance};
    float hitbox_width{static_cast<float>(width)};
    sf::Vector2f size{hitbox_height, hitbox_width};

    attack_hitbox.setPosition(hitbox_position);
    attack_hitbox.setRotation(rotation);
    attack_hitbox.setFillColor(sf::Color::Black);
    attack_hitbox.setOrigin(-width / 2, hitbox_width / 2);
    attack_hitbox.setSize(size);


    sf::RectangleShape texture_attack_hitbox;
    sf::Vector2f texture_size{hitbox_width + 20, attack_distance};
    texture_attack_hitbox.setSize(texture_size);
    texture_attack_hitbox.setOrigin(texture_size.x / 2, texture_size.y + width / 2);
    texture_attack_hitbox.setRotation(rotation + 90);
    texture_attack_hitbox.setPosition(coordinates);
    texture_attack_hitbox.setTexture(&fire_texture);

    if (loaded_enemies)
    {
        for (auto it = loaded_enemies->begin(); it != loaded_enemies->end(); ++it)
        {
            sf::FloatRect enemy_bounds = (*it)->get_global_bounds();
            sf::FloatRect attack_bounds = attack_hitbox.getGlobalBounds();

            if (enemy_bounds.intersects(attack_bounds))
            {
                (*it)->take_damage(damage);
            }
        }
    }
    window.draw(texture_attack_hitbox);
}


void Player::kill_entity(sf::Texture const& dead_texture)
{
    set_texture(dead_texture);
    dead = true;
}


void Player::take_damage(int const damage_to_take)
{
    if ( damage_effect_timer.getElapsedTime() > invul_time )
    {
        health_points -= damage_to_take;   
        damage_effect_timer.restart();
        sprite.setColor(sf::Color(255, 0, 0)); 
    }
}