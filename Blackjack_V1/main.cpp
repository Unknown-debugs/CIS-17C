/* 
 * File:   main.cpp
 * Author: Junhwan Lee
 * Purpose: create a deck of cards
 * Created on April 14, 2021, 12:31 PM
 */

#include "Deck.h"
#include "Hand.h"

using namespace std;

int main() {
    Deck d;
    d.shuffleDeck();
    d.prntDeck();
    Hand h(d,1);
    h.prntHands();
    
    return 0;
}

