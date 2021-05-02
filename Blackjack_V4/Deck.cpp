
#include "Deck.h"
#include <ctime>


//Constructor will produce a new deck of cards and arrange them in sequence

Deck::Deck() {
    // Uses 6 decks or 312 cards combined
    size = size * 6;
    // Reserve enough space for vector beforehand
    deck.reserve(size);
    for (int i = 0; i < 6; i++) {
        for (int i = 0; i < SUIT_SIZE; i++) {
            for (int j = 0; j < RANK_SIZE; j++) {
                Card card(j, i); // Declare a card
                deck.push_back(card); // Insert a card in the deck
            }
        }
    }
    this->topCard = 0;
}

//Shuffle the vector of cards

void Deck::shuffleDeck() {
    //Random time seed
    srand(time(NULL));
    //Algorithm random shuffle implemented
    random_shuffle(deck.begin(), deck.end());
    this->topCard = 0;
}

void Deck::removeCard() {
    deck.erase(deck.begin());
}

Card Deck::dealCard() {
    if (deck.size() == 0) {
        throw runtime_error("No more cards left in the deck");
    }
    return this->deck[this->topCard++];
}

void Deck::prntDeck() const {
    for (Card c : deck) {
        c.prntCard();
    }
}

void Deck::deckSize() const {
    int counter = 0;
    for (Card c : deck) {
        counter++;
    }
}

bool Deck::cutDeck(int mid) {
    // Invalid cut spot
    // Must in between 75 and 60 to discard
    if (mid > 75 || mid < 60) {
        return false;
    }
    else {
        trash.reserve(mid);
        // trash stack filled
        for (int i = 0; i < mid; i++) {
            trash.push_back(deck[i]);
            // Delete elements starting at cut spot
            deck.erase(deck.end() + mid);
        }
        return true;
    }
}

void Deck::combDeck() {
    vector<Card> ::iterator itr;
    for (itr = trash.begin(); itr != trash.end(); ++itr) {
        deck.push_back(*itr);
    }
}

void Deck::addBack(Card& c){
    deck.push_back(c);
}