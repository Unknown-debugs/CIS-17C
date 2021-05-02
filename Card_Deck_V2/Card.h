/* 
 * File:   Card.h
 * Author: Junhwan Lee
 * Purpose: Create a card class
 * Created on April 14, 2021, 12:31 PM
 */

#ifndef CARD_H
#define CARD_H
#include <iostream>

using namespace std;

// Enumerate  rank and suit 
enum Rank { ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
enum Suit { SPADES, HEARTS, DIAMONDS, CLUBS};           

// A single card object
struct Card{
    Rank rank;
    Suit suit;
    void prntCard();
};

void Card::prntCard(){
    cout << "Rank: "<< rank;
    cout << " Suit: "<<suit;
    cout<<endl;
}

#endif /* CARD_H */

