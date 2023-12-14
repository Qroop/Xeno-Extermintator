#pragma once

#include "enemy.h"
#include <SFML/Graphics.hpp>

/**
 * @class Grunt
 * @brief Represents a grunt enemy in the game, derived from the Enemy class.
 */
class Grunt : public Enemy
{
public:
    /**
     * @brief Constructor for the Grunt class.
     * @param coordinates The initial coordinates of the grunt.
     * @param texture The texture used for rendering the grunt.
     * @param window The render window where the grunt will be drawn.
     * @param projectile_texture The texture used for rendering the grunt's projectiles.
     * @param health_points The health points of the grunt.
     * @param damage The damage inflicted by the grunt.
     * @param speed The speed at which the grunt moves.
     * @param player The player Game_Object that the grunt targets.
     * @param rotation The initial rotation angle of the grunt.
     */
    Grunt(sf::Vector2f coordinates,
          sf::Texture& texture,
          sf::RenderWindow& window,
          sf::Texture& projectile_texture,
          int health_points,
          int damage,
          int speed,
          Game_Object& player,
          double rotation = 0);

    /**
     * @brief Destructor for the Grunt class.
     */
    ~Grunt();

    /**
     * @brief Updates the state of the grunt over time.
     * @param delta_time The time elapsed since the last update.
     */
    void update(double delta_time) override;

    /**
     * @brief Moves the grunt based on its speed and direction.
     * @param delta_time The time elapsed since the last move.
     */
    void move(double const delta_time) override;

    /**
     * @brief Performs the attack behavior of the grunt.
     */
    void attack() const override;

    /**
     * @brief Handles collision with other game objects.
     * @param collided The game object with which the collision occurred.
     */
    void handle_collision(std::shared_ptr<Game_Object> collided) override;

    /**
     * @brief Gets the lateral direction vector of the grunt.
     * @return The normalized lateral direction vector.
     */
    sf::Vector2f get_lateral_direction() const;

    /**
     * @brief Gets the distance between the grunt and the player.
     * @return The distance to the player.
     */
    double get_distance_to_player() const;

    /**
     * @brief Kills the grunt and sets its texture to the specified dead texture.
     * @param dead_texture The texture to set after the grunt is killed.
     */
    void kill_entity(sf::Texture const& dead_texture) override;

private:
    double distance_to_keep; ///< The distance the grunt tries to keep from the player.
    bool walk_left; ///< Flag indicating the grunt's walking direction.
    sf::Texture& projectile_texture; ///< The texture used for rendering the grunt's projectiles.
};
