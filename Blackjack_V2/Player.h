/* 
 * File:   Player.h
 * Author: junhw
 *
 * Created on April 21, 2021, 8:36 PM
 */

#ifndef PLAYER_H
#define PLAYER_H
#include <set>
#include <string>
#include <map>

#include "Hand.h"

class Player : public Hand{
private:
    string name;
    int cash, bet;
    int wins, loses;
public:    
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
    void WinOrLose(bool);
    void prntPlayer();
};



#endif /* PLAYER_H */

