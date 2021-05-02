/* 
 * File:   hand.h
 * Author: Junhwan Lee
 *
 * Created on April 19, 2021, 9:48 PM
 */
#include "Deck.h"
#ifndef HAND_H
#define HAND_H
#include <map>

using std::map;
using std::vector;

class Hand{
public:    
    vector<Card> hand;

    Hand(Deck &, int); 
    void prntHands() const;
};


#endif /* HAND_H */

