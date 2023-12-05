#include "classes.h"
#include <fstream>
#include <iostream>

//Play_State::Play_State() {};




// std::vector<Game_Object*> Play_State::load(std::string file_name)
// {
//     std::ifstream fs;
//     fs.open("../Static/" + file_name);

//     if (!fs.is_open())
//     {
//         std::cerr << "Error: no file with such name";
//     }
//     std::vector<Game_Object*> level;
//     sf::Vector2f coords;
//     while ( !fs.eof() )
//     {
//         char character = fs.get();
//         switch(character)
//         {
//             case '#':
//                 level.push_back(new Wall(coords));
//                 coords.x += 32;
//                 break;
//             case '@':
//                 level.push_back(new Player(coords));
//                 coords.x += 32;
//                 break;
//             case 'X':
//                 level.push_back(new Enemy(coords));
//                 coords.x += 32;
//                 break;
//             case '\n':
//                 coords.y += 32;
//                 coords.x = 0;
//                 break;
//             case ' ':
//                 coords.x += 32;
//                 break;
//         }
//     }

//     sf:
// }