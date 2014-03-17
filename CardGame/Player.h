//
//  Player.h
//  CardGame
//
//  Created by Nicholas Lau on 3/14/14.
//  Copyright (c) 2014 Nicholas Lau. All rights reserved.
//

#ifndef __CardGame__Player__
#define __CardGame__Player__

#include <iostream>
#include "Hand.h"
typedef double  money_t;
typedef Hand * hand_t;

class Player {
public:
    Player();
    Player(char * name);
    
    void setMoney(money_t a);
    money_t getMoney();
    void setHand(hand_t a);
    hand_t getHand();
    void setName(char * name);
    char * getName();
    
    
private:
    money_t money;
    hand_t hand;
    char * name;
    int player_id;
};

#endif /* defined(__CardGame__Player__) */
