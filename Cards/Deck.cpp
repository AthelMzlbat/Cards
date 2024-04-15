#include "Deck.h"
#include <iostream>
#include <stdexcept>

using namespace std;

// Constructor
Deck::Deck() : cards(nullptr), capacity(0), size(0) {}


// Destructor
Deck::~Deck() {
    delete[] cards;
}

void Deck::addCard(const Card& card) {
    // Resize array if necessary
    if (size >= capacity) {
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        Card* temp = new Card[newCapacity];
        for (int i = 0; i < size; ++i) {
            temp[i] = cards[i];
        }
        delete[] cards;
        cards = temp;
        capacity = newCapacity;
    }
    // Shift existing cards to make space for the new card
    for (int i = size; i > 0; --i) {
        cards[i] = cards[i - 1];
    }
    cards[0] = card; // Add the new card at the top of the deck
    size++;
}

void Deck::addCards(const Card* newCards, int numCards) {
    for (int i = 0; i < numCards; ++i) {
        addCard(newCards[i]);
    }
}

const Card& Deck::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("Invalid index");
    }
    return cards[index];
}

void Deck::replaceCard(int index, const Card& newCard) {
    if (index < 0 || index >= size) {
        throw out_of_range("Invalid index");
    }
    cards[index] = newCard;
}

void Deck::printDeck() const {
    if (size == 0) {
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    for (int i = 0; i < size-1; ++i) {
        cout << cards[i] << ",";
    }
    cout << cards[size - 1] << "]" << endl;
}

int Deck::getSize() const {
    return size;
}

void Deck::operator+=(const Card& card) {
    addCard(card);
}

void Deck::operator+=(const Card* newCards) {
    addCards(newCards, 1);
}

void Deck::operator-=(int numCards) {
    if (numCards >= size) {
        size = 0;
    } else {
        for (int i = size - numCards; i > 0; --i) {
            cards[i] = cards[i + numCards];
        }
        size -= numCards;
    }
}







