/* 
 * File:   main.cpp
 * Author: Junhwan Lee
 * Purpose: create a deck of cards
 * Created on April 14, 2021, 12:31 PM
 */

#include "BlackJack.h"

using namespace std;

int main() {

    BlackJack bj;

    
    bj.storeName();
    bj.displayStats();

    int n;
    cin>>n;
    bj.setDeck(n);
    bj.dealCardsto();


    bj.prntTable();

    int bet = 0;
    cout << "Enter the amount of cash to bet: ";
    cin>>bet;
    while (!bj.betting(bet)) {
        cout << "Enter the amount of cash to bet: ";
        cin>>bet;
    }
    bj.hitMe();
    bj.dealDealer();
    bj.checkSum();
    bj.checkWins();

    bj.prntScores();
    bj.clearRound();

    bj.storeName();
    bj.displayStats();
    bj.findCash();
    return 0;
}

