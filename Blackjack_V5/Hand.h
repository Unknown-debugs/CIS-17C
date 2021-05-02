/* 
 * File:   hand.h
 * Author: Junhwan Lee
 * Purpose: Create hand class containing vector of cards
 * Created on April 19, 2021, 9:48 PM
 */

#include "Deck.h"
#ifndef HAND_H
#define HAND_H

// Hand containing cards
// Extended to dealer and player classes

class Hand {
public:
    // Vector of cards
    std::vector<Card> hand;
    // Size and sum of hand
    int handSize;
    int sum;

    // Constructor
    Hand();
    // Insert a card to hand
    void addCard(Deck&);
    // Clear hand
    void clearHand(Deck &);
    // Display cards in hand
    void prntHands() const;
    // Evaluate/calculate the sum
    void evaluate();
    // Special evaluation for dealer
    void dealerEval();
    // Return sum of cards
    int getSum();
};
#endif /* HAND_H */

