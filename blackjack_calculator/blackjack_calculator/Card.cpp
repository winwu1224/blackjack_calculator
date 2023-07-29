// Card.cpp
#include "Card.hpp"

Card::Card(char card) : card_(card) { }

int Card::GetValue() const {
    if (card_ >= '2' && card_ <= '6') {
        return 1;
    } else if (card_ == '7' || card_ == '8' || card_ == '9') {
        return 0;
    } else {
        return -1;
    }
}
