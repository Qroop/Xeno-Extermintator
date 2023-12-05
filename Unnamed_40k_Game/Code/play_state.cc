#include "classes.h"
#include "play_state.h"
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>


Play_State::Play_State()
    :level{}
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
                level.push_back(new Wall(coords));
                coords.x += 32;
                break;
            case '@':
                level.push_back(new Player(coords));
                coords.x += 32;
                break;
            case 'X':
                level.push_back(new Enemy(coords));
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
void Play_State::render() const
{
    for (Game_Object* curr_object : level)
    {
        Entity* entity = dynamic_cast<Entity*> (curr_object);
        Wall* wall = dynamic_cast<Wall*> (curr_object);
        if (entity)
        {
            //entity -> update();
            Enemy* enemy = dynamic_cast<Enemy*> (entity);
            Player* player = dynamic_cast<Player*> (entity);
            if (enemy)
            {
                std::cout << "it is enemy" << std::endl;
            }
            else if ( player )
            {
                std::cout << "it is player" << std::endl;
            }
        }
        else if (wall)
        {
            std::cout << "it is wall" << std::endl;
        }
    }
}
