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
#include <cstdlib>
#include "Card.h"

using namespace std;

class Deck {
public:
    // Collection of cards
    std::vector<Card> deck;
    std::vector<Card> trash;
    
    // Top card in the deck
    int topCard;
    int size = 52;
    // Max values 
    const int RANK_SIZE = 13, SUIT_SIZE = 4;
    
    Deck();
    void shuffleDeck();
    Card dealCard();
    void removeCard();
    void prntDeck() const;
    void deckSize() const;
    void addBack(Card&);
    bool cutDeck(int);
    void combDeck();
};


#endif /* DECK_H */

