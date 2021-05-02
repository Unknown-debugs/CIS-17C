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
    
    string name;
    cout<<"Enter player name: ";
    cin>>name;
    bj.setName(name);
    bj.displayStats();
    
    
    bj.setDeck();
    bj.dealCardsto();
    
    
    bj.prntTable();
    bj.checkSum();
    bj.checkWins();
    bj.prntScores();
    string nm;
    cout<<"Enter player name to view remaining cash"<<endl;
    cin>>nm;
    cout<<bj.findCash(nm);
    return 0;
}

