
#ifndef ATHEEL_CARDGAME_CARD_H
#define ATHEEL_CARDGAME_CARD_H


#include <iostream>

class Card {
private:
    char rank;
    char suit;
    int value;

public:
    Card();
    Card(char rank, char suit);

    bool operator==(const Card& other) const;
    bool operator!=(const Card& other) const;
    bool operator<(const Card& other) const;
    bool operator<=(const Card& other) const;
    bool operator>(const Card& other) const;
    bool operator>=(const Card& other) const;

    Card& operator=(const Card& other);

    friend std::ostream& operator<<(std::ostream& os, const Card& card);
};

#endif //ATHEEL_CARDGAME_CARD_H
