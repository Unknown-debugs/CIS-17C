/* 
 * File:   main.cpp
 * Author: Junhwan Lee
 * Purpose: create a deck of cards
 * Created on April 14, 2021, 12:31 PM
 */

#include "Game.h"

using namespace std;

// Actual game contents and player information
void game_start(Game &game);

int main() {

    // Initialize game
    Game game;

    // Display header
    game.header();

    cin.ignore();
    cout << "Are you read to play the game? [Press Enter]\n";
    cin.get();

    // User selection
    int choice;
    bool repeat;

    // Begin the game
    cout << "Let's Begin the Game of BlackJack!\n";
    game_start(game);

    do {
        //Clear buffer
        cin.ignore();
        cout << "\nPress Enter to continue\n";
        cin.get();

        game.menu();
        cin>>choice;
        // Validate choice selection
        while (choice < 1 || choice > 6) {
            cout << "\nInvalid selection! Enter 1 - 5\n" << "Your choice: ";
            cin>>choice;
        }
        cout << "\n";

        switch (choice) {
            case 1:
                // Game
                game_start(game);
                repeat = true;
                break;
            case 2:
                // Show list of players
                game.showList();
                repeat = true;
                break;
            case 3:
                // Display player's cash
                game.getCash();
                repeat = true;
                break;
            case 4:
                // Show results from each round
                game.listScores();
                repeat = true;
                break;
            case 5:
                // Register a new player
                game.registerPlayer();
                repeat = true;
                break;
            case 6:
                // Exit the game
                repeat = false;
                break;
        }
    } while (repeat);

    cout << "Thank you for playing!\n";

    // End of program
    return 0;
}

// Actual game contents and player information

void game_start(Game & g) {

    g.retPlayer();
    g.beginGame();
    g.begin_betting();
    // Clear buffer
    cin.ignore();
    cout << "Finished betting? Let's continue! [Press Enter]\n";
    cin.get();
    cout << endl;
    g.begin_dealing();
    g.endRound();

}