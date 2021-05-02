/* 
 * File:   Game.h
 * Author: Junhwan Lee
 * Purpose: Game of BlackJack sequence
 * Created on April 23, 2021, 11:23 AM
 */

#include "Game.h"

using namespace std;

// Display header

void Game::header() {
    char c;
    cout << " /$$$$$$$  /$$                     /$$                /$$$$$                     /$$      \n";
    cout << "| $$__  $$| $$                    | $$               |__  $$                    | $$      \n";
    cout << "| $$  | $$| $$  /$$$$$$   /$$$$$$$| $$   /$$            | $$  /$$$$$$   /$$$$$$$| $$   /$$\n";
    cout << "| $$$$$$$ | $$ |____  $$ /$$_____/| $$  /$$/            | $$ |____  $$ /$$_____/| $$  /$$/\n";
    cout << "| $$__  $$| $$  /$$$$$$$| $$      | $$$$$$/        /$$  | $$  /$$$$$$$| $$      | $$$$$$/ \n";
    cout << "| $$  | $$| $$ /$$__  $$| $$      | $$_  $$       | $$  | $$ /$$__  $$| $$      | $$_  $$ \n";
    cout << "| $$$$$$$/| $$|  $$$$$$$|  $$$$$$$| $$ |  $$      |  $$$$$$/|  $$$$$$$|  $$$$$$$| $$ |  $$\n";
    cout << "|_______/ |__/|________/|________/|__/  |__/      |_______/ |________/|________/|__/ |___/\n";
    cout << endl;
    cout << "Welcome to Blackjack!" << endl;
    cout << "Would you like to read the instruction?[Y/N]: ";
    cin >> c;
    
    while( c != 'Y' && c != 'N'){
        cout<<"Invalid selection. Would you like to read the instruction?[Y/N]: ";
        cin>> c;
    }
    // If user wants to read instruction, 
    if (c == 'Y') {
        cout << "\nMake fortune with your luck and decision making skill\n";
        cout << "================================PLAY===============================\n";
        cout << "Six decks are combined to form a single deck in the game.Dealer    \n";
        cout << "asks  user to cut the deck ranging from 60 to 75 cards from top.   \n";
        cout << "The game is played with the remaining cards.A player and dealer    \n";
        cout << "are given two cards from the deck. A single card from dealer's     \n";
        cout << "hand is revealed while player's cards are only revealed to player. \n";
        cout << "If dealer's sum of cards are less than 17, dealer must draw a card \n";
        cout << "until it reaches 17 or over. Player are asked to either stand or   \n";
        cout << "hit. If hit, the player adds a card from the deck to his/her hand  \n";
        cout << "as many as desired. If stand, keep the hand, then evaluate       \n";
        cout << "=============================OBJECTIVE=============================\n";
        cout << "Each card has its rank. The sum of cards mean the sum of ranks.    \n";
        cout << "If the sum exceeds 21 it means 'bust' and it is an automatic lose  \n";
        cout << "The player wins if the sum of players is greater than the dealer's \n";
        cout << "sum. \n";
        cout << "================================BET================================\n";
        cout << "Win = 1.5 times the original bet \n";
        cout << "Lose = loses the amount of bet placed  \n";
        cout << "Draw = take back the amount of bet placed \n";
        cout << "=====================================================================\n";
        cout << endl;
    }
    cout << endl;
}

// Betting phase

void Game::begin_betting() {
    int bet = 0;
    // Ask player for amount of bet
    cout << "Enter the amount of cash to bet: ";
    cin>>bet;
    // If bet is over cash, ask for bet again
    while (!bj.betting(bet)) {
        cout << "Enter the amount of cash to bet: ";
        cin>>bet;
    }
}

// Display profiles

void Game::showList() {
    bj.displayStats();
}

// Display cash remaining

void Game::getCash() {
    bj.findCash();
}

// Display score per round

void Game::listScores() {
    bj.prntScores();
}

// Register a new player

void Game::registerPlayer() {
    bj.storeName();
}

// For returning player

void Game::retPlayer() {

    // Ask for a player name
    string nm;
    cout << "Enter your name: ";
    cin>> nm;

    // Switch player before playing game
    bj.switchPlayer(nm);
}

// Early game

void Game::beginGame() {
    // Shuffle, cut deck
    bj.setDeck();

    // Distribute cards
    bj.dealCardsto();

    // Print hands
    bj.prntTable();
}

// Begin hit or stand phase

void Game::begin_dealing() {

    // User choice
    char choice;
    do {
        // Ask player to hit or stand
        cout << "Would you like to Hit or Stand [H/S] ";
        cin>>choice;

        // Input validation
        while (choice != 'H' && choice != 'S') {
            cout << "That is not a valid choice!!" << endl;
            cout << "Would you like to Hit or Stand [H/S] ";
            cin>>choice;
        }

        // If a player hits
        if (choice == 'H') {
            // Give a card to player
            bj.hitMe();
        }
    } while (choice != 'S'); // Repeat until player chooses to stand

    cout << endl;

    // Dealer may draw cards
    bj.dealDealer();


    // Compare sum
    bj.checkSum();

    cout << endl;
    // Check for black jack
    bj.checkBlackJack();

    // Check win or lost
    bj.checkWins();
    cout << endl;
}

// Clear round

void Game::endRound() {
    bj.clearRound();
}

// Display menu

void Game::menu() {
    cout << "\n1. Start a game\n";
    cout << "2. Display all player's information.\n";
    cout << "3. Find cash with player name.\n";
    cout << "4. Display player's game history.\n";
    cout << "5. Register new player.\n";
    cout << "6. Exit game.\n" << "Your choice: ";
}

