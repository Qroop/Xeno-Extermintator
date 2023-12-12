#include "abstract_game_state.h"
#include <SFML/Graphics.hpp>

class Game_Over_State : public Abstract_Game_State
{
    public:
    Game_Over_State(int level_count);
    ~Game_Over_State();
    
    void update(double delta_time, sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;
    void set_win( bool win );
    int get_change() override;
    void decision_handling(sf::RenderWindow& window);

    private:
    int level_count;
    int current_level_index;
    int decision;
    sf::Font font;
    std::string instructions;
    std::array<sf::Text, 4> text;
    // bool win_or_lose;
};