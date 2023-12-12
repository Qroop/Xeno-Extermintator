#include "play_state.h"
#include "wall.h"
#include "player.h"
#include "grunt.h"
#include "enemy.h"

#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>


Play_State::Play_State()
{
    grunt_texture.loadFromFile("../Static/Textures/grunt_texture.png");
    player_texture.loadFromFile("../Static/Textures/player_texture.png");
    wall_texture.loadFromFile("../Static/Textures/wall_texture.png");
    dead_grunt_texture.loadFromFile("../Static/Textures/dead_grunt_texture.png");
}

Play_State::~Play_State()
{
    level.clear();
}

// Creates a vector containing all game objects
void Play_State::load(std::string const& file_name, sf::RenderWindow& window)
{
    std::ifstream fs;
    fs.open("../Static/Levels/" + file_name);

    if (!fs.is_open())
    {
        std::cerr << "Error: no file with such name";
    }
    
    std::vector<std::shared_ptr<Game_Object>> loaded;
    // std::vector<std::shared_ptr<Enemy>> loaded_enemies;

    sf::Vector2f coords{16, 16};
    player_object = std::make_shared<Player>(coords, player_texture, window, 3, 1, 200);
    loaded.push_back(player_object);
    while ( !fs.eof() )
    {
        char character = fs.get();
        switch(character)
        {
            case '#':   // Wall
                loaded.push_back(std::make_shared<Wall>(coords, wall_texture, window));
                coords.x += 32;
                break;
            case '@':   // Player
                loaded[0]->set_coordinates(coords);
                coords.x += 32;
                break;
            case 'X':   // Grunt
                enemies.push_back(std::make_shared<Grunt>(coords, grunt_texture, dead_grunt_texture, window, 3, 1, 50, *loaded[0]));
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
    
    std::shared_ptr<Player> player = std::static_pointer_cast<Player>(loaded[0]);
    if (player) {
        player->set_enemies(enemies);
    }

    // for (auto& enemy : enemies)
    // {
    //     Grunt* grunt = dynamic_cast<Grunt*>(enemy.get());
    //     if (grunt) {
    //         grunt->set_enemies(enemies);
    //     }
    // }

    // enemy_count = enemies.size();
    level = std::move(loaded);
}


void Play_State::render(sf::RenderWindow& window)
{
    for (const auto& current_object : dead_entities)
    {
        current_object->draw(window);
    }
    for (const auto& curr_object : level)
    {
        curr_object->draw(window);
    }
    for (const auto& current_enemy : enemies)
    {
        current_enemy -> draw(window);
    }
}


void Play_State::update(double delta_time, sf::RenderWindow& window)
{
    auto it = level.begin();
    for ( std::shared_ptr<Game_Object> i : level )
    {
        i->update(delta_time);
        if ( i -> is_dead() )
        {
            dead_entities.push_back(i);
            level.erase(it);
        }
        it++;
    }
    auto enemy_it = enemies.begin();
    for ( std::shared_ptr<Grunt> i : enemies )
    {
        i->update(delta_time);
        if ( i -> is_dead() )
        {
            dead_entities.push_back(i);
            enemies.erase(enemy_it);
        }
        enemy_it++;
    }
}

int Play_State::get_enemy_count()
{
    return enemies.size();
}

bool Play_State::get_player_dead()
{
    return player_object -> is_dead();
}

int Play_State::get_change()
{
    if ( get_enemy_count() == 0)
    {
        return 1;
    }
    else if ( get_player_dead() == true )
    {
        return 2;
    }
    else
    {
        return 0;
    }
}