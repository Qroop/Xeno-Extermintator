#pragma once
#include "entity.h"
#include <SFML/Graphics.hpp>

/**
 * @brief Base class for enemy entities.
 * 
 * This class inherits from the Entity class and provides common functionalities for enemy entities.
 */
class Enemy : public Entity
{
    public:
    /**
     * @brief Constructor for the Enemy class.
     * 
     * @param coordinates Initial position of the enemy.
     * @param texture Reference to the SFML Texture used for rendering.
     * @param window Reference to the SFML RenderWindow.
     * @param health_points Initial health points of the enemy.
     * @param damage Amount of damage the enemy can inflict.
     * @param speed Movement speed of the enemy.
     * @param player Reference to the Game_Object representing the player.
     * @param rotation Initial rotation of the enemy (default is 0).
     */
    Enemy(sf::Vector2f coordinates, 
        sf::Texture& texture,
        sf::RenderWindow& window, 
        int health_points, int damage, int speed, 
        Game_Object& player,
        double rotation = 0);

    /**
     * @brief Virtual destructor for the Enemy class.
     */
    virtual ~Enemy() = 0;

    /**
     * @brief Pure virtual function for updating the enemy state.
     * 
     * This function must be implemented by derived classes to update the state of the enemy.
     * 
     * @param delta_time Time elapsed since the last update.
     */
    virtual void update(double delta_time) = 0;

    /**
     * @brief Rotate the enemy based on the given direction and delta time.
     * 
     * @param direction The direction to rotate towards.
     * @param delta_time Time elapsed since the last rotation.
     */
    void rotate(sf::Vector2f& direction, double delta_time);

    /**
     * @brief Calculate the shortest angular distance between two angles.
     * 
     * @param from Starting angle.
     * @param to Target angle.
     * @return The shortest angular distance between the two angles.
     */
    double shortest_angular_distance(double from, double to) const;

    /**
     * @brief Set the rotation speed of the enemy.
     * 
     * @param new_rotation_speed The new rotation speed.
     */
    void set_rotation_speed(double new_rotation_speed);

    protected:
    /**
     * @brief Reference to the Game_Object representing the player.
     */
    Game_Object& player;

    /**
     * @brief Rotation speed of the enemy.
     */
    double rotation_speed;
};