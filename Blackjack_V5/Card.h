/* 
 * File:   Card.h
 * Author: Junhwan Lee
 * Purpose: Create a card class
 * Created on April 14, 2021, 12:31 PM
 */

#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>

using std::string;
using std::ostream;

// A single card object

class Card {
private:
    // Rank and Suit represent numbers
    int rank;
    int suit;
public:    
    // Constructor
    Card(int, int);
    
    // Ranks array declared with size of 13
    static string ranks[13];
    
    // Suits array declared with size of 4
    static string suits[4];
    
    // Print a card
    void prntCard() const;
    
    // Return Rank
    int getRank(){ return rank;}
    
    // Overload << operator
    friend ostream& operator<<(ostream&, const Card&);
};
#endif /* CARD_H */

