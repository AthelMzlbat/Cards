#include <iostream>
#include "Deck.h"

using namespace std;

void printMainMenu();
void createEmptyDeck(Deck& deck, bool& deckCreated);
void compareCards();
void addCardsToDeck(Deck& deck);
void removeCardsFromDeck(Deck& deck);
void viewCardsInDeck(const Deck& deck);
void viewCardAtIndex(const Deck& deck);
void replaceCardInDeck(Deck& deck);
void printDeck(const Deck& deck);
void deleteDeck(Deck& deck, bool& deckCreated);

int main() {
    Deck deck;
    bool deckCreated = false;
    int choice;
    do {
        printMainMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                createEmptyDeck(deck, deckCreated);
                break;
            case 2:
                compareCards();
                break;
            case 3:
                addCardsToDeck(deck);
                break;
            case 4:
                removeCardsFromDeck(deck);
                break;
            case 5:
                viewCardsInDeck(deck);
                break;
            case 6:
                viewCardAtIndex(deck);
                break;
            case 7:
                replaceCardInDeck(deck);
                break;
            case 8:
                printDeck(deck);
                break;
            case 9:
                deleteDeck(deck, deckCreated);
                break;
            case 10:

                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

    } while (choice != 10);

    return 0;
}

void printMainMenu() {
    cout << "Menu:" << endl;
    cout << "1. Build Empty Deck" << endl;
    cout << "2. Compare Cards" << endl;
    cout << "3. Add Cards" << endl;
    cout << "4. Remove Cards" << endl;
    cout << "5. Look at Top Cards" << endl;
    cout << "6. Card at" << endl;
    cout << "7. Swap Card" << endl;
    cout << "8. Print Deck" << endl;
    cout << "9. Delete Deck" << endl;
    cout << "10. Exit" << endl;
}

void createEmptyDeck(Deck& deck, bool& deckCreated) {
    if (deckCreated) {
        cout << "Deck already exists" << endl;
    } else {
        deck = Deck();
        deckCreated = true;
    }
}


void compareCards() {
    char rank1, suit1, rank2, suit2;
    string op;

    cin >> rank1 >> suit1;
    cin >> rank2 >> suit2;
    cin >> op;

    Card card1(rank1, suit1);
    Card card2(rank2, suit2);

    bool result;

    if (op == "<") {
        result = (card1 < card2);
    } else if (op == ">") {
        result = (card1 > card2);
    } else if (op == "<=") {
        result = (card1 <= card2);
    } else if (op == ">=") {
        result = (card1 >= card2);
    } else if (op == "==") {
        result = (card1 == card2);
    } else if (op == "!=") {
        result = (card1 != card2);
    } else {
        cout << "Invalid comparison operator." << endl;
        return;
    }

    cout << (result ? "True" : "False") << endl;

}

void addCardsToDeck(Deck& deck) {
    int numCardsToAdd;
    cin >> numCardsToAdd;
    if (numCardsToAdd < 0) {
        cout << "Invalid number" << endl;
        return;
    }
    for (int i = 0; i < numCardsToAdd; ++i) {
        char rank, suit;
        cin >> suit >> rank;
        Card newCard(rank, suit);
        deck.addCard(newCard);
    }
}

void removeCardsFromDeck(Deck& deck) {
    int numCardsToRemove;
    cin >> numCardsToRemove;
    if (numCardsToRemove < 0) {
        cout << "Invalid number" << endl;
        return;
    }
    deck -= numCardsToRemove;
}

void viewCardsInDeck(const Deck& deck) {
    int numCardsToView;
    cin >> numCardsToView;

    if (numCardsToView < 0) {
        cout << "Invalid number" << endl;
        return;
    }
    int maxIndex = min(numCardsToView - 1, deck.getSize() - 1); // Calculate the maximum valid index
    for (int i = maxIndex; i >= 0; --i) {
        cout << deck[i] << endl;
    }
}


void viewCardAtIndex(const Deck& deck) {
    int index;
    cin >> index;

    try {
        cout << deck[index] << endl;
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
    }
}

void replaceCardInDeck(Deck& deck) {
    int index;
    cin >> index;
    try {
        char rank, suit;
        cin >> suit >> rank;
        Card newCard(rank, suit);
        deck.replaceCard(index, newCard);
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
    }
}

void printDeck(const Deck& deck) {
    deck.printDeck();
}

void deleteDeck(Deck& deck, bool& deckCreated) {
    deck = Deck();
    deckCreated = false;

}