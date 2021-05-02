/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dealer.h
 * Author: junhw
 *
 * Created on April 21, 2021, 11:13 PM
 */

#ifndef DEALER_H
#define DEALER_H
#include "Hand.h"

class Dealer: public Hand{
public:
    void prntDealer();
    void RevealFirstCard();    
};

#endif /* DEALER_H */

