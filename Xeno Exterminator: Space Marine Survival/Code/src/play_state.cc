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
{}


void Play_State::load(std::string const& file_name)
{
    std::ifstream fs;
    alive_entities.clear();
    fs.open("../Static/Levels/" + file_name);

    if (!fs.is_open())
    {
        throw std::invalid_argument("Error: no file with such name");
    }
    
    if(!dead_entities.empty())
    {
        dead_entities.clear();
    }

    std::vector<std::shared_ptr<Game_Object>> loaded;
    std::vector<std::shared_ptr<Enemy>> loaded_enemies;

    if (!dead_entities.empty()) dead_entities.clear();

    sf::Vector2f coords{16, 16};
    player_pointer = std::make_unique<Player>(coords, player_texture, window, 7, 1, 275, fire_texture);
    loaded.push_back(player_pointer);
    alive_entities.push_back(player_pointer);
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
                auto grunt = std::make_shared<Grunt>(coords, grunt_texture, window, projectile_texture, 3, 1, 40, *loaded[0]);
                loaded.push_back(grunt);
                alive_entities.push_back(grunt);
                loaded_enemies.push_back(grunt);
                coords.x += 32;
                break;
            }
            case '\n':
                coords.y += 32;
                coords.x = 16;
                break;
            default :   // Anything else
                coords.x += 32;
                break;
        }
    }
    fs.close();

    player_pointer -> set_enemies(enemies);

    for (auto& enemy : loaded_enemies)
    {
        enemy->set_enemies(projectiles_to_add);
    }

    enemies = std::move(loaded_enemies);
    level = std::move(loaded);
}


void Play_State::render()
{
    for (const auto& current_object : dead_entities)
    {
        current_object->draw();
    }
    for (const auto& current_object : level)
    {
        current_object->draw();
    }
}


void Play_State::update(double const delta_time)
{
    for (auto entity : alive_entities)
    {
        if(entity -> is_dead())
        {
            dead_entities.push_back(entity);
            entity -> kill_entity(dead_grunt_texture);
        }
        else
        {
            entity -> update(delta_time);
            auto entity_bounds{entity -> get_global_bounds()};
            for(auto it = level.begin() ; it != level.end() ; it++)
            {
                if(entity_bounds.intersects((*it) -> get_global_bounds()))
                {
                    entity -> handle_collision(*it);
                }
            }
        }
    }

    for (auto it = enemies.begin(); it != enemies.end(); )
    {
        if ((*it)->is_dead())
        {
            enemies.erase(it);
        }
        else
        {
            ++it;
        }
    }

    if(!projectiles_to_add.empty())
    {
        for (auto it = projectiles_to_add.begin(); it != projectiles_to_add.end(); )
        {
        level.push_back(*it);
        alive_entities.push_back(*it);
        it = projectiles_to_add.erase(it);
        }   
    }

    alive_entities.erase(std::remove_if(alive_entities.begin(), alive_entities.end(),
    [](std::shared_ptr<Entity> const& entity)
    {
        return entity -> is_dead();
    }),
    alive_entities.end());

    level.erase(
    std::remove_if(level.begin(), level.end(), 
        [](std::shared_ptr<Game_Object> const& enemy)
        {
            if (std::shared_ptr<Enemy> to_remove = std::dynamic_pointer_cast<Enemy> (enemy))
            return to_remove->is_dead();
            else return false;
        }),
    level.end());

    // std::cerr << get_player_dead() << "\n";
    // std::cerr << "Amount of entities: " << alive_entities.size() << "\n";
}


int Play_State::get_enemy_count() const
{
    return enemies.size();
}


bool Play_State::get_player_dead() const
{
    return player_pointer -> is_dead();
}


int Play_State::get_change() const
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