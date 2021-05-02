/* 
 * File:   Game.h
 * Author: Junhwan Lee
 * Purpose: Game of BlackJack sequence
 * Created on April 23, 2021, 11:23 AM
 */

#ifndef GAME_H
#define GAME_H
#include "BlackJack.h"

// Game Structure class
class Game {
private:
    // Initialize the game of BlackJack
    BlackJack bj;
public:
    
    // Display header and rules
    void header(); 
    
    // Display menu for players to select
    void menu();
    
    // Show player list
    void showList();
    
    // For returning player
    void retPlayer();
    
    // Register new player
    void registerPlayer();
    
    // Display cash for a player
    void getCash();
    
    // Display round results
    void listScores();
    
    // Begin dealing and betting
    void begin_dealing();
    void begin_betting();
    
    // Early game phase
    void beginGame();
    
    // Comparing sum phase
    void checkingPhase();
    
    // End round
    void endRound();
    
    // Exit game
    bool exitGame();
};
#endif /* GAME_H */

