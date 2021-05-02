/* 
 * File:   Deck.h
 * Author: Junhwan Lee
 * Purpose: Deck of card object
 * Created on April 14, 2021, 12:33 PM
 */

#ifndef DECK_H
#define DECK_H
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "Card.h"


class Deck {
private:
    vector<Card> *cards;
    string card_backs;
    // Max values 
    const int DECK_SIZE = 52;
    const int RANK_SIZE = 13, SUIT_SIZE = 4;
public:
    Deck();
    ~Deck();
    void prntDeck();
    //void initDeck();
    void shuffleDeck();
};


#endif /* DECK_H */

