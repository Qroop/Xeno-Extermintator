#include "player.h"
#include "point.h"
#include "standard.h"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <cmath>
#include <iostream>


Player::Player(sf::Vector2f coordinates, sf::Texture& texture, int health_points, int damage, int speed, int window_width, int window_height)
    : Entity(coordinates, texture, health_points, damage, speed, window_width, window_height)
{


    texture_scale = 3;
    width = width * texture_scale / 2;
    height = height * texture_scale / 2;
    attack_distance = 80;
    attack_cooldown = 0.5;
    time_since_last_attack = 0.0;
    
    // Set the sprite scale
    sprite.setScale(texture_scale, texture_scale);

    // Set the hitbox size and position (considering scaling)
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


void Player::move(double delta_time, size_t window_width, size_t window_height)
{
    sf::Vector2f direction = find_direction();
    double distance_to_move{speed * delta_time};

    coordinates = check_boundury_collision(direction, distance_to_move, window_width, window_height);
}


void Player::update(double delta_time, sf::RenderWindow& window)
{
    sf::Vector2f mouse_position{sf::Mouse::getPosition(window)};
    rotate(mouse_position);
    move(delta_time, window_size.x, window_size.y);
    hitbox.setPosition(coordinates);

    time_since_last_attack += delta_time;
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && can_attack())
    {
        attack();
        time_since_last_attack = 0.0;
    }
}


void Player::attack() const 
{
    sf::Vector2f hitbox_position = coordinates;

    sf::RectangleShape attack_hitbox;
    float hitbox_width{attack_distance};
    float hitbox_height{static_cast<float>(width)};
    sf::Vector2f size{hitbox_width, hitbox_height};

    attack_hitbox.setPosition(hitbox_position);
    attack_hitbox.setRotation(rotation);
    attack_hitbox.setFillColor(sf::Color::Black);
    attack_hitbox.setOrigin(0, hitbox_height / 2);
    attack_hitbox.setSize(size);

    if (loaded_enemies)
    {
        for (auto it = loaded_enemies->begin(); it != loaded_enemies->end(); ++it)
        {
            sf::FloatRect enemy_bounds = (*it) -> get_global_bounds();
            sf::FloatRect attack_bounds = attack_hitbox.getGlobalBounds();

            if (enemy_bounds.intersects(attack_bounds))
            {
                (*it) -> take_damage(damage);

            }
        }
    }

    // window.draw(attack_hitbox);
}
