/* 
 * File:   hand.h
 * Author: Junhwan Lee
 *
 * Created on April 19, 2021, 9:48 PM
 */
#include "Deck.h"
#ifndef HAND_H
#define HAND_H

class Hand{
public:    
    vector<Card> hand;
    int handSize;
    int sum ;
    Hand();
    void addCard(Deck&);
    void clearHand(Deck &);
    void prntHands() const;
    void evaluate();
    int getSum();
};


#endif /* HAND_H */

