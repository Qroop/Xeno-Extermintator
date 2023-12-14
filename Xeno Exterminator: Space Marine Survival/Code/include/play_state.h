#pragma once

#include "game_object.h"
#include "abstract_game_state.h"
#include "grunt.h"
#include "enemy.h"
#include "player.h"
#include "projectile.h"
#include <vector>
#include <memory>
#include <string>

/**
 * @class Play_State
 * @brief Represents the game state during play, derived from Abstract_Game_State.
 */
class Play_State : public Abstract_Game_State
{
    public:
    /**
     * @brief Constructor for the Play_State class.
     * @param window The render window for the game.
     */
    Play_State(sf::RenderWindow& window);

    /**
     * @brief Destructor for the Play_State class.
     */
    ~Play_State();

    /**
     * @brief Loads a game state from a specified file.
     * @param file_name The name of the file containing the game state information.
     */
    void load(std::string const& file_name);

    /**
     * @brief Renders the game state.
     */
    void render();

    /**
     * @brief Updates the game state over time.
     * @param delta_time The time elapsed since the last update.
     */
    void update(double const delta_time) override;

    /**
     * @brief Gets the count of enemies in the game state.
     * @return The count of enemies.
     */
    int get_enemy_count() const;

    /**
     * @brief Checks if the player is dead.
     * @return True if the player is dead, false otherwise.
     */
    bool get_player_dead() const;

    /**
     * @brief Gets the change in the game state.
     * @return The change in the game state.
     */
    int get_change() const override;

    private:
    sf::Texture grunt_texture;
    sf::Texture player_texture;
    sf::Texture wall_texture;
    sf::Texture dead_grunt_texture;
    sf::Texture projectile_texture;
    sf::Texture dead_projectile_texture;
    sf::Texture fire_texture;

    std::vector<std::shared_ptr<Game_Object>> level; ///< The game objects in the current level.
    std::vector<std::shared_ptr<Game_Object>> dead_entities; ///< The dead game objects in the current level.
    std::vector<std::shared_ptr<Enemy>> enemies; ///< The enemies in the current level.
    std::vector<std::shared_ptr<Enemy>> projectiles_to_add; ///< The projectiles to be added to the game state.

    std::shared_ptr<Player> player_pointer; ///< Pointer to the player object in the game state.
};
