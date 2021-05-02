/* 
 * File:   Dealer.h
 * Author: Junhwan Lee
 * Purpose: Create a dealer
 * Created on April 21, 2021, 11:13 PM
 */

#ifndef DEALER_H
#define DEALER_H
#include "Hand.h"

// Create a dealer class extending Hand class

class Dealer : public Hand {
private:
    string face;
public:
    Dealer();
    // Display a dealer
    void prntDealer();
    // Reveal first card
    void RevealFirstCard();
};
#endif /* DEALER_H */

