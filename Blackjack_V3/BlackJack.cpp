#include "BlackJack.h"
#include <bits/stdc++.h>
using namespace std;

void BlackJack::setDeck() {
    int n = 0;
    deck.shuffleDeck();
    deck.deckSize();
    cout << "Where to cut? ";
    cout << "Enter between 75 and 60 cards to discard from the deck\n";
    cin>>n;
    while (!deck.cutDeck(n)) {
        cout << "Invalid cut spot" << endl;
        cin>>n;
    }
    deck.deckSize();
}

void BlackJack::setName(string nm) {
    player.setName(nm);
    profiles[player.getName()] = player.getCash();
}

int BlackJack::findCash(string nm){
    if(profiles.find(nm) == profiles.end()){
        cout<<"No name found "<<endl;
        return 0;
    }
    else{
        return profiles[nm];
    }
    
}

void BlackJack::dealCardsto() {


    player.addCard(deck);
    dealer.addCard(deck);
    player.addCard(deck);
    dealer.addCard(deck);


    player.evaluate();

    dealer.dealerEval();


    while (dealer.getSum() < 17) {
        dealer.addCard(deck);
        dealer.dealerEval();
    }

    dealer.evaluate();
}

void BlackJack::prntTable() {
    dealer.prntDealer();
    dealer.RevealFirstCard();
    player.prntHands();

}

void BlackJack::displayStats() {
    cout << player.getName() << " " << profiles[player.getName()];
}

int BlackJack::checkSum() {
    int winCounter = 0;
    int pSum = player.getSum();
    int dSum = dealer.getSum();
    if (pSum > 21 || dSum > 21) {
        if (pSum < 21) {
            winCounter++;
            return winCounter;
        }
    } else if (pSum > dSum) {
        winCounter++;
        return winCounter;
    } else if (pSum == dSum) {
        winCounter += 2;
        return winCounter;
    } else {
        return winCounter;
    }

}

int BlackJack::checkWins() {
    switch (checkSum()) {
        case 1: player.WinOrLose(true);
            cout << "Won" << endl;
            dealer.prntHands();
            scores.push(1);
            return 1;
        case 0: player.WinOrLose(false);
            cout << "Lost" << endl;
            dealer.prntHands();
            scores.push(2);
            return 2;
        case 3: cout << "Draw" << endl;
            scores.push(3);
            return 3;
    }
    return -1;
}

void BlackJack::prntScores() {
    std::queue<int> q = scores;
    int i = 0;
    while (!q.empty()) {
        cout << "Round " << i + 1 << " ";
        if (q.front() == 1) {
            cout << "Won" << endl;
        } else if (q.front() == 2) {
            cout << "Lost" << endl;
        } else {
            cout << "Draw" << endl;
        }
        q.pop();
        i++;
    }
}

void BlackJack::dealDealer() {
    if (dealer.getSum() < player.getSum()) {
        while (dealer.getSum() < 17) {
            dealer.addCard(deck);
        }

    }
    dealer.evaluate();
}

