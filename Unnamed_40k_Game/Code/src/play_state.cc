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
: level{}
{
    grunt_texture.loadFromFile("../Static/Textures/grunt_texture.png");
    player_texture.loadFromFile("../Static/Textures/player_texture.png");
    wall_texture.loadFromFile("../Static/Textures/wall_texture.png");
    dead_grunt_texture.loadFromFile("../Static/Textures/dead_grunt_texture.png");
    projectile_texture.loadFromFile("../Static/Textures/projectile_texture.png");
    dead_projectile_texture.loadFromFile("../Static/Textures/dead_projectile_texture.png");
}

Play_State::~Play_State()
{}

// Creates a vector containing all game objects
void Play_State::load(std::string file_name, int window_width, int window_height)
{
    std::ifstream fs;
    fs.open("../Static/Levels/" + file_name);

    if (!fs.is_open())
    {
        std::cerr << "Error: no file with such name";
    }
    
    std::vector<std::shared_ptr<Game_Object>> loaded;
    std::vector<std::shared_ptr<Enemy>> loaded_enemies;

    sf::Vector2f coords{16, 16};
    loaded.push_back(std::make_shared<Player>(coords, player_texture, 3, 1, 200, window_width, window_height));
    while ( !fs.eof() )
    {
        char character = fs.get();
        switch(character)
        {
            case '#':   // Wall
                loaded.push_back(std::make_shared<Wall>(coords, wall_texture));
                coords.x += 32;
                break;
            case '@':   // Player
                loaded[0]->set_coordinates(coords);
                coords.x += 32;
                break;
            case 'X':   // Grunt
            {
                auto grunt = std::make_shared<Grunt>(coords, grunt_texture, projectile_texture, 3, 1, 50, window_width, window_height,*loaded[0]);
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
    
    std::cerr << loaded_enemies.size() << "\n";

    Player* player = dynamic_cast<Player*>(loaded[0].get());
    if (player) {
        player->set_enemies(enemies);
        std::cerr << "Player: "<< player->check_set_enemies();
    }

    for (auto& enemy : loaded_enemies)
    {
        enemy->set_enemies(projectiles_to_add);
        std::cerr << "Enemy: " << enemy -> check_set_enemies();
    }

    enemies = std::move(loaded_enemies);
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
}


void Play_State::update(double delta_time, sf::RenderWindow& window)
{
    for (auto it = level.begin(); it != level.end(); )
    {
        Player* player = dynamic_cast<Player*>(it->get());
        Grunt* grunt = dynamic_cast<Grunt*>(it->get());
        if (player)
        {
            player->update(delta_time, window);
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

    std::cerr << "Amount of enemies in the vector: " << enemies.size() << "\n";
}