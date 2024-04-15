
#ifndef ATHEEL_CARDGAME_DECK_H
#define ATHEEL_CARDGAME_DECK_H

#include "Card.h"

class Deck {
private:
    Card* cards;
    int capacity;
    int size;

public:
    Deck();

    ~Deck();

    void addCard(const Card& card);

    void addCards(const Card* newCards, int numCards);

    const Card& operator[](int index) const;

    void replaceCard(int index, const Card& newCard);

    void printDeck() const;

    int getSize() const;

    void operator+=(const Card& card);

    void operator+=(const Card* newCards);

    void operator-=(int numCards);
};

#endif //ATHEEL_CARDGAME_DECK_H
