
#include "Hand.h"

Hand::Hand() {
    sum = 0;
    handSize = 0;
}

void Hand::prntHands() const {
    cout << "Cards on hands:\n";
    for (Card c : hand) {
        c.prntCard();
    }
}

void Hand::addCard(Deck& d) {
    Card card = d.dealCard();
    hand.push_back(card);
    d.removeCard();
    handSize++;
    bool Ace;
    for (Card c : hand) {
        if (c.getRank() == 0) {
            sum += 11;
            Ace = true;
        } else {
            sum += c.getRank() + 1;
        }
    }
    // Switch Ace between 1 and 11
    if (sum > 21 && Ace) {
        sum -= 10;
    }
}

void Hand::clearHand(Deck &d) {
    for (int i = 0; i < handSize; i++) {
        Card card = hand.front();
        d.addBack(card);
        hand.erase(hand.begin());
    }
}

void Hand::evaluate() {
    sum = 0;
    bool Ace;
    for (Card c : hand) {
        if (c.getRank() == 0) {
            sum += 11;
            Ace = true;
        }
        else if(c.getRank() > 10){
            sum += 10;
        }
        else {
            sum += c.getRank() + 1;
        }
    }
    // Switch Ace between 1 and 11
    if (sum > 21 && Ace) {
        sum -= 10;
    }
}

int Hand::getSum() {
    return sum;
}

void Hand::dealerEval() {
    sum = 0;
    for (Card c : hand)
        sum += c.getRank() + 1;
}