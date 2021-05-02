/* 
 * File:   BlackJack.h
 * Author: Junhwan Lee
 *
 * Created on April 21, 2021, 11:30 PM
 */

#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <queue>
#include <map>
#include "Dealer.h"
#include "Player.h"



class BlackJack{
private:
    Dealer dealer;
    Player player;
    Deck deck;
    
public:
    int winCounter;
    std::queue<int> scores;
    std::map<string, int> profiles;
    
    void dealCardsto();
    void dealDealer();
    int compareSum();
    void setDeck();
    void displayStats();
    
    void setName(string);
    int findCash(string nm);
    
    void prntTable();
    void prntScores();
    int checkSum();
    int checkWins();
};




#endif /* BLACKJACK_H */

