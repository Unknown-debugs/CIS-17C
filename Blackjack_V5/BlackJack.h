/* 
 * File:   BlackJack.h
 * Author: Junhwan Lee
 * Purpose: Create a game of BlackJack
 * Created on April 21, 2021, 11:30 PM
 */

#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <queue>
#include <map>
#include <set>
#include "Dealer.h"
#include "Player.h"


// using standard
using std::queue;
using std::map;
using std::set;

// BlackJack game

class BlackJack {
private:
    // Initialize dealer and player
    Dealer dealer;
    Player player;
    // Create a deck
    Deck deck;
    int startCash;
    // Count number of wins
    int winCounter;
    // Initialize dealer and player sum
    int dealer_Sum, player_Sum;
public:
    
    BlackJack();
    // Queue scores
    queue<int> scores;
    // Set rounds
    set<int> rounds;
    // Map profiles
    map<string, int> profiles;

    // Distribute cards from the deck
    void dealCardsto();
    void dealDealer();

    // Initialize deck
    void setDeck();

    // Display profiles
    void displayStats();

    // Switch to new player or existing player
    void switchPlayer(string);
    // Store a new player profiles
    void storeName();
    // Display cash for a specific player
    void findCash();
    // Give cash to player
    void giveCash(bool);

    // Betting table
    bool betting(int);

    // hit action taken
    void hitMe();

    // Print cards on the table
    void prntTable();

    // Print scores from each round
    void prntScores();

    // Compare sums
    void checkSum();
    // Check for BlackJack
    void checkBlackJack();
    // Check win or lose
    void checkWins();

    // Clear round for next round
    void clearRound();
    
    void prntMessage(int);
};
#endif /* BLACKJACK_H */

