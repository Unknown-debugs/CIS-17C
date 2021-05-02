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
#include <iomanip>
#include "Dealer.h"
#include "Player.h"

using std::queue;
using std::map;

class BlackJack{
private:
    Dealer dealer;
    Player player;
    Deck deck;
    
public:
    int winCounter;
    queue<int> scores;
    map<string, int> profiles;
    
    void dealCardsto();
    void dealDealer();
    
    
    void setDeck(int);
    void displayStats();
    
    bool switchPlayer(string);
    void storeName();
    void findCash();
    
    bool betting(int);

    
    void prntTable();
    void prntScores();
    int checkSum();
    void checkWins();
    void hitMe();
    
    void clearRound();
};

#endif /* BLACKJACK_H */

