#include "player.h"
#include "point.h"
#include "standard.h"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <cmath>
#include <iostream>


Player::Player(sf::Vector2f coordinates, sf::Texture& texture, int health_points, int damage, int speed)
    : Entity(coordinates, texture, health_points, damage, speed)
{
    texture_scale = 3;
    width = width * texture_scale / 2;
    height = height * texture_scale / 2;
    attack_distance = 30;
    
    // Set the sprite scale
    sprite.setScale(texture_scale, texture_scale);

    // Set the hitbox size and position (considering scaling)
    hitbox.setSize(sf::Vector2f(width, height));
    hitbox.setOrigin(width / 2.0f, height / 2.0f);  // Set the origin at the center
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


void Player::update(double delta_time, sf::RenderWindow& window, size_t window_width, size_t window_height)
{
    sf::Vector2f mouse_position{sf::Mouse::getPosition(window)};
    rotate(mouse_position);
    move(delta_time, window_width, window_height);
    hitbox.setPosition(coordinates);

    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        attack(window);
    }
}

void Player::attack(sf::RenderWindow& window) const 
{
    /*To Do
    1. Skapa en hitbox i spelarens riktning
    2. Kolla vilka fiender som är i den
    3. Om fienden är i den så tar dem skada*/
    float radians = rotation * (M_PI / 180.0f);

    float offset_x = attack_distance * std::cos(radians);
    float offset_y = attack_distance * std::sin(radians);

    sf::Vector2f hitbox_position = coordinates + sf::Vector2f(offset_x, offset_y);

    sf::RectangleShape attack_hitbox;
    float hitbox_width{50};
    float hitbox_height{50};
    attack_hitbox.setPosition(hitbox_position);
    attack_hitbox.setRotation(rotation);
    attack_hitbox.setFillColor(sf::Color::Black);
    attack_hitbox.setOrigin(hitbox_width / 2, hitbox_height / 2);
    attack_hitbox.setSize(sf::Vector2f(hitbox_width, hitbox_height));

    window.draw(attack_hitbox);
    //cout << "Attack!" << endl;
}
