#pragma once
#include "game_object.h"
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

    void load(std::string file_name);
    void render(sf::RenderWindow & window);
    void update(double delta_time, sf::RenderWindow& window, size_t window_width, size_t window_height);

    private:
    std::vector<Game_Object*> level;
};

// std::vector<Game_Object*>& operator=(std::vector<Game_Object*> lhs, std::vector<Game_Object*> && rhs);