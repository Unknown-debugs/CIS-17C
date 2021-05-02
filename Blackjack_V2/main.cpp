/* 
 * File:   main.cpp
 * Author: Junhwan Lee
 * Purpose: create a deck of cards
 * Created on April 14, 2021, 12:31 PM
 */

#include "Deck.h"
#include "Hand.h"

using namespace std;

void setDeck(Deck &);
    
void setDeck(Deck &deck){
    int n = 0;
    deck.shuffleDeck();
    deck.deckSize();
    cout<<"Where to cut?\n";
    cout<<"Enter between 75 and 60 cards to discard from the deck\n";
    cin>>n;
    while(!deck.cutDeck(n)){
        cout<<"Invalid cut spot"<<endl;
        cin>>n;
    }
    deck.deckSize();
}

int main() {
    Deck d;
    setDeck(d);
    Hand h;
    h.addCard(d);
    h.addCard(d);
    h.evaluate();
    
    h.prntHands();
    d.deckSize();
    h.clearHand(d);    
    d.combDeck();
    d.deckSize();
    return 0;
}

