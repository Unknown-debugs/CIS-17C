
#include "Hand.h"

Hand::Hand(Deck& deck, int n){
    for (int i = 0; i < n; i++) {
        hand.push_back(deck.dealCard()); 
        deck.removeCard();
    }
}

void Hand::prntHands() const{
    cout<<"Cards on hands:\n";
    for(Card c : hand){
        c.prntCard();
    }
}
