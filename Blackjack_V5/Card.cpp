/* 
 * File:   Card.cpp
 * Author: Junhwan Lee
 * Purpose: Card.cpp file
 * Created on April 21, 2021, 11:30 PM
 */

// Card file containing ranks/suits array and various functions

#include "Card.h"

// Declare string arrays converting integer to string
string Card:: ranks[13] = {"ACE", "TWO", "THREE", "FOUR","FIVE", "SIX", "SEVEN", 
                                      "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING"};
string Card:: suits[4] = {"SPADES", "HEARTS", "DIAMONDS", "CLUBS"};

// Constructor
Card::Card(int rank, int suit){
    this->rank = rank;
    this->suit = suit;
}

// Print a single card
void Card::prntCard() const{
    // Print a string
    std::cout<< ranks[rank] + " of " + suits[suit]<<std::endl;
}

ostream& operator<<(ostream &out, const Card &c) {
  return out << Card::ranks[c.rank] << " of " << Card::suits[c.suit] << "\n";
}