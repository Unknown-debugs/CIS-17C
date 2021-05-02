/* 
 * File:   Dealer.h
 * Author: Junhwan Lee
 * Purpose: Create a dealer
 * Created on April 21, 2021, 11:13 PM
 */

#include "Dealer.h"

Dealer::Dealer(){
    face = "ʅ（´◔౪◔）ʃ";
}

// Print Dealer
void Dealer::prntDealer(){
    std::cout<<std::endl;
    std::cout<<face<<std::endl;
    std::cout<<"Dealer"<<std::endl;
}

// Only dealer reveal first card
void Dealer::RevealFirstCard(){
    std::cout<<std::endl;
    hand[0].prntCard();
}