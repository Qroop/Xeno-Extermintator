#pragma once

#include "game_object.h"
#include "wall.h"
//#include "enemy.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

class Enemy;

/**
 * @class Entity
 * @brief Represents a generic entity in the game, derived from Game_Object.
 */
class Entity : public Game_Object
{
    public:
    /**
     * @brief Constructor for the Entity class.
     * @param coordinates The initial coordinates of the entity.
     * @param texture The texture used for rendering the entity.
     * @param window The render window where the entity will be drawn.
     * @param health_points The health points of the entity.
     * @param damage The damage inflicted by the entity.
     * @param speed The speed at which the entity moves.
     * @param rotation The initial rotation angle of the entity.
     */
    Entity(sf::Vector2f coordinates,
           sf::Texture& texture,
           sf::RenderWindow& window,
           int health_points = 3,
           int damage = 1,
           int speed = 1,
           double rotation = 0);

    /**
     * @brief Virtual destructor for the Entity class.
     */
    virtual ~Entity();

    /**
     * @brief Pure virtual function for updating the enitty state.
     * 
     * This function must be implemented by derived classes to update the state of the entity.
     * 
     * @param delta_time Time elapsed since the last update.
     */
    virtual void update(double delta_time) = 0;

    /**
     * @brief Draws the entity on the render window.
     */
    void draw() override;

    /**
     * @brief Performs the attack behavior of the entity (pure virtual).
     */
    virtual void attack() const = 0;

    /**
     * @brief Moves the entity based on its speed and direction (pure virtual).
     * @param delta_time The time elapsed since the last move.
     */
    virtual void move(double const delta_time) = 0;

    /**
     * @brief Handles collision with other game objects (pure virtual).
     * @param collided The game object with which the collision occurred.
     */
    virtual void handle_collision(std::shared_ptr<Game_Object> collided) = 0;

    /**
     * @brief Handles collision with a wall.
     * @param wall The wall with which the collision occurred.
     */
    void handle_wall_collision(std::shared_ptr<Wall> wall);

    /**
     * @brief Rotates the entity based on the given direction.
     * @param direction The direction vector to which the entity should be oriented.
     */
    void rotate(sf::Vector2f& direction);

    /**
     * @brief Checks and handles collision with the game boundaries.
     * @param direction The intended direction of movement.
     * @param distance_to_move The distance to move in the specified direction.
     * @return The adjusted movement direction after collision handling.
     */
    sf::Vector2f check_boundury_collision(sf::Vector2f& direction, double const distance_to_move);

    /**
     * @brief Checks if the entity is dead.
     * @return True if the entity is dead, false otherwise.
     */
    bool is_dead();

    /**
     * @brief Sets the speed of the entity.
     * @param new_speed The new speed to set.
     */
    void set_speed(int const new_speed);

    /**
     * @brief Sets the texture of the entity.
     * @param new_texture The new texture to set.
     */
    void set_texture(sf::Texture const& new_texture);

    /**
     * @brief Sets the attack speed of the entity.
     * @param new_speed The new attack speed to set.
     */
    void set_attack_speed(double const new_speed);

    /**
     * @brief Checks if the entity can attack based on the attack cooldown.
     * @return True if the entity can attack, false otherwise.
     */
    bool can_attack() const;

    /**
     * @brief Sets the vector of enemies for the entity to interact with.
     * @param enemies The vector of enemies.
     */
    void set_enemies(std::vector<std::shared_ptr<Enemy>>& enemies);

    /**
     * @brief Performs the death sequence of the entity (pure virtual).
     * @param dead_texture The texture to set after the entity is killed.
     */
    virtual void kill_entity(sf::Texture const& dead_texture) = 0;

    /**
     * @brief Reduces the health points of the entity based on the given damage.
     * @param damage_to_take The amount of damage the entity should take.
     */
    virtual void take_damage(int damage_to_take);

    protected:
    int health_points; ///< The health points of the entity.
    int damage; ///< The damage inflicted by the entity.
    int speed; ///< The speed at which the entity moves.
    float texture_scale; ///< The scale factor for the entity's texture.
    bool dead; ///< Flag indicating whether the entity is dead.
    float attack_distance; ///< The distance within which the entity can attack.
    double attack_cooldown; ///< The cooldown time between consecutive attacks.
    double time_since_last_attack; ///< Time elapsed since the last attack.
    std::vector<std::shared_ptr<Enemy>>* loaded_enemies; ///< Pointer to the vector of enemies.
    sf::Vector2i window_size; ///< The size of the render window.
    double rotation; ///< The rotation angle of the entity.

    sf::Clock damage_effect_timer; ///< Timer for damage effect duration.
    sf::Time damage_effect_duration; ///< Duration of the damage effect.
};
