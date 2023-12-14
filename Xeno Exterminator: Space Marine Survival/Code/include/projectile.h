#pragma once

#include "enemy.h"
#include "game_object.h"
#include <SFML/Graphics.hpp>

/**
 * @class Projectile
 * @brief Represents a projectile fired by an enemy, derived from the Enemy class.
 */
class Projectile : public Enemy
{
    public:
    /**
     * @brief Constructor for the Projectile class.
     * @param coordinates The initial coordinates of the projectile.
     * @param texture The texture used for rendering the projectile.
     * @param window The render window where the projectile will be drawn.
     * @param health_points The health points of the projectile.
     * @param damage The damage inflicted by the projectile.
     * @param speed The speed at which the projectile moves.
     * @param player The player Game_Object that the projectile targets.
     * @param rotation The initial rotation angle of the projectile.
     */
    Projectile(sf::Vector2f coordinates,
               sf::Texture& texture,
               sf::RenderWindow& window,
               int health_points,
               int damage,
               int speed,
               Game_Object& player,
               double rotation);

    /**
     * @brief Destructor for the Projectile class.
     */
    ~Projectile();

    /**
     * @brief Updates the projectile's state over time.
     * @param delta_time The time elapsed since the last update.
     */
    void update(double const delta_time) override;

    /**
     * @brief Performs the attack behavior of the projectile.
     */
    void attack() const override;

    /**
     * @brief Moves the projectile based on its speed and direction.
     * @param delta_time The time elapsed since the last move.
     */
    void move(double const delta_time) override;

    /**
     * @brief Handles collision with other game objects.
     * @param collided The game object with which the collision occurred.
     */
    void handle_collision(std::shared_ptr<Game_Object> collided) override;

    /**
     * @brief Kills the projectile and sets its texture to the specified dead texture.
     * @param dead_texture The texture to set after the projectile is killed.
     */
    void kill_entity(sf::Texture const& dead_texture) override;

    private:
    sf::Vector2f direction_to_move; ///< The direction in which the projectile is moving.
};
