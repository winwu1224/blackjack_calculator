// Game.cpp
#include "Game.hpp"
#include <iostream>
#include <cmath>

Game::Game(int initial_decks) :
    card_values({
        {'2', 1}, {'3', 1}, {'4', 1}, {'5', 1}, {'6', 1},
        {'7', 0}, {'8', 0}, {'9', 0},
        {'T', -1}, {'J', -1}, {'Q', -1}, {'K', -1}, {'A', -1}
    }),
    remaining_cards(initial_decks * 52),
    running_count(0) { }

void Game::Run() {
    std::string input;

    while (true) {
        std::cout << "Enter your two cards, dealer's face-up card, or 'q' to quit: ";
        std::cin >> input;

        if (input == "q") {
            break;
        }

        Card player_card1(input[0]);
        Card player_card2(input[1]);
        Card dealer_card(input[2]);

        running_count += card_values[player_card1.GetValue()];
        running_count += card_values[player_card2.GetValue()];
        running_count += card_values[dealer_card.GetValue()];

        remaining_cards -= 3;

        double true_count = static_cast<double>(running_count) / ceil(remaining_cards / 52.0);

        std::string recommended_move = Strategy::BasicStrategy(player_card1, player_card2, dealer_card);

        std::cout << "Running count: " << running_count << std::endl;
        std::cout << "True count: " << true_count << std::endl;
        std::cout << "Recommended move: " << recommended_move << std::endl;
    }
}
