#pragma once
#include "game_object.h"
#include "abstract_game_state.h"
#include "grunt.h"
#include "enemy.h"

#include <vector>
#include <memory>
#include <string>

class Play_State : public Abstract_Game_State
{
    public:
    Play_State();
    ~Play_State();
    Play_State(Play_State & other) = delete;
    Play_State& operator=(Play_State & other) = delete;
    Play_State(Play_State && other) = delete;
    Play_State& operator=(Play_State && other) = delete;

    void load(std::string const& file_name, sf::RenderWindow& window);
    void render(sf::RenderWindow & window) override;
    void update(double delta_time, sf::RenderWindow& window, size_t window_width, size_t window_height) override;
    int get_enemy_count();
    bool get_player_dead();
    int get_change() override;

    private:
    sf::Texture grunt_texture;
    sf::Texture player_texture;
    sf::Texture wall_texture;
    sf::Texture dead_grunt_texture;

    std::vector<std::shared_ptr<Game_Object>> level;
    std::vector<std::shared_ptr<Game_Object>> dead_entities;
    std::vector<std::shared_ptr<Grunt>> enemies;

    std::shared_ptr<Player> player_object;
};