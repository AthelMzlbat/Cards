#include "Card.h"

using namespace std;

Card::Card() : rank(' '), suit(' '), value(0) {}

Card::Card(char rank, char suit) : rank(rank), suit(suit) {
    switch (rank) {
        case 'A':
            value = 1;
            break;
        case 'J':
            value = 10;
            break;
        case 'Q':
            value = 15;
            break;
        case 'K':
            value = 20;
            break;
        case 'T':
            value = 10;
            break;
        default:
            if (rank >= '2' && rank <= '9') {
                value = rank - '0';
            }
    }
}

bool Card::operator==(const Card& other) const {
    if ((rank == 'J' && other.rank == 'T') || (rank == 'T' && other.rank == 'J'))
        return false; // 'J' and 'T' are not equal
    else
        return (rank == other.rank && suit == other.suit);
}

bool Card::operator!=(const Card& other) const {
    return !(*this == other);
}


bool Card::operator<(const Card& other) const {
    if (rank == 'J' && other.rank == 'T')
        return false;
    else if (rank == 'T' && other.rank == 'J')
        return true;
    else if (value != other.value)
        return value < other.value;
    else
        return suit < other.suit;
}

bool Card::operator<=(const Card& other) const {
    return (*this < other || *this == other);
}

bool Card::operator>(const Card& other) const {
    return !(*this <= other);
}

bool Card::operator>=(const Card& other) const {
    return !(*this < other);
}


Card& Card::operator=(const Card& other) {
    if (this != &other) {
        rank = other.rank;
        suit = other.suit;
        value = other.value;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Card& card) {
    os << card.suit << card.rank;
    return os;
}