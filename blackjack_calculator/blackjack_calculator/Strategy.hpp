// Strategy.hpp
#include "Card.hpp"
#include <iostream>

class Strategy {
public:
    static std::string BasicStrategy(Card player_card1, Card player_card2, Card dealer_card);
};
