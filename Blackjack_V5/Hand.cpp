/* 
 * File:   hand.h
 * Author: Junhwan Lee
 * Purpose: Create hand class containing vector of cards
 * Created on April 19, 2021, 9:48 PM
 */

#include "Hand.h"

// Constructor
Hand::Hand() {
    sum = 0;
    handSize = 0;
}

// Print hand
void Hand::prntHands() const {
    // Print each card in the vector using iterator
    for (Card c : hand) {
        // rank + suit
        c.prntCard();
    }
}

// Add a card into the hand using the deck(used for hits)
void Hand::addCard(Deck& d) {
    
    // Initialize a card and equal to the top of the deck
    Card card = d.dealCard();
    
    // Push the card into the hand
    hand.push_back(card);
    
    // Remove a top card from the deck
    d.removeCard();
    
    // Increment the size of hand by one
    handSize++;
}

// Determine the sum of cards on hand
void Hand::evaluate() {
    // Clear sum
    sum = 0;
    
    // Declare boolean value ACE
    bool Ace;
    
    // Iterate through each card in hand
    for (Card c : hand) {
        
        // If ACE found, add eleven to sum
        if (c.getRank() == 0) {
            sum += 11;
            Ace = true;
        }
        // If face cards, add ten to sum
        else if (c.getRank() > 9) {
            sum += 10;
        } 
        // If normal number cards, add their ranks
        else {
            sum += c.getRank() + 1;
        }
    }
    
    // If the sum exceeds 21 and Ace is contained in the hand
    if (sum > 21 && Ace) {
        // Ace is treated as one instead of eleven
        sum -= 10;
    }
}

// Return sum of hand
int Hand::getSum() {
    return sum;
}

// Dealer specialized evaluation
void Hand::dealerEval() {
    // Clear sum
    sum = 0;
    // Iterate through each card in hand
    for (Card c : hand) {
        // Add eleven if Ace
        if (c.getRank() == 0) {
            sum += 11;
        }
        // If face cards, add ten to sum
        else if (c.getRank() > 9) {
            sum += 10;
        } 
        // If normal number cards, add their ranks
        else {
            sum += c.getRank() + 1;
        }
    }
}

// Clear hand
void Hand::clearHand(Deck &d) {
    // Move back the cards from hand to the deck
    for (int i = 0; i < handSize; i++) {
        Card card = hand.front();
        d.addBack(card);
    }
    // Clear sum and cards in the hand
    sum = 0;
    hand.clear();
}