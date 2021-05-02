/* 
 * File:   Player.h
 * Author: Junhwan Lee
 * Purpose: Player object
 * Created on April 21, 2021, 8:36 PM
 */

#include "Player.h"

// Constructor
Player::Player(){
    name = "unknown";
    cash = 0;
    bet = 0;
    wins = 0;
    loses = 0;
}

// Return name
string Player::getName(){
    return name;
}

// Return remaining cash
int Player::getCash(){
    return cash;
}

// Return bet
int Player::getBet(){
    return bet;
}

// Return loses
int Player::getLoses(){
    return loses;
}

// Return wins
int Player::getWins(){
    return wins;
}

// Set name
void Player::setName(string player_name){
    name = player_name;
}

// Set cash
void Player::setCash(int gain){
    cash += gain;
}

// Set bet
void Player::setBet(int betting){
    bet += betting;
}

// Set win or lose
void Player::WinOrLose(bool determinant){
    if(determinant)
        wins++;
    else
        loses++;
}

// Clear player
void Player::reset(){
    cash = 0;
    bet = 0;
    wins = 0;
    loses = 0;
}
