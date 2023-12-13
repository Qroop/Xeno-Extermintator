#pragma once
#include "game_object.h"
#include "abstract_game_state.h"
#include "grunt.h"
#include "enemy.h"
#include "player.h"

#include <vector>
#include <memory>
#include <string>

class Play_State : public Abstract_Game_State
{
    public:
    Play_State(sf::RenderWindow& window);
    ~Play_State();
    Play_State(Play_State & other) = delete;
    Play_State& operator=(Play_State & other) = delete;
    Play_State(Play_State && other) = delete;
    Play_State& operator=(Play_State && other) = delete;

    void load(std::string file_name);
    void render();
    void update(double delta_time) override;
    int get_enemy_count();
    bool get_player_dead();
    void set_player_dead();
    int get_change() override;


    private:
    // int enemy_count;

    sf::Texture grunt_texture;
    sf::Texture player_texture;
    sf::Texture wall_texture;
    sf::Texture dead_grunt_texture;
    sf::Texture projectile_texture;
    sf::Texture dead_projectile_texture;
    sf::Texture fire_texture;

    std::vector<std::shared_ptr<Game_Object>> level;
    std::vector<std::shared_ptr<Game_Object>> dead_entities;
    std::vector<std::shared_ptr<Enemy>> enemies;
    std::vector<std::shared_ptr<Enemy>> projectiles_to_add;

    std::shared_ptr<Player> player_pointer;
};