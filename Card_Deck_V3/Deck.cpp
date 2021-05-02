/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Deck.h"

//Constructor will produce a new deck of cards and arrange them in sequence

Deck::Deck() {
    cards = new std::vector<Card>();
    cards->reserve(DECK_SIZE);
    Card card;
    for (int suit = 0; suit < SUIT_SIZE; suit++) {
        for (int rank = 0; rank < RANK_SIZE; rank++) {
            card.suit = Suit(suit);
            card.rank = Rank(rank);
            cards->push_back(card);
        }
    }
}

//Destructor

Deck::~Deck() {
    delete cards;
}

//Print vector of cards

void Deck::prntDeck() {
    for (Card c : *cards)
        c.prntCard();
}

//Shuffle the vector of cards

void Deck::shuffleDeck() {
    //Random time seed
    srand(time(NULL));
    //Algorithm random shuffle implemented
    random_shuffle(cards->begin(), cards->end());
}


