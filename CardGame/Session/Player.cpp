//
//  Player.cpp
//  CardGame
//
//  Created by Nicholas Lau on 3/14/14.
//  Copyright (c) 2014 Nicholas Lau. All rights reserved.
//

#include "Player.h"

static int id_count = 1;

Player::Player() {
    money = 0;
    hand = NULL;
    name = NULL;
    player_id = id_count++;
}

Player::Player(char * a) {
    money = 0;
    hand = NULL;
    name = a;
    player_id = id_count++;
}

Player::~Player() {
    player_id = id_count--;
}