#pragma once

#include "entity.h"
#include "enemy.h"
#include "grunt.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <memory>

/**
 * @class Player
 * @brief Represents the player in the game, derived from the Entity class.
 */
class Player : public Entity
{
    public:
    /**
     * @brief Constructor for the Player class.
     * @param coordinates The initial coordinates of the player.
     * @param texture The texture used for rendering the player.
     * @param window The render window where the player will be drawn.
     * @param health_points The health points of the player.
     * @param damage The damage inflicted by the player.
     * @param speed The speed at which the player moves.
     * @param fire_texture The texture used for rendering the player's attack.
     * @param rotation The initial rotation angle of the player.
     */
    Player(sf::Vector2f coordinates,
           sf::Texture& texture,
           sf::RenderWindow& window,
           int health_points,
           int damage,
           int speed,
           sf::Texture& fire_texture,
           double rotation = 0);

    /**
     * @brief Destructor for the Player class.
     */
    ~Player();

    /**
     * @brief Calculates the direction in which the player is facing.
     * @return The normalized vector representing the player's direction.
     */
    sf::Vector2f find_direction() const;

    /**
     * @brief Updates the player's state over time.
     * @param delta_time The time elapsed since the last update.
     */
    void update(double const delta_time);

    /**
     * @brief Handles collision with other game objects.
     * @param collided The game object with which the collision occurred.
     */
    void handle_collision(std::shared_ptr<Game_Object> collided) override;

    /**
     * @brief Performs the attack behavior of the player.
     */
    void attack() const override;

    /**
     * @brief Moves the player based on its speed and direction.
     * @param delta_time The time elapsed since the last move.
     */
    void move(double const delta_time) override;

    /**
     * @brief Kills the player and sets its texture to the specified dead texture.
     * @param dead_texture The texture to set after the player is killed.
     */
    void kill_entity(sf::Texture const& dead_texture) override;

    /**
     * @brief Reduces the player's health points based on the given damage.
     * @param damage_to_take The amount of damage the player should take.
     */
    void take_damage(int const damage_to_take) override;

    private:
    sf::Time invul_time; ///< Time interval during which the player is invulnerable after taking damage.
    sf::Texture& fire_texture; ///< The texture used for rendering the player's attack.
};
