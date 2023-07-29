// Strategy.cpp
#include "Strategy.hpp"
#include <unordered_map>
#include <iostream>

std::string Strategy::BasicStrategy(Card player_card1, Card player_card2, Card dealer_card) {
    int player_sum = 0;
    bool has_ace = false;
    bool is_pair = false;

    if (player_card1.GetValue() == 'A' || player_card2.GetValue() == 'A') {
        has_ace = true;
    }

    if (player_card1.GetValue() == player_card2.GetValue() && !has_ace) {
        is_pair = true;
    }

    // Calculate player hand value
    for (Card card : {player_card1, player_card2}) {
        player_sum += card.GetValue();
    }

    if (player_sum > 21 && has_ace) {
        player_sum -= 10;
    }

    // Strategy for pairs
    if (is_pair) {
        std::string pair_rank(1, player_card1.GetValue());
        std::unordered_map<std::string, std::string> pair_strategy = {
            {"22", "h"}, {"33", "h"}, {"44", "h"}, {"55", "h"}, {"66", "h"},
            {"77", "h"}, {"88", "s"}, {"99", "s"}, {"TT", "s"}, {"JJ", "s"},
            {"QQ", "s"}, {"KK", "s"}, {"AA", "s"}};

        auto it = pair_strategy.find(pair_rank);
        if (it != pair_strategy.end()) {
            std::string move = it->second;
            return move == "h" ? "Hit" : move == "s" ? "Stand" : "Split";
        }
    }

    // Strategy for soft hands
    if (has_ace) {
        std::unordered_map<int, std::string> soft_strategy = {
            {13, "h"}, {14, "h"}, {15, "h"}, {16, "h"},
            {17, "h"}, {18, "ds"}, {19, "ds"}, {20, "ds"}, {21, "ds"}};

        auto it = soft_strategy.find(player_sum);
        if (it != soft_strategy.end()) {
            std::string move = it->second;
            return move == "h" ? "Hit" : move == "s" ? "Stand" : "Double/Surrender";
        }
    }

    // Strategy for hard hands
    std::unordered_map<int, std::string> hard_strategy = {
        {4, "h"},  {5, "h"},  {6, "h"},  {7, "h"},  {8, "h"},
        {9, "h"},  {10, "dh"}, {11, "dh"}, {12, "h"}, {13, "h"},
        {14, "h"}, {15, "h"}, {16, "h"}, {17, "h"}, {18, "s"},
        {19, "s"}, {20, "s"}, {21, "s"}};

    auto it = hard_strategy.find(player_sum);
    if (it != hard_strategy.end()) {
        std::string move = it->second;
        return move == "h" ? "Hit" : "Stand";
    }

    return "Unknown Move";
}
