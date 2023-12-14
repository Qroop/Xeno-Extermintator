#include "point.h"
#include "play_state.h"
#include "player.h"
#include "grunt.h"
#include "game_engine.h"

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

const size_t window_width = 1536;
const size_t window_height = 1024;

int main()
{
    Game_Engine game;
    game.run();
}
