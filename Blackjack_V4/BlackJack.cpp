#include "BlackJack.h"


using namespace std;

void BlackJack::setDeck(int n) {
    n = 0;
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

void BlackJack::storeName() {
    string nm;
    char c;
    cout << "Enter player name: ";
    cin>>nm;
    if(profiles.find(nm) != profiles.end()){
        cout << "The name already exists!" << endl;
        cin>>nm;
    }
    player.setName(nm);
    profiles[nm] = player.getCash();
}

bool BlackJack::switchPlayer(string nm){
    if(profiles.find(nm) != profiles.end()){
        clearRound();
        player.setCash(profiles[nm]);
        return true;
    }
    else{
        cout<<"No name exists!"<<endl;
        return false;
    }
}

void BlackJack::findCash() {
    string nm;
    cout << "Enter player name to view remaining cash" << endl;
    cin>>nm;
    while (profiles.find(nm) == profiles.end()) {
        cout << "No name found " << endl;
        cin>>nm;
    }
    cout << nm << "'s remaining cash: $" << profiles[nm];

}

void BlackJack::dealCardsto() {

    player.addCard(deck);
    dealer.addCard(deck);
    player.addCard(deck);
    dealer.addCard(deck);

 

    dealer.dealerEval();

}

void BlackJack::prntTable() {
    dealer.prntDealer();
    cout << endl;
    cout << "Here is your hand: " << endl;
    player.prntHands();
    cout << "Dealer Reveals First Card: ";
    dealer.RevealFirstCard();
    cout << endl;


}

void BlackJack::displayStats() {
    for (auto it = profiles.begin(); it != profiles.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
}

int BlackJack::checkSum() {
    player.evaluate();
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

void BlackJack::checkWins() {
    switch (checkSum()) {
        case 1: player.WinOrLose(true);
            cout << "\nWon\n" << endl;
            player.setCash(1.5 * player.getBet());
            profiles.at(player.getName()) = player.getCash();
            scores.push(1);
            break;

        case 0: player.WinOrLose(false);
            cout << "\nLost\n" << endl;
            profiles.at(player.getName()) = player.getCash();
            scores.push(2);
            break;

        case 3: cout << "\nDraw\n" << endl;
            player.setCash(player.getBet());
            profiles.at(player.getName()) = player.getCash();
            scores.push(3);
            break;
    }
    cout << "Dealer reveals his cards: " << endl;
    dealer.prntHands();

}

void BlackJack::hitMe(){
    cout<<"\nDealer hands you a card :)"<<endl;
    player.addCard(deck);
    player.prntHands();
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

    while (dealer.getSum() < 17) {
        cout << "Dealer Draws A card" << endl;
        dealer.addCard(deck);
        dealer.dealerEval();
    }

    dealer.evaluate();
}

bool BlackJack::betting(int bet) {

    if (bet > player.getCash()) {
        cout <<" ლ(ಠ益ಠლ) Screams: "<<setw(5)<< "You don't have that much money!" << endl;
        cout <<" ლ(ಠ益ಠლ) Says: "<<setw(5)<< "You have $" << player.getCash() << endl;
        return false;
    }

    player.setBet(bet);
    player.setCash(-player.getBet());
    return true;
}

void BlackJack::clearRound(){
    player.clearHand(deck);
    player.reset();
}