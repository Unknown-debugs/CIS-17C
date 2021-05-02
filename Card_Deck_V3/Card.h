/* 
 * File:   Card.h
 * Author: Junhwan Lee
 * Purpose: Create a card class
 * Created on April 14, 2021, 12:31 PM
 */

#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>

using namespace std;

// Enumerate  rank and suit 

enum Rank {
    ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
};

enum Suit {
    SPADES, HEARTS, DIAMONDS, CLUBS
};
static const char *Suit_String[] = {"SPADES", "HEARTS", "DIAMONDS", "CLUBS"};
// A single card object

struct Card {
    Rank rank;
    Suit suit;

    void prntCard() {
        cout << "Rank: " << rank;
        cout << " Suit: " << toString(suit);
        cout << endl;
    };

    string toString(int suit) {
        string tmp(Suit_String[suit]);
        return tmp;
    }
};



#endif /* CARD_H */

