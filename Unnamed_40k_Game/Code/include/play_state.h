#pragma once
#include "game_object.h"
#include "enemy.h"

#include <memory>
#include <vector>
#include <string>

class Play_State
{
    public:
    Play_State();
    ~Play_State();
    Play_State(Play_State & other) = delete;
    Play_State& operator=(Play_State & other) = delete;
    Play_State(Play_State && other) = delete;
    Play_State& operator=(Play_State && other) = delete;

    void load(std::string file_name, int window_width, int window_height);
    void render(sf::RenderWindow & window);
    void update(double delta_time, sf::RenderWindow& window);

    private:
    sf::Texture grunt_texture;
    sf::Texture player_texture;
    sf::Texture wall_texture;
    sf::Texture dead_grunt_texture;
    sf::Texture projectile_texture;

    std::vector<std::shared_ptr<Game_Object>> level;
    std::vector<std::shared_ptr<Game_Object>> dead_entities;
    std::vector<std::shared_ptr<Enemy>> enemies;
};