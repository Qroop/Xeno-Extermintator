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

// Creates a vector containing all game objects
void Play_State::load(std::string const& file_name)
{
    std::ifstream fs;
    fs.open("../Static/" + file_name);

    if (!fs.is_open())
    {
        std::cerr << "Error: no file with such name";
    }
    
    std::vector<Game_Object*> loaded;
    sf::Vector2f coords{16, 16};
    loaded.push_back(new Player(coords, 3, 1, 300));
    // Player& player_object = dynamic_cast<Player&> (loaded[0]);
    while ( !fs.eof() )
    {
        char character = fs.get();
        switch(character)
        {
            case '#':   // Wall
                loaded.push_back(new Wall(coords));
                coords.x += 32;
                break;
            case '@':   // Player
                loaded[0]->set_coordinates(coords);
                coords.x += 32;
                break;
            case 'X':   // Grunt
                loaded.push_back(new Grunt(coords, 3, 1, 50, dynamic_cast<Player&> (*loaded[0]))); // dynamic_cast<Player&>(*loaded[0])
                coords.x += 32;
                break;
            case '\n':
                coords.y += 32;
                coords.x = 16;
                break;
            case ',':   // Whitespace
                coords.x += 32;
                break;
        }
    }
    fs.close();
    
    level = loaded;
}


void Play_State::render(sf::RenderWindow & window) 
{
    for (Game_Object* curr_object : level)
    {
        curr_object -> draw(window);
        
    }
}

void Play_State::update(double delta_time, sf::RenderWindow& window, size_t window_width, size_t window_height)
{
    for (Game_Object* object : level)
    {
        Grunt* grunt = dynamic_cast<Grunt*> (object);
        Player* player = dynamic_cast<Player*> (object);
        if (grunt)
        {
            grunt -> update(delta_time, window_width, window_height);
        }
        else if(player)
        {
            player -> update(delta_time, window, window_width, window_height);
        }
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