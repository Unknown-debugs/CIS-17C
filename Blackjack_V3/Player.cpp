
#include "Player.h"

Player::Player(){
    name = "Nobody;)";
    cash = 1000;
    bet = 0;
    wins = 0;
    loses = 0;
}

string Player::getName(){
    return name;
}

int Player::getCash(){
    return cash;
}

int Player::getBet(){
    return bet;
}

int Player::getLoses(){
    return loses;
}

int Player::getWins(){
    return wins;
}


void Player::setName(string player_name){
    name = player_name;
}

void Player::setCash(int gain){
    cash += gain;
}

void Player::setBet(int betting){
    bet += betting;
}

void Player::WinOrLose(bool determinant){
    if(determinant)
        wins++;
    else
        loses++;
}

