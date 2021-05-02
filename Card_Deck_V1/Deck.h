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
#include <cstdlib>

using namespace std;

class Deck{
    vector<Card> cards;
    string card_backs;
};

#endif /* DECK_H */

