#include "abstract_game_state.h"

#include <map>

class game_engine
{
public:
    game_engine(/* args */);
    ~game_engine();

    void run();
    void quit();
    void change_state();
    int get_state();

private:
    std::map<Abstract_Game_State*, bool> states;
    bool running;
    Abstract_Game_State* active_state;
};
