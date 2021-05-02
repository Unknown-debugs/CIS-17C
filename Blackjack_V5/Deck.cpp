/* 
 * File:   Deck.h
 * Author: Junhwan Lee
 * Purpose: Deck of card object
 * Created on April 14, 2021, 12:33 PM
 */

#include "Deck.h"
#include <ctime>
#include <iomanip>

using namespace std;
//Constructor will produce a new deck of cards and arrange them in sequence

Deck::Deck() {
    deck.clear();
    // Uses 6 decks or 312 cards combined
    // Reserve enough space for vector beforehand
    deck.reserve(size * 2);
    for (int i = 0; i < 6; i++) {
        for (int i = 0; i < SUIT_SIZE; i++) {
            for (int j = 0; j < RANK_SIZE; j++) {
                Card card(j, i); // Declare a card
                deck.push_back(card); // Insert a card in the deck
            }
        }
    }
}

//Shuffle the vector of cards

void Deck::shuffleDeck() {
    //Random time seed
    srand(time(NULL));
    cout << "***| " << setw(42) << "(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧ Shows:" << setw(7) << "" << "Shuffling Deck~~" << endl;
    //Algorithm random shuffle implemented
    random_shuffle(deck.begin(), deck.end());
}

// Delete a single card from the top of the deck 

void Deck::removeCard() {
    deck.erase(deck.begin());
}

// Get a card on the top of the deck

Card Deck::dealCard() {

    // Throw an exception when there is no more card left on the deck
    if (deck.size() == 0) {
        throw runtime_error("No more cards left in the deck");
    }
    return this->deck[0];
}

// Print every cards in the deck

void Deck::prntDeck() const {
    for (Card c : deck) {
        c.prntCard();
    }
}

// Return the size of the deck

int Deck::deckSize() const {
    return deck.size();
}

// Return the size of the trash deck

int Deck::trashSize() const {
    return trash.size();
}

// Cut deck

bool Deck::cutDeck(int mid) {
    // Invalid cut spot
    // Must in between 75 and 60 to discard
    if (mid > 75 || mid < 60) {
        return false;
    } else {
        // trash stack filled
        for (int i = 0; i < mid; i++) {
            trash.push(deck.at(i));
            // Delete elements starting at cut spot
            deck.erase(deck.end() + mid);
        }
        return true;
    }
}

// Combine trash and deck 

void Deck::combDeck() {

    while(!trash.empty()){
        deck.push_back(trash.top());
        trash.pop();
    }

}

// Push a specific card back to the deck

void Deck::addBack(Card& c) {
    deck.push_back(c);
}