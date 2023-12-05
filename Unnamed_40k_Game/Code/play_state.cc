#include "play_state.h"
#include "wall.h"
#include "player.h"
#include "grunt.h"
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>


Play_State::Play_State()
    :level{}
{}

Play_State::~Play_State()
{}

//creates a vector containing all game objects
void Play_State::load(std::string file_name)
{
    std::ifstream fs;
    fs.open("../Static/" + file_name);

    if (!fs.is_open())
    {
        std::cerr << "Error: no file with such name";
    }
    std::vector<Game_Object*> loaded;
    sf::Vector2f coords;
    while ( !fs.eof() )
    {
        char character = fs.get();
        switch(character)
        {
            case '#':
                loaded.push_back(new Wall(coords, 32, 32));
                coords.x += 32;
                break;
            case '@':
                loaded.push_back(new Player(coords, 32, 32, 3, 1, 1));
                coords.x += 32;
                break;
            case 'X':
                loaded.push_back(new Grunt(coords, 32, 32, 3, 1, 1));
                coords.x += 32;
                break;
            case '\n':
                coords.y += 32;
                coords.x = 0;
                break;
            case ' ':
                coords.x += 32;
                break;
        }
    }
    fs.close();
    level = loaded;
}

//std::vector<Game_Object*> const& objects
void Play_State::render(sf::RenderWindow & window) 
{
    for (Game_Object* curr_object : level)
    {
        curr_object -> render(window);
        
    }
}
// Entity* entity = dynamic_cast<Entity*> (curr_object);
        // Wall* wall = dynamic_cast<Wall*> (curr_object);
        // if (entity)
        // {
        //     //entity -> update();
        //     Enemy* enemy = dynamic_cast<Enemy*> (entity);
        //     Player* player = dynamic_cast<Player*> (entity);
        //     if (enemy)
        //     {
        //         std::cout << "it is enemy" << std::endl;
        //     }
        //     else if ( player )
        //     {
        //         std::cout << "it is player" << std::endl;
        //     }
        // }
        // else if (wall)
        // {
        //     std::cout << "it is wall" << std::endl;
        // }