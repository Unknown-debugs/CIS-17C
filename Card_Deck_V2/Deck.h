/* 
 * File:   Deck.h
 * Author: Junhwan Lee
 * Purpose: Deck of card object
 * Created on April 14, 2021, 12:33 PM
 */

#ifndef DECK_H
#define DECK_H
#include <vector>
#include <string>
#include <algorithm>
#include "Card.h"

using namespace std;
// Max values 
const int DECK_SIZE = 52;
const int RANK_SIZE = 13, SUIT_SIZE = 4;

class Deck{
private:
    vector<Card> cards;
    string card_backs;
public:
    void prntDeck(const Deck&);
    void initDeck();
};

void Deck:: initDeck(){
    Card card;
    for(int suit = 0; suit < SUIT_SIZE; suit++){
        for(int rank = 0; rank < RANK_SIZE; rank++){
            card.suit = Suit(suit);
            card.rank = Rank(rank);
            cards.push_back(card);
        }
    }
}


void Deck::prntDeck(const Deck& deck){
    
    for(Card c : deck.cards)
        c.prntCard();
    
}
#endif /* DECK_H */

