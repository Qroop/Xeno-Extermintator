// #include "menu_state.h"

// Menu_State::Menu_State()
// :resume{false}
// {
//     font.loadFromFile("../Textures/font.ttf");
//     sf::Vector2f temp{450, 60};

//     entries.push_back( {sf::Text{"Resume", font, 60 }, temp} );
//     entries.push_back( {sf::Text{"New Game", font, 60}, temp} );
//     entries.push_back( {sf::Text{"Exit", font, 60}, temp} );

//     add("Resume", temp);
//     add("New Game", temp);
//     add("Exit", temp);
// }

// void Menu_State::add(std::string const& text, sf::Vector2f temp)
// {
//     entries.push_back( {sf::Text{text, font, 60 }, temp} );
// }

// Menu_State::~Menu_State()
// {}

// void Menu_State::set_resume()
// {
//     resume = true;
// }

// void Menu_State::update(double delta_time, sf::RenderWindow& window, size_t window_width, size_t window_height)
// {
//     mouse_pos = sf::Mouse::getPosition(window);
//     //if (entries[0].hitbox.)
    
// }

// void Menu_State::render(sf::RenderWindow& window) 
// {
//     if (resume == true) draw_specified(3);
//     else draw_specified(2);
    
// }

// void Menu_State::draw_specified(int amount)
// {
//     int parameter{1024/(amount + 2)};
//     int y_coord{parameter};
//     int counter{};
//     if ( amount == 2)
//     {
//         counter++;
//         amount++;
//     }
//     while ( counter < amount )
//     {
//         entries[counter].hitbox.setPosition(sf::Vector2f(512, y_coord));
//         entries[counter].text.setPosition(sf::Vector2f(512, y_coord));
//         y_coord += parameter;
//         counter++;
//     }

// }