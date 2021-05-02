/* 
 * File:   Deck.h
 * Author: Junhwan Lee
 * Purpose: Deck of card object
 * Created on April 14, 2021, 12:33 PM
 */

#ifndef DECK_H
#define DECK_H
#include <vector>
#include <algorithm>
#include <stack>
#include <cstdlib>
#include "Card.h"

// Deck object consisting of vector of cards

class Deck {
private:
    // Six decks combined 52 * 6 = 312
    const int size = 312;
    // Max values 
    const int RANK_SIZE = 13, SUIT_SIZE = 4;

public:
    // Collection of cards
    std::vector<Card> deck;

    // Collection of discarded cards
    std::stack<Card> trash;
    
    // Constructor
    Deck();

    // Functions changing deck
    void shuffleDeck();
    bool cutDeck(int);
    void combDeck();

    // Functions adding or removing card
    Card dealCard();
    void removeCard();
    void addBack(Card&);

    // Return size for deck and trash
    int deckSize() const;
    int trashSize() const;

    // Print deck
    void prntDeck() const;
};
#endif /* DECK_H */

