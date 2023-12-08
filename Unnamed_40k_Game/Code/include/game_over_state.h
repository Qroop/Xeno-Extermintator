#include "abstract_game_state.h"
#include <SFML/Graphics.hpp>

class Game_Over_State : public Abstract_Game_State
{
    public:
    Game_Over_State();
    ~Game_Over_State();
    
    void update(double delta_time, sf::RenderWindow& window, size_t window_width, size_t window_height) override;
    void render(sf::RenderWindow& window) override;
};