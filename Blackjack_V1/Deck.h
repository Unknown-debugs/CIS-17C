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
    int topCard;
    
    // Max values 
    const int DECK_SIZE = 52;
    const int RANK_SIZE = 13, SUIT_SIZE = 4;
    
    Deck();
    
    std::vector<Card> deck;
    int currentCard;
    void shuffleDeck();
    Card dealCard();
    void removeCard();
    void prntDeck();
};


#endif /* DECK_H */

