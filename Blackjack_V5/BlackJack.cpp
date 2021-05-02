/* 
 * File:   BlackJack.h
 * Author: Junhwan Lee
 * Purpose: Create a game of BlackJack
 * Created on April 21, 2021, 11:30 PM
 */

#include "BlackJack.h"
#include <iomanip>

using namespace std;

BlackJack::BlackJack() {
    startCash = 1000;
    winCounter = 0;
    player_Sum = 0;
    dealer_Sum = 0;
}

// Form a deck

void BlackJack::setDeck() {
    // Declare a variable for cut spot
    int cutSpot = 0;

    // Shuffle the deck
    deck.shuffleDeck();

    // Ask player for a cut spot
    cout << "***| " << setw(30) << "v( ‘.’ )v Asks: " << setw(33) << "Where to cut? [60 ~ 75] ";
    cin >> cutSpot;

    // Input validation
    while (!deck.cutDeck(cutSpot)) {
        cout << "Invalid cut spot. Enter between 60 - 75: ";
        cin>>cutSpot;
    }

    // Display number of cards discarded and remaining deck size
    cout << "\nDiscarded ";
    cout << deck.trashSize() << " cards.\n";
    cout << "Remaining deck size: " << deck.deckSize() << endl;
    cout << endl;

    // Combine deck
    deck.combDeck();
}

// Store a new name to the map

void BlackJack::storeName() {

    // Set cash equal to zero for new player
    player.setCash(0);

    // Ask for a name
    string nm;
    cout << "Enter player name: ";
    cin>>nm;

    // If the name already exists ask for a new name
    if (profiles.find(nm) != profiles.end()) {
        cout << "The name already exists!" << endl;
        cin>>nm;
    }

    // Store $1000 for the new name
    profiles[nm] = startCash;
}

// Switch player to play a new game with

void BlackJack::switchPlayer(string nm) {

    // Set cash to zero
    player.setCash(0);

    // If the player already exists
    if (profiles.find(nm) != profiles.end()) {

        // Set the name as that player's name
        player.setName(nm);

        // Set the cash as that player's remaining cash
        player.setCash(profiles.at(player.getName()));

    }// If the player is new
    else {
        // Set the name as that player's name
        player.setName(nm);

        // Give $1000 as the starting cash
        player.setCash(1000);

        // Register a new player into the profiles
        profiles[nm] = player.getCash();
        cout << "New Player!! $1000 is given!\n";
    }
    cout << endl;
}

// Find cash for a specific player

void BlackJack::findCash() {

    // Ask user for the name
    string nm;
    cout << "Enter player name to view remaining cash: ";
    cin>>nm;

    // If the player does not exist, ask for a name 
    while (profiles.find(nm) == profiles.end()) {
        cout << "No name found. Enter player name: ";
        cin>>nm;
    }

    // Display remaining cash
    cout << nm << "'s remaining cash: $" << profiles[nm] << endl;
    ;
}

// Distribute cards to dealer and player

void BlackJack::dealCardsto() {

    // Two cards each
    player.addCard(deck);
    dealer.addCard(deck);
    player.addCard(deck);
    dealer.addCard(deck);
    dealer.dealerEval();
}

// Print cards on the table 

void BlackJack::prntTable() {

    // Display dealer face
    dealer.prntDealer();
    cout << endl;

    // Display player's cards
    cout << "Here is your hand: " << endl;
    player.prntHands();

    // Reveal one of dealer card
    cout << "\nDealer Reveals First Card: ";
    dealer.RevealFirstCard();
    cout << endl;
}

// Print all of the player's name and cash

void BlackJack::displayStats() {
    cout << setw(7) << "Name" << setw(7) << " " << "Cash($)\n";
    cout << "---------------------------------------------------------\n";

    // Forward iterator
    for (auto it = profiles.begin(); it != profiles.end(); ++it) {
        // Display string and then integer indicating name and cash
        cout << setw(7) << it->first << setw(7) << " " << it->second << endl;
    }
}

// Compare sum of player and dealer

void BlackJack::checkSum() {
    // Evaluate player sum
    player.evaluate();

    // Clear win counts
    winCounter = 0;
    player_Sum = 0;
    dealer_Sum = 0;

    // Reveal dealer cards
    cout << "\nDealer reveals his cards.\n";
    dealer.prntHands();

    // Initialize temporary sums
    player_Sum = player.getSum();
    dealer_Sum = dealer.getSum();

    // Display sums
    cout << "\nPlayer Sum: " << player_Sum;
    cout << "\nDealer Sum: " << dealer_Sum;

    // Compare sums
    // If one of sum exceeds 21
    if (player_Sum > 21 || dealer_Sum > 21) {
        // If player sum is less than 21 indicating dealer sum is over 21
        if (player_Sum < 21) {
            // Player win
            winCounter++;
        }
    }// If player sum is greater than dealer sum
    else if (player_Sum > dealer_Sum) {
        // Player win
        winCounter++;
    }// If player sum is equal to dealer sum
    else if (player_Sum == dealer_Sum) {
        // Draw
        winCounter + 2;
    }
    // If winCounter is not incremented, player lost
}

void BlackJack::checkBlackJack() {
    cout << endl;
    if (player_Sum == 21) {
        cout << "Player has BLACK JACK\n";
        cout << "Congratulations!!\n";
        player.setCash(1.5 * player.getBet());
    }
    if (dealer_Sum == 21) {
        cout << "Dealer has BLACK JACK\n";
    }
    cout << endl;
}


// Update cash and scores

void BlackJack::checkWins() {
    cout << endl;
    // switch based on winCounter
    switch (winCounter) {
            // If won
        case 1: 
            player.WinOrLose(true); // Increment win
            // Update cash by 1.5 * the amount of bet
            player.setCash(1.5 * player.getBet());

            // Update cash in the profiles
            profiles.at(player.getName()) = player.getCash();

            // Update scores
            scores.push(1);
            break;

            // If lost
        case 0: 
            player.WinOrLose(false); // Increment lose
            // Player does not gain anything from bet
            // Update cash in the profiles
            profiles.at(player.getName()) = player.getCash();

            // Update scores
            scores.push(2);
            break;

            // If draw
        case 3: 
            // Player gets back the amount of bet back to cash
            player.setCash(player.getBet());

            // Update cash in the profiles
            profiles.at(player.getName()) = player.getCash();

            // Update scores
            scores.push(3);
            break;
    }
    prntMessage(winCounter);
    cout<<"\nYour remaining cash now is: "<<player.getCash()<<endl;
}

// Hit

void BlackJack::hitMe() {
    // Player receives a new card from the top of the deck
    cout << "\nDealer hands you a card :)" << endl;
    player.addCard(deck);

    // Print new hand
    player.prntHands();
}

// Print scores per rounds

void BlackJack::prntScores() {
    std::queue<int> q = scores;
    int i = 0;

    // Display rounds and results from each round
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

// Deal card to dealer

void BlackJack::dealDealer() {
    // If dealer sum is less than 17
    while (dealer.getSum() < 17) {
        cout << "Dealer: I have sum less than 17! I will draw a card.\n";

        //Dealer gets a card
        dealer.addCard(deck);
        dealer.dealerEval();
    }
    cout << endl;

    // Evaluate dealer cards and get sum
    dealer.evaluate();
}

// Betting phase

bool BlackJack::betting(int bet) {
    // Input validation
    if (bet > player.getCash()) {
        // If the remaining cash is less than the bet
        cout << "Invalid amount of bet.You have $" << player.getCash() << endl;
        return false;
    }

    // Update bet amount
    player.setBet(bet);
    // Subtract bet amount from cash
    player.setCash(-player.getBet());

    // Display remaining cash
    cout << "Your remaining cash($): " << player.getCash() << endl;
    return true;
}

// Clear Round

void BlackJack::clearRound() {
    // Clear hands
    player.clearHand(deck);
    dealer.clearHand(deck);
    player.reset();
}

void BlackJack::prntMessage(int result) {
    if (result == 1) {
        cout << "YYYYYYY       YYYYYYY     OOOOOOOOO     UUUUUUUU     UUUUUUUU     WWWWWWWW                           WWWWWWWW     OOOOOOOOO     NNNNNNNN        NNNNNNNN !!!  !!!\n";
        cout << "Y:::::Y       Y:::::Y   OO:::::::::OO   U::::::U     U::::::U     W::::::W                           W::::::W   OO:::::::::OO   N:::::::N       N::::::N!!:!!!!:!!\n";
        cout << "Y:::::Y       Y:::::Y OO:::::::::::::OO U::::::U     U::::::U     W::::::W                           W::::::W OO:::::::::::::OO N::::::::N      N::::::N!:::!!:::!\n";
        cout << "Y::::::Y     Y::::::YO:::::::OOO:::::::OUU:::::U     U:::::UU     W::::::W                           W::::::WO:::::::OOO:::::::ON:::::::::N     N::::::N!:::!!:::!\n";
        cout << "YYY:::::Y   Y:::::YYYO::::::O   O::::::O U:::::U     U:::::U       W:::::W           WWWWW           W:::::W O::::::O   O::::::ON::::::::::N    N::::::N!:::!!:::!\n";
        cout << "   Y:::::Y Y:::::Y   O:::::O     O:::::O U:::::D     D:::::U        W:::::W         W:::::W         W:::::W  O:::::O     O:::::ON:::::::::::N   N::::::N!:::!!:::!\n";
        cout << "    Y:::::Y:::::Y    O:::::O     O:::::O U:::::D     D:::::U         W:::::W       W:::::::W       W:::::W   O:::::O     O:::::ON:::::::N::::N  N::::::N!:::!!:::!\n";
        cout << "     Y:::::::::Y     O:::::O     O:::::O U:::::D     D:::::U          W:::::W     W:::::::::W     W:::::W    O:::::O     O:::::ON::::::N N::::N N::::::N!:::!!:::!\n";
        cout << "      Y:::::::Y      O:::::O     O:::::O U:::::D     D:::::U           W:::::W   W:::::W:::::W   W:::::W     O:::::O     O:::::ON::::::N  N::::N:::::::N!:::!!:::!\n";
        cout << "       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U            W:::::W W:::::W W:::::W W:::::W      O:::::O     O:::::ON::::::N   N:::::::::::N!:::!!:::!\n";
        cout << "       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U             W:::::W:::::W   W:::::W:::::W       O:::::O     O:::::ON::::::N    N::::::::::N!!:!!!!:!!\n";
        cout << "       Y:::::Y       O::::::O   O::::::O U::::::U   U::::::U              W:::::::::W     W:::::::::W        O::::::O   O::::::ON::::::N     N:::::::::N !!!  !!! \n";
        cout << "       Y:::::Y       O:::::::OOO:::::::O U:::::::UUU:::::::U               W:::::::W       W:::::::W         O:::::::OOO:::::::ON::::::N      N::::::::N          \n";
        cout << "    YYYY:::::YYYY     OO:::::::::::::OO   UU:::::::::::::UU                 W:::::W         W:::::W           OO:::::::::::::OO N::::::N       N:::::::N !!!  !!! \n";
        cout << "    Y:::::::::::Y       OO:::::::::OO       UU:::::::::UU                    W:::W           W:::W              OO:::::::::OO   N::::::N        N::::::N!!:!!!!:!!\n";
        cout << "    YYYYYYYYYYYYY         OOOOOOOOO           UUUUUUUUU                       WWW             WWW                 OOOOOOOOO     NNNNNNNN         NNNNNNN !!!  !!! \n";
    } else if (result == 0) {
        cout << "YYYYYYY       YYYYYYY                                     LLLLLLLLLLL                                                        tttt\n";
        cout << "Y:::::Y       Y:::::Y                                     L:::::::::L                                                     ttt:::t\n";
        cout << "Y:::::Y       Y:::::Y                                     L:::::::::L                                                     t:::::t\n";
        cout << "Y::::::Y     Y::::::Y                                     LL:::::::LL                                                     t:::::t\n";
        cout << "YYY:::::Y   Y:::::YYYooooooooooo   uuuuuu    uuuuuu         L:::::L                  ooooooooooo       ssssssssss   ttttttt:::::ttttttt\n";
        cout << "   Y:::::Y Y:::::Y oo:::::::::::oo u::::u    u::::u         L:::::L                oo:::::::::::oo   ss::::::::::s  t:::::::::::::::::t\n";
        cout << "    Y:::::Y:::::Y o:::::::::::::::ou::::u    u::::u         L:::::L               o:::::::::::::::oss:::::::::::::s t:::::::::::::::::t\n";
        cout << "     Y:::::::::Y  o:::::ooooo:::::ou::::u    u::::u         L:::::L               o:::::ooooo:::::os::::::ssss:::::stttttt:::::::tttttt\n";
        cout << "      Y:::::::Y   o::::o     o::::ou::::u    u::::u         L:::::L               o::::o     o::::o s:::::s  ssssss       t:::::t\n";
        cout << "       Y:::::Y    o::::o     o::::ou::::u    u::::u         L:::::L               o::::o     o::::o   s::::::s            t:::::t\n";
        cout << "       Y:::::Y    o::::o     o::::ou::::u    u::::u         L:::::L               o::::o     o::::o      s::::::s         t:::::t\n";
        cout << "       Y:::::Y    o::::o     o::::ou:::::uuuu:::::u         L:::::L         LLLLLLo::::o     o::::ossssss   s:::::s       t:::::t    tttttt\n";
        cout << "       Y:::::Y    o:::::ooooo:::::ou:::::::::::::::uu     LL:::::::LLLLLLLLL:::::Lo:::::ooooo:::::os:::::ssss::::::s      t::::::tttt:::::t\n";
        cout << "    YYYY:::::YYYY o:::::::::::::::o u:::::::::::::::u     L::::::::::::::::::::::Lo:::::::::::::::os::::::::::::::s       tt::::::::::::::t\n";
        cout << "    Y:::::::::::Y  oo:::::::::::oo   uu::::::::uu:::u     L::::::::::::::::::::::L oo:::::::::::oo  s:::::::::::ss          tt:::::::::::tt\n";
        cout << "    YYYYYYYYYYYYY    ooooooooooo       uuuuuuuu  uuuu     LLLLLLLLLLLLLLLLLLLLLLLL   ooooooooooo     sssssssssss              ttttttttttt\n";
    } else {
        cout << "DDDDDDDDDDDDD      RRRRRRRRRRRRRRRRR                AAA   WWWWWWWW                           WWWWWWWW\n";
        cout << "D::::::::::::DDD   R::::::::::::::::R              A:::A  W::::::W                           W::::::W\n";
        cout << "D:::::::::::::::DD R::::::RRRRRR:::::R            A:::::A W::::::W                           W::::::W\n";
        cout << "DDD:::::DDDDD:::::DRR:::::R     R:::::R          A:::::::AW::::::W                           W::::::W\n";
        cout << "D:::::D    D:::::D R::::R     R:::::R           A:::::::::AW:::::W           WWWWW           W:::::W \n";
        cout << "D:::::D     D:::::DR::::R     R:::::R          A:::::A:::::AW:::::W         W:::::W         W:::::W  \n";
        cout << "D:::::D     D:::::DR::::RRRRRR:::::R          A:::::A A:::::AW:::::W       W:::::::W       W:::::W   \n";
        cout << "D:::::D     D:::::DR:::::::::::::RR          A:::::A   A:::::AW:::::W     W:::::::::W     W:::::W    \n";
        cout << "D:::::D     D:::::DR::::RRRRRR:::::R        A:::::A     A:::::AW:::::W   W:::::W:::::W   W:::::W     \n";
        cout << "D:::::D     D:::::DR::::R     R:::::R      A:::::AAAAAAAAA:::::AW:::::W W:::::W W:::::W W:::::W      \n";
        cout << "D:::::D     D:::::DR::::R     R:::::R     A:::::::::::::::::::::AW:::::W:::::W   W:::::W:::::W       \n";
        cout << "D:::::D    D:::::D R::::R     R:::::R    A:::::AAAAAAAAAAAAA:::::AW:::::::::W     W:::::::::W        \n";
        cout << "DDD:::::DDDDD:::::DRR:::::R     R:::::R A:::::A            A:::::AW:::::::W        W:::::::W         \n";
        cout << "D:::::::::::::::DDR::::::R     R:::::R  A:::::A              A:::::AW:::::W         W:::::W          \n";
        cout << "D::::::::::::DDD  R::::::R     R:::::R A:::::A                A:::::AW:::W           W:::W           \n";
        cout << "DDDDDDDDDDDDD     RRRRRRRR     RRRRRRRAAAAAAA                  AAAAAAAWWW             WWW            \n";
    }
}
