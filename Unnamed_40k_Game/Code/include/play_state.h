#pragma once
#include "game_object.h"
#include "abstract_game_state.h"
#include <vector>
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

    void load(std::string const& file_name);
    void render(sf::RenderWindow & window) override;
    void update(double delta_time, sf::RenderWindow& window, size_t window_width, size_t window_height) override;

    private:
    sf::Texture grunt_texture;
    sf::Texture player_texture;
    sf::Texture wall_texture;
    std::vector<Game_Object*> level;
};

// std::vector<Game_Object*>& operator=(std::vector<Game_Object*> lhs, std::vector<Game_Object*> && rhs);