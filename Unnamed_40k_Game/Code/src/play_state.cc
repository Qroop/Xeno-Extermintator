#include "play_state.h"
#include "wall.h"
#include "player.h"
#include "grunt.h"
#include "enemy.h"
#include "projectile.h"

#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>


Play_State::Play_State(sf::RenderWindow& window)
: Abstract_Game_State{window}, level{}
{
    grunt_texture.loadFromFile("../Static/Textures/grunt_texture.png");
    player_texture.loadFromFile("../Static/Textures/player_texture.png");
    wall_texture.loadFromFile("../Static/Textures/wall_texture.png");
    dead_grunt_texture.loadFromFile("../Static/Textures/dead_grunt_texture.png");
    projectile_texture.loadFromFile("../Static/Textures/projectile_texture.png");
    dead_projectile_texture.loadFromFile("../Static/Textures/dead_projectile_texture.png");
    fire_texture.loadFromFile("../Static/Textures/fire.png");
}

Play_State::~Play_State()
{
    level.clear();
}

// Creates a vector containing all game objects
void Play_State::load(std::string file_name)
{
    std::ifstream fs;
    fs.open("../Static/Levels/" + file_name);

    if (!fs.is_open())
    {
        std::cerr << "Error: no file with such name";
    }
    
    if(!dead_entities.empty())
    {
        dead_entities.clear();
    }

    std::vector<std::shared_ptr<Game_Object>> loaded;
    std::vector<std::shared_ptr<Enemy>> loaded_enemies;

    if (!dead_entities.empty()) dead_entities.clear();

    sf::Vector2f coords{16, 16};
    player_pointer = std::make_unique<Player>(coords, player_texture, window, 3, 1, 200, fire_texture);
    loaded.push_back(player_pointer);
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
            {
                auto grunt = std::make_shared<Grunt>(coords, grunt_texture, window, projectile_texture, 3, 1, 50, *loaded[0]);
                loaded.push_back(grunt);
                loaded_enemies.push_back(grunt);
                coords.x += 32;
                break;
            }
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

    Player* player = dynamic_cast<Player*>(loaded[0].get());
    if (player) {
        player->set_enemies(enemies);
    }

    for (auto& enemy : loaded_enemies)
    {
        enemy->set_enemies(projectiles_to_add);
    }

    // enemy_count = enemies.size();
    
    enemies = std::move(loaded_enemies);
    level = std::move(loaded);
}


void Play_State::render()
{
    for (const auto& current_object : dead_entities)
    {
        current_object->draw();
    }
    for (const auto& curr_object : level)
    {
        curr_object->draw();
    }
}


void Play_State::update(double delta_time)
{
    for (auto it = level.begin(); it != level.end(); )
    {
        Player* player = dynamic_cast<Player*>(it->get());
        Grunt* grunt = dynamic_cast<Grunt*>(it->get());
        Projectile* projectile = dynamic_cast<Projectile*>(it->get());
        if (player)
        {
            player->update(delta_time);
            auto player_bounds = player->get_global_bounds();
            for (auto it_temp = level.begin() ; it_temp != level.end() ; it_temp++)
            {
                if ( player_bounds.intersects((*it_temp)->get_global_bounds()) )
                {
                    player->handle_collision(*it_temp);
                }
            }
        }
        if(grunt)
        {
            if(grunt -> is_dead())
            {
                grunt->kill_entity(dead_grunt_texture);
                dead_entities.push_back(std::move(*it));
                level.erase(it);
            }
            else
            {
                grunt->update(delta_time);
            }
        }
        if(projectile)
        {
            projectile -> update(delta_time);
        }
        ++it;
    }

    for (auto it = enemies.begin(); it != enemies.end(); )
    {
        if ((*it)->is_dead())
        {
            it = enemies.erase(it);
        }
        else
        {
            ++it;
        }
    }

    for (auto it = projectiles_to_add.begin(); it != projectiles_to_add.end(); )
    {
        level.push_back(std::move(*it));
        it = projectiles_to_add.erase(it);
    }

}

int Play_State::get_enemy_count()
{
    return enemies.size();
}

bool Play_State::get_player_dead()
{
    return player_pointer -> is_dead();
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

void Play_State::set_player_dead()
{
    player_pointer -> take_damage(100000);
}