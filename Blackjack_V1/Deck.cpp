
#include "Deck.h"
#include <ctime>


//Constructor will produce a new deck of cards and arrange them in sequence

Deck::Deck() {
    deck.reserve(DECK_SIZE);
    for (int i = 0; i < SUIT_SIZE; i++) {
        for (int j = 0; j < RANK_SIZE; j++) {
            Card card(j, i);
            deck.push_back(card);
        }
    }
    this->topCard = 0;
}


//Shuffle the vector of cards

void Deck::shuffleDeck() {
    //Random time seed
    srand(time(NULL));
    cout << "Shuffling Deck:\n" << endl;
    //Algorithm random shuffle implemented
    random_shuffle(deck.begin(), deck.end());
    this->topCard = 0;
}

void Deck::removeCard(){
    deck.erase(deck.begin());
}

Card Deck::dealCard(){
    if(deck.size() == 0){
        throw runtime_error("No more cards left in the deck");
    }
    return this->deck[this->topCard++];
}

void Deck::prntDeck(){
    for(Card c : deck){
        c.prntCard();
    }
}