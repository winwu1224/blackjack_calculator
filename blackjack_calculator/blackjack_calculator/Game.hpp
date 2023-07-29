// Game.hpp

#include "Strategy.hpp"
#include <unordered_map>

class Game {
public:
    Game(int initial_decks);
    void Run();

private:
    std::unordered_map<char, int> card_values;
    int remaining_cards;
    int running_count;
};
