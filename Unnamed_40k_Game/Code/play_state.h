#pragma once
#include "game_object.h"
#include <vector>
#include <string>

class Play_State
{
    public:
    Play_State();
    void load(std::string file_name);
    void render() const;

    private:
    std::vector<Game_Object*> level;
};
