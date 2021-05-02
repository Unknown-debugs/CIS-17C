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
public:
    int rank;
    int suit;
    
    Card(int, int);
    static string ranks[13];
    static string suits[4];
    void prntCard() const;
    friend ostream& operator<<(ostream&, const Card&);
      
};


#endif /* CARD_H */

