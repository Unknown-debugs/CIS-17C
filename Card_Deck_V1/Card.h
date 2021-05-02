/* 
 * File:   Card.h
 * Author: Junhwan Lee
 * Purpose: Create a card class
 * Created on April 14, 2021, 12:31 PM
 */

#ifndef CARD_H
#define CARD_H

// Enumerate  rank and suit 
enum Rank { ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
enum Suit { SPADES, HEARTS, DIAMONDS, CLUBS};           

// A single card object
struct Card{
    Rank rank;
    Suit suit;
};

#endif /* CARD_H */

