/* 
 * File:   Player.h
 * Author: Junhwan Lee
 * Purpose: Player object
 * Created on April 21, 2021, 8:36 PM
 */

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <map>
#include "Hand.h"

// Player class extended by hand class
class Player : public Hand{
private:
    // Initialize player name, cash, bet, and win or lose records
    string name;
    int cash, bet;
    int wins, loses;
public:    
    
    //Constructor
    Player();
    
    // Get functions
    string getName();
    int getCash();
    int getBet();
    int getWins();
    int getLoses();
    
    // Set functions
    void setName(string);
    void setCash(int);
    void setBet(int);
    
    // Determine win or lose
    void WinOrLose(bool);
    
    // Print player names and their cash
    void prntPlayer();
    
    // Reset for next player
    void reset();
};



#endif /* PLAYER_H */

