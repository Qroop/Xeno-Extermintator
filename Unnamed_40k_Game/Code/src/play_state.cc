#include "play_state.h"
#include "wall.h"
#include "player.h"
#include "grunt.h"


#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>


Play_State::Play_State()
: level{}
{
    grunt_texture.loadFromFile("../Static/Textures/grunt_texture.png");
    player_texture.loadFromFile("../Static/Textures/player_texture.png");
    wall_texture.loadFromFile("../Static/Textures/wall_texture.png");
    dead_grunt_texture.loadFromFile("../Static/Textures/dead_grunt_texture.png");
}

Play_State::~Play_State()
{
    if ( !level.empty() )
    {
        for ( Game_Object* i : level)
        {
            delete i;
        }
    }
}

// Creates a vector containing all game objects
void Play_State::load(std::string const& file_name)
{
    std::ifstream fs;
    fs.open("../Static/Levels/" + file_name);

    if (!fs.is_open())
    {
        std::cerr << "Error: no file with such name";
    }
    
    std::vector<std::shared_ptr<Game_Object>> loaded;
    sf::Vector2f coords{16, 16};
    loaded.push_back(std::make_shared<Game_Object> (Player(coords, player_texture, 3, 1, 300)));
    while ( !fs.eof() )
    {
        char character = fs.get();
        switch(character)
        {
            case '#':   // Wall
                loaded.push_back(std::make_shared<Game_Object> (Wall(coords, wall_texture)));
                coords.x += 32;
                break;
            case '@':   // Player
                loaded[0]->set_coordinates(coords);
                coords.x += 32;
                break;
            case 'X':   // Grunt
                // loaded.push_back(std::make_shared<Game_Object> (Grunt(coords, grunt_texture, 3, 1, 50, static_cast<Player&> (*loaded[0])))); // dynamic_cast<Player&>(*loaded[0])
                // enemies.push_back(std::static_pointer_cast<std::shared_ptr<Grunt>> (loaded.at(loaded.size())));
                enemies.push_back(std::make_shared<Grunt> (Grunt(coords, grunt_texture, 3, 1, 50, static_cast<Player&> (*loaded[0])))); // dynamic_cast<Player&>(*loaded[0])
                loaded.push_back( enemies.at(enemies.size()) );
                
                coords.x += 32;
                break;
            case '\n':
                coords.y += 32;
                coords.x = 16;
                break;
            default :   // Whitespace
                coords.x += 32;
                break;
        }
    }
    fs.close();
    
    level = loaded;
    // for ( Game_Object* i : loaded)
    // {
    //     delete i;
    // }
}


void Play_State::render(sf::RenderWindow & window) 
{
    for (Game_Object* current_object : dead_entities)
    {
        current_object -> draw(window);
    }
    for (Game_Object* curr_object : level)
    {
        curr_object -> draw(window);   
    }
}

void Play_State::update(double delta_time, sf::RenderWindow& window, size_t window_width, size_t window_height)
{
    for (auto it = level.begin(); it != level.end(); )
    {
        Grunt* grunt = dynamic_cast<Grunt*>(*it);
        Player* player = dynamic_cast<Player*>(*it);

        if (grunt)
        {
            if (grunt -> is_dead())
            {
                grunt->set_texture(dead_grunt_texture);
                grunt->set_speed(0);
                grunt->set_rotation_speed(0);
                grunt->set_attack_speed(0);
                dead_entities.push_back(grunt);

                it = level.erase(it);
                delete grunt;
                continue;
            }
            else
            {
                grunt->update(delta_time, window_width, window_height);
            }
        }
        else if (player)
        {
            player->update(delta_time, window, window_width, window_height);
        }

        ++it; // Increment iterator
    }
}
