#pragma once
#include "abstract_game_state.h"



class Menu_State : public Abstract_Game_State
{
    public:
    Menu_State();
    ~Menu_State();

    void update(double delta_time, sf::RenderWindow& window, size_t window_width, size_t window_height) override;
    void render(sf::RenderWindow& window) override;
    void draw_specified(int amount);
    void set_resume();
    bool get_resume();


    private:
    sf::Vector2i mouse_pos;
    void add(std::string const& text, sf::Vector2f temp);
    bool resume;
    struct Entry
    {
        sf::Text text;
        sf::Vector2f size;
        sf::RectangleShape hitbox{size};
    };
    std::vector<Entry> entries;
    sf::Font font;
};